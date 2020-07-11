#include "FacesDetectClass.h"
#include<QDebug>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include "opencv2/opencv.hpp"
#include"opencv2/videoio.hpp"
FacesDetectClass::FacesDetectClass(QObject *parent ) : QObject(parent)
{
  //  connect(this, SIGNAL(SendFramegetFromCamera(cv::Mat)),this,SLOT(DetectEyeSleep(cv::Mat)));

    InitialFaceDetector(SHAPE_PREDIRTOR_68_FACE_LANDMARK);
    //  StartWebCam();
}

// compute eye aspect ratio (ear)
double FacesDetectClass::ComputerAspectRatioForEye(std::vector<cv::Point> vec)
{

 //                   left eye                     right eye
 //=|P2-P6|          P38  |   P39                    P44  |  P45
 //=|p3-P5|      P37 -----|----- P40     nose    P43 -----|----- P46
 //=|p1-p4|          P42  |   P41                    P48  |  P47


    double averageAspectRatio;

    double ratioPoint37To39 = cv::norm(cv::Mat(vec[36]), cv::Mat(vec[39])); //=|P37-P39|
    double ratioPoint38To42 = cv::norm(cv::Mat(vec[37]), cv::Mat(vec[41])); //=|P38-P42|
    double ratioPoint39To41 = cv::norm(cv::Mat(vec[38]), cv::Mat(vec[40])); //=|P39-P41|
    //compute Left EAR
    double leftEar= (ratioPoint38To42 + ratioPoint39To41) / (2.0 * ratioPoint37To39);
    qDebug() << "compute Left EAR:"<<"a="<<ratioPoint37To39<<"\t b="<<ratioPoint38To42<<"\t c="<<ratioPoint39To41<<"\n";


    //compute right EAR
    double ratioPoint43To46 = cv::norm(cv::Mat(vec[42]), cv::Mat(vec[45])); //=|P43-P46|
    double ratioPoint44To48 = cv::norm(cv::Mat(vec[43]), cv::Mat(vec[47])); //=|P44-P48|
    double ratioPoint45To48 = cv::norm(cv::Mat(vec[44]), cv::Mat(vec[46])); //=|P45-P47|
    double rigthEar = (ratioPoint44To48 + ratioPoint45To48) / (2.0 * ratioPoint43To46);
    qDebug() << "compute_EAR:"<<"a="<<ratioPoint43To46<<"\t b="<<ratioPoint44To48<<"\t c="<<ratioPoint45To48<<"\n";

    averageAspectRatio=(leftEar+rigthEar)/2;

    return averageAspectRatio;
}

double FacesDetectClass::ComputerAspectRatioForEarAndNose(std::vector<Point> vec)
{
    //Mapping point of ear and nose
                //1          28          17

                //2          29          16

                // 3         30         15

                //  4        31        14

    double averageAspectRatio;

    double ratioPoint1To17 = cv::norm(cv::Mat(vec[0]), cv::Mat(vec[27]))/cv::norm(cv::Mat(vec[27]), cv::Mat(vec[16])); //=|(P1-P28)/P28-P17|
    double ratioPoint2To16 = cv::norm(cv::Mat(vec[1]), cv::Mat(vec[28]))/cv::norm(cv::Mat(vec[28]), cv::Mat(vec[15])); //=|(P2-P29)/P29-P16|
    double ratioPoint3To15 = cv::norm(cv::Mat(vec[2]), cv::Mat(vec[29]))/cv::norm(cv::Mat(vec[29]), cv::Mat(vec[14])); //=|(P3-P30)/P30-P15|
    double ratioPoint4To14 = cv::norm(cv::Mat(vec[3]), cv::Mat(vec[30]))/cv::norm(cv::Mat(vec[30]), cv::Mat(vec[13])); //=|(P4-P31)/P31-P14|

    averageAspectRatio= (ratioPoint1To17+ ratioPoint2To16+ ratioPoint3To15+ ratioPoint4To14)/4;

    return  averageAspectRatio;

}

