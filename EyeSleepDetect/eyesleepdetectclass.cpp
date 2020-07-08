#define FACE_DOWNSAMPLE_RATIO 2
#define SKIP_FRAMES 10
#include "eyesleepdetectclass.h"
#include<QDebug>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include "opencv2/opencv.hpp"
#include"opencv2/videoio.hpp"
EyeSleepDetectClass::EyeSleepDetectClass(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(SendFramegetFromCamera(cv::Mat)),this,SLOT(DetectEyeSleep(cv::Mat)));
    InitialFaceDetector(SHAPE_PREDIRTOR_68_FACE_LANDMARK);
    StartWebCam();
}

// compute eye aspect ratio (ear)
double EyeSleepDetectClass::computeAveragPositionForEye(std::vector<cv::Point> vec)
{

    double a = cv::norm(cv::Mat(vec[1]), cv::Mat(vec[5])); //=|P2-P6|         P2  |  P3
    double b = cv::norm(cv::Mat(vec[2]), cv::Mat(vec[4])); //=|p3-P5|      P1 ----|---- P4
    double c = cv::norm(cv::Mat(vec[0]), cv::Mat(vec[3])); //=|p1-p4|         P6  |  P5
    qDebug() << "compute_EAR:"<<"a="<<a<<"\t b="<<b<<"\t c="<<c<<"\n";

    //compute EAR
    double ear = (a + b) / (2.0 * c);
    return ear;
}

bool EyeSleepDetectClass::StartWebCam()
{
    try {
        cv::VideoCapture cap(0);
        m_videoCapture = new cv::VideoCapture(0);
        m_videoCapture->open(0);
        m_videoCapture->set(CAP_PROP_FRAME_WIDTH, CAM_WIDTH);//use small resolution for fast processing
        m_videoCapture->set(CAP_PROP_FRAME_HEIGHT, CAM_HEIGHT);
        if (!m_videoCapture->isOpened()) {
            qDebug() << "Unable to connect to camera";
            return false;
        }
        while (!win.is_closed()) {
            // Grab a frame
            cv::Mat temp;
            if (!m_videoCapture->read(temp)) {
                qDebug()<< "videoCapture error " <<endl;
                break;
            }
            else {
               emit SendFramegetFromCamera( temp);
            }
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

void EyeSleepDetectClass::InitialFaceDetector(std::string shape_Predirtor)
{
    this->shape_Predirtor=shape_Predirtor;
    // Load face detection and deserialize face landmarks model.
    deserialize(this->shape_Predirtor) >> landMarkOfFace;
    detector = get_frontal_face_detector();
}

std::vector<image_window::overlay_line> EyeSleepDetectClass::GetSubObjectFromFullFace(full_object_detection shape,int startPoint, int endPoint)
{
   // full_object_detection subShape;
    std::vector<image_window::overlay_line> lines;
    const rgb_pixel color = rgb_pixel(0,255,0);
    for(int count=startPoint; count < endPoint;count++)
    {
       //"push back to lines";
        lines.push_back(image_window::overlay_line(shape.part(count+1), shape.part(count), color));
    }

    return lines;
}

void EyeSleepDetectClass::DetectEyeSleep(cv::Mat frame)
{
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
            win.clear_overlay();
            win.set_image(cimg);

            // Find the pose of each face.
            if (faces.size() > 0) {

                shape = landMarkOfFace(cimg, faces[0]); //work only with 1 face

                for (int b = 36; b < 42; ++b) {
                    locationPointsOfEye.x = shape.part(b).x()*FACE_DOWNSAMPLE_RATIO;
                    locationPointsOfEye.y = shape.part(b).y()*FACE_DOWNSAMPLE_RATIO;
                    pointsOfLeftEye.push_back(locationPointsOfEye);
                }
                for (int b = 42; b < 48; ++b) {
                    locationPointsOfEye.x = shape.part(b).x()*FACE_DOWNSAMPLE_RATIO;
                    locationPointsOfEye.y = shape.part(b).y()*FACE_DOWNSAMPLE_RATIO;
                    pointsOfRightEye.push_back(locationPointsOfEye);
                }
                //Compute Eye aspect ration for eyes
                double right_ear = computeAveragPositionForEye(pointsOfRightEye);
                double left_ear = computeAveragPositionForEye(pointsOfLeftEye);
                qDebug()<< "result compute_EAR : "<<"right_ear="<< right_ear<<"\t left_ear="<<left_ear << endl;
                //if the avarage eye aspect ratio of lef and right eye less than 0.2, the status is sleeping.
                if ((right_ear + left_ear) / 2 < 0.3)//0.2)
                {
                    qDebug()<< "Sleeping = " <<(right_ear + left_ear)/2<< endl;
                    win.add_overlay(dlib::image_window::overlay_rect(faces[0], rgb_pixel(255, 255, 255), "Sleeping"));
                }
                else
                {
                    qDebug()<< "Not sleeping= "<<(right_ear + left_ear)/2 << endl;
                    win.add_overlay(dlib::image_window::overlay_rect(faces[0], rgb_pixel(255, 255, 255), "Not sleeping"));
                }

                pointsOfRightEye.clear();
                pointsOfLeftEye.clear();

                // set lines for points of Left eye and right eye
                std::vector<image_window::overlay_line> lines =GetSubObjectFromFullFace(shape,36,47);

                win.add_overlay(lines);
               // win.add_overlay(render_face_detections(shape));

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

void EyeSleepDetectClass::DetectLip(Mat frame)
{

}