double FacesDetectClass::ComputerAspectRatioForMouth(std::vector<Point> vec)
{

            //              P51             P53
            //          P50                       P54
            //              P62     P63     P64
            //     P49 P61                         P65 P55
            //              P68     P67     P66
            //          P60                       P56
            //              P59             P57

    // compute InSideMount
    double ratioPoint61To65 = cv::norm(cv::Mat(vec[60]), cv::Mat(vec[64])); //=|P61-P65|
    double ratioPoint62To68 =0;//= cv::norm(cv::Mat(vec[61]), cv::Mat(vec[67])); //=|P62-P68|
    double ratioPoint63To67 = cv::norm(cv::Mat(vec[62]), cv::Mat(vec[66])); //=|P62-P66|
    double ratioPoint64To66 = cv::norm(cv::Mat(vec[63]), cv::Mat(vec[65])); //=|P64-P66|
    qDebug() << "InSideMount:"<<"ratioPoint61To65="<<ratioPoint61To65<<"\t ratioPoint62To68="<<ratioPoint62To68<<"\t ratioPoint63To67="<<ratioPoint63To67<<"\t ratioPoint64To66=" << ratioPoint64To66<<"\n";

    double inSideMount= (ratioPoint63To67+ ratioPoint64To66 ) / (2.0 * ratioPoint61To65);

    // compute OutSideMount
    double ratioPoin49To55  = cv::norm(cv::Mat(vec[48]), cv::Mat(vec[54]));  //=|P49-P55|
    double ratioPoint50To60 = cv::norm(cv::Mat(vec[49]), cv::Mat(vec[59])); //=|P50-P60|
    double ratioPoint51To59 = cv::norm(cv::Mat(vec[50]), cv::Mat(vec[58])); //=|P51-P59|
    double ratioPoint53To57 = cv::norm(cv::Mat(vec[52]), cv::Mat(vec[56])); //=|P52-P57|
    double ratioPoint54To56 = cv::norm(cv::Mat(vec[53]), cv::Mat(vec[55])); //=|P54-P56|
    qDebug() << "OutSideMount:"<<"ratioPoin49To55="<<ratioPoin49To55<<"\t ratioPoint50To60="<<ratioPoint50To60<<"\t ratioPoint51To59="<<ratioPoint51To59<<"\t ratioPoint53To57=" << "\t ratioPoint54To56="  <<ratioPoint54To56 <<"\n";

    double outSideMount= (ratioPoint50To60 + ratioPoint51To59+ ratioPoint53To57 +ratioPoint54To56) / (4.0 * ratioPoin49To55);
    double averageAspectRatio;

    averageAspectRatio= (inSideMount+ outSideMount)/2;

    return  averageAspectRatio;



}


void FacesDetectClass::InitialFaceDetector(std::string shape_Predirtor)
{
    this->shape_Predirtor=shape_Predirtor;
    // Load face detection and deserialize face landmarks model.
    deserialize(this->shape_Predirtor) >> landMarkOfFace;
    detector = get_frontal_face_detector();
}

std::vector<image_window::overlay_line> FacesDetectClass::DrawEyeLineOnFrame(full_object_detection shape)
{
   // full_object_detection subShape;
    std::vector<image_window::overlay_line> lines;
    const rgb_pixel color = rgb_pixel(0,255,0);
    // Left eye
    for (unsigned long i = 37; i <= 41; ++i)
        lines.push_back(image_window::overlay_line(shape.part(i), shape.part(i-1), color));
    lines.push_back(image_window::overlay_line(shape.part(36), shape.part(41), color));

    // Right eye
    for (unsigned long i = 43; i <= 47; ++i)
        lines.push_back(image_window::overlay_line(shape.part(i), shape.part(i-1), color));
    lines.push_back(image_window::overlay_line(shape.part(42), shape.part(47), color));

    return lines;
}

std::vector<image_window::overlay_line> FacesDetectClass::DrawEarAndNoseLineOnFrame(full_object_detection shape)
{
    // full_object_detection subShape;
     std::vector<image_window::overlay_line> lines;
     const rgb_pixel color = rgb_pixel(0,255,0);
     // Left eye
     // Around Chin. Ear to Ear
     for (unsigned long i = 1; i <= 4; ++i)
         lines.push_back(image_window::overlay_line(shape.part(i), shape.part(i-1), color));
     for (unsigned long i = 13; i <= 16; ++i)
         lines.push_back(image_window::overlay_line(shape.part(i), shape.part(i-1), color));
     // Line on top of nose
     for (unsigned long i = 28; i <= 30; ++i)
         lines.push_back(image_window::overlay_line(shape.part(i), shape.part(i-1), color));

     return lines;
}

std::vector<image_window::overlay_line> FacesDetectClass::DrawMouthLineOnFrame(full_object_detection shape)
{
    std::vector<image_window::overlay_line> lines;
    const rgb_pixel color = rgb_pixel(0,255,0);
    // Lips outer part
    for (unsigned long i = 49; i <= 59; ++i)
        lines.push_back(image_window::overlay_line(shape.part(i), shape.part(i-1), color));
    lines.push_back(image_window::overlay_line(shape.part(48), shape.part(59), color));

    // Lips inside part
    for (unsigned long i = 61; i <= 67; ++i)
        lines.push_back(image_window::overlay_line(shape.part(i), shape.part(i-1), color));
    lines.push_back(image_window::overlay_line(shape.part(60), shape.part(67), color));

    return lines;

}


void FacesDetectClass::DetectEyeSleep(cv::Mat frame,  image_window *mWin)
{
    std::vector<cv::Point> pointsOfFaceResize;
    try{
        cv::Mat im_small, im_display;
        //resize frame to increase performance
        cv::resize(frame, im_small, cv::Size(), 1.0/FACE_DOWNSAMPLE_RATIO, 1.0/FACE_DOWNSAMPLE_RATIO);
        cv_image<bgr_pixel> cimg(im_small);
        cv_image<bgr_pixel> cimgForView(frame);
        // Resize image for face detection
        full_object_detection shape;

        // Detect faces
        std::vector<dlib::rectangle> faces;
        if ( countNumberOfFrame % SKIP_FRAMES == 0 )
        {
            faces = detector(cimg); // detect the faces from cimg frame
            qDebug()<< "Number of faces detected: " << faces.size() << endl;
            mWin->clear_overlay();
            mWin->set_image(cimg);

            // Find the pose of each face.
            if (faces.size() > 0) {

                shape = landMarkOfFace(cimg, faces[0]); //work only with 1 face

                //Get localtion points of left Eye and right eye
                for (int b = 0; b < 67; ++b) {
                                    locationPointsOfEye.x = shape.part(b).x()*FACE_DOWNSAMPLE_RATIO;
                                    locationPointsOfEye.y = shape.part(b).y()*FACE_DOWNSAMPLE_RATIO;
                                    pointsOfFaceResize.push_back(locationPointsOfEye);
                }
                //Compute Eye aspect ration for eyes
                double averageAspectRatio = ComputerAspectRatioForEye(pointsOfFaceResize);

                qDebug()<< "result compute_EAR : "<<"averageAspectRatio="<< averageAspectRatio<< endl;

                //if the avarage eye aspect ratio of lef and right eye less than 0.2, the status is sleeping.
                if (averageAspectRatio < TWO_EYELID_ASPECT_RATIO_STANDARD)//0.2)
                {
                    qDebug()<< "Sleeping = " <<averageAspectRatio<< endl;
                    mWin->add_overlay(dlib::image_window::overlay_rect(faces[0], rgb_pixel(255, 255, 255), "Sleeping"));
                }
                else
                {
                    qDebug()<< "Not sleeping= "<<averageAspectRatio << endl;
                    mWin->add_overlay(dlib::image_window::overlay_rect(faces[0], rgb_pixel(255, 255, 255), "Not sleeping"));
                }

                pointsOfFaceResize.clear();

                // set lines for points of Left eye and right eye from point 36 to point 47 in maping 68 point face landmark

                std::vector<image_window::overlay_line> lines =DrawEarAndNoseLineOnFrame(shape);

                mWin->add_overlay(lines);
                mWin->add_overlay(render_face_detections(shape));

               // wait for press key in 30ms
                c = (char)waitKey(30);
                if (c == 27) // if Press ESC key, break
                    return;
            }
        }
        countNumberOfFrame ++;
        if(countNumberOfFrame ==100)
        {
            countNumberOfFrame =0;
        }
    }
    catch (serialization_error& e) {
        cout << "Check the path to dlib's default face landmarking model file to run this example." << endl;
        cout << "You can get it from the following URL: " << endl;
        cout << "   http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
        cout << endl
             << e.what() << endl;
    }
}

void FacesDetectClass::DetectEarAndNose(cv::Mat frame, image_window *mWin)
{
    std::vector<cv::Point> pointsOfFaceResize;

    try{
        cv::Mat im_small, im_display;
        //resize frame to increase performance
        cv::resize(frame, im_small, cv::Size(), 1.0/FACE_DOWNSAMPLE_RATIO, 1.0/FACE_DOWNSAMPLE_RATIO);
        cv_image<bgr_pixel> cimg(im_small);
        cv_image<bgr_pixel> cimgForView(frame);
        // Resize image for face detection
        full_object_detection shape;

        // Detect faces
        std::vector<dlib::rectangle> faces;
        if ( countNumberOfFrame % SKIP_FRAMES == 0 )
        {
            faces = detector(cimg); // detect the faces from cimg frame
            qDebug()<< "Number of faces detected: " << faces.size() << endl;
            mWin->clear_overlay();
            mWin->set_image(cimg);

            // Find the pose of each face.
            if (faces.size() > 0) {

                shape = landMarkOfFace(cimg, faces[0]); //work only with 1 face

                for (int b = 0; b < 67; ++b) {
                                    locationPointsOfEye.x = shape.part(b).x()*FACE_DOWNSAMPLE_RATIO;
                                    locationPointsOfEye.y = shape.part(b).y()*FACE_DOWNSAMPLE_RATIO;
                                    pointsOfFaceResize.push_back(locationPointsOfEye);
                }

               //Compute ear and nose aspect ration for ear
                double aspectRation = ComputerAspectRatioForEarAndNose(pointsOfFaceResize);
                qDebug()<< "result compute_EAR : "<<"aspectRation="<< aspectRation<< endl;

                //Check
                if (aspectRation < EAR_ASPECT_RATIO_STANDARD_LOW || aspectRation>EAR_ASPECT_RATIO_STANDARD_HIGH )//0.2)
                {
                    qDebug()<< "Sleeping = " <<aspectRation<< endl;
                    mWin->add_overlay(dlib::image_window::overlay_rect(faces[0], rgb_pixel(255, 255, 255), "Heading Phone"));
                }
                else {
                    qDebug()<< "No Sleep = " <<aspectRation<< endl;
                    mWin->add_overlay(dlib::image_window::overlay_rect(faces[0], rgb_pixel(255, 255, 255), "Not heading phone"));

                }
                pointsOfFaceResize.clear();

                // set lines for points of Left eye and right eye from point 36 to point 47 in maping 68 point face landmark

                std::vector<image_window::overlay_line> lines =DrawEarAndNoseLineOnFrame(shape);

                mWin->add_overlay(lines);
               // mWin->add_overlay(render_face_detections(shape));

               // wait for press key in 30ms
                c = (char)waitKey(30);
                if (c == 27) // if Press ESC key, break
                    return;
            }
        }
        countNumberOfFrame ++;
        if(countNumberOfFrame ==100)
        {
            countNumberOfFrame =0;
        }
    }
    catch (serialization_error& e) {
        cout << "Check the path to dlib's default face landmarking model file to run this example." << endl;
        cout << "You can get it from the following URL: " << endl;
        cout << "   http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
        cout << endl
             << e.what() << endl;
    }
}

void FacesDetectClass::DetectYawnMouth(Mat frame, image_window *mWin)
{
    std::vector<cv::Point> pointsOfFaceResize;

    try{
        cv::Mat im_small, im_display;
        //resize frame to increase performance
        cv::resize(frame, im_small, cv::Size(), 1.0/FACE_DOWNSAMPLE_RATIO, 1.0/FACE_DOWNSAMPLE_RATIO);
        cv_image<bgr_pixel> cimg(im_small);
        cv_image<bgr_pixel> cimgForView(frame);
        // Resize image for face detection
        full_object_detection shape;

        // Detect faces
        std::vector<dlib::rectangle> faces;
        if ( countNumberOfFrame % SKIP_FRAMES == 0 )
        {
            faces = detector(cimg); // detect the faces from cimg frame
            qDebug()<< "Number of faces detected: " << faces.size() << endl;
            mWin->clear_overlay();
            mWin->set_image(cimg);

            // Find the pose of each face.
            if (faces.size() > 0) {

                shape = landMarkOfFace(cimg, faces[0]); //work only with 1 face

                for (int b = 0; b < 67; ++b) {
                                    locationPointsOfEye.x = shape.part(b).x()*FACE_DOWNSAMPLE_RATIO;
                                    locationPointsOfEye.y = shape.part(b).y()*FACE_DOWNSAMPLE_RATIO;
                                    pointsOfFaceResize.push_back(locationPointsOfEye);
                }

               //Compute ear and nose aspect ration for ear
                double aspectRation = ComputerAspectRatioForMouth(pointsOfFaceResize);
                qDebug()<< "result compute_EAR : "<<"aspectRation="<< aspectRation<< endl;

                //Check
                if (aspectRation > MOUTH_ASPECT_RATIO_STANDARD)
                {
                    qDebug()<< "Yawning mouth = " <<aspectRation<< endl;
                    mWin->add_overlay(dlib::image_window::overlay_rect(faces[0], rgb_pixel(255, 255, 255), "Yawning mouth"));
                }
                else {
                    qDebug()<< "NotYawning mouth = " <<aspectRation<< endl;
                    mWin->add_overlay(dlib::image_window::overlay_rect(faces[0], rgb_pixel(255, 255, 255), "NotYawning mouth"));

                }
                pointsOfFaceResize.clear();

                // set lines for points of Left eye and right eye from point 36 to point 47 in maping 68 point face landmark

                std::vector<image_window::overlay_line> lines =DrawMouthLineOnFrame(shape);

                mWin->add_overlay(lines);
               // mWin->add_overlay(render_face_detections(shape));

               // wait for press key in 30ms
                c = (char)waitKey(30);
                if (c == 27) // if Press ESC key, break
                    return;
            }
        }
        countNumberOfFrame ++;
        if(countNumberOfFrame ==100)
        {
            countNumberOfFrame =0;
        }
    }
    catch (serialization_error& e) {
        cout << "Check the path to dlib's default face landmarking model file to run this example." << endl;
        cout << "You can get it from the following URL: " << endl;
        cout << "   http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
        cout << endl
             << e.what() << endl;
    }

}
