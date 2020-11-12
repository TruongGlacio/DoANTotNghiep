#include "handDetectClass.h"
#include<QDebug>



HandDetectClass::HandDetectClass(QObject *parent) : QObject(parent)
{
    FUNCTION_LOG();
    InitialFaceDetector(SHAPE_PREDIRTOR_HAND_LANDMARK,SHAPE_HAND_DETECTOR_PATH);


}
void HandDetectClass::InitialFaceDetector(std::string shape_Predirtor,std::string shapeHandDetectorPath)
{
    FUNCTION_LOG();

    this->shapeLandMarkPredirtorPath=shape_Predirtor;
    this->shapeHandDetectorPath=shapeHandDetectorPath;
    // Load face detection and deserialize face landmarks model.
    deserialize(this->shapeLandMarkPredirtorPath) >> landMarkOfHand;
    //detector = get_frontal_face_detector();

    deserialize(this->shapeHandDetectorPath) >> handDetector;

   // detector=DetectHandLandmarks()



}

Mat HandDetectClass::DrawEyeLineOnFrame(full_object_detection shape, Mat frame)
{
    // full_object_detection subShape;
    cv::Mat frame1=frame.clone();

    cv::Scalar scalar(0,255,0);
    // Hand eye

    cv::line(frame1, cv::Point(shape.part(1).x(),shape.part(1).y()), cv::Point(shape.part(3).x(),shape.part(3).y()),scalar, 2, 8, 0);

    cv::line(frame1, cv::Point(shape.part(3).x(),shape.part(3).y()), cv::Point(shape.part(5).x(),shape.part(5).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(5).x(),shape.part(5).y()), cv::Point(shape.part(7).x(),shape.part(7).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(7).x(),shape.part(7).y()), cv::Point(shape.part(8).x(),shape.part(8).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(8).x(),shape.part(8).y()), cv::Point(shape.part(6).x(),shape.part(6).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(6).x(),shape.part(6).y()), cv::Point(shape.part(1).x(),shape.part(1).y()),scalar, 2, 8, 0);

    //Draw finger
    cv::line(frame1, cv::Point(shape.part(1).x(),shape.part(1).y()), cv::Point(shape.part(0).x(),shape.part(0).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(2).x(),shape.part(2).y()), cv::Point(shape.part(3).x(),shape.part(3).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(4).x(),shape.part(4).y()), cv::Point(shape.part(5).x(),shape.part(5).y()),scalar, 2, 8, 0);

    return frame1;

}

Mat HandDetectClass::DrawHandDetectStatus(Mat frame, string handdetectStatus)
{
    FUNCTION_LOG();

    cv::Mat frame1=frame.clone();
    cv::putText(frame1, handdetectStatus, cv::Point(20,200), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, cv::Scalar(0,255,0),1, cv::LINE_AA);
    return  frame1;
}

std::vector<dlib::rectangle> HandDetectClass::resizeBoxes(std::vector<dlib::rectangle> rects, int scaleFactor)
{
    for(int k=0; k<(int)rects.size();k++)
        {
            rects[k] = dlib::rectangle(rects[k].left()/scaleFactor,rects[k].top()/scaleFactor,rects[k].right()/scaleFactor,rects[k].bottom()/scaleFactor);
        }
    return rects;
}

void HandDetectClass::DetectHand(cv::Mat frame)
{

    FUNCTION_LOG();
    std::vector<cv::Point> pointsOfHandResize;

    try{
        cv::Mat im_small, im_display;
        cv::Mat frame1,frame2;
        //resize frame to increase performance
        cv::resize(frame, im_small, cv::Size(), 1.0/HAND_DOWNSAMPLE_RATIO, 1.0/HAND_DOWNSAMPLE_RATIO);
        cv_image<bgr_pixel> cimg(im_small);
        // Resize image for face detection
        full_object_detection shape;

        // Detect faces
        std::vector<dlib::rectangle> hand;
        if ( countNumberOfFrame % SKIP_FRAMES == 0 )
        {
           // hand = DetectHandsBox(handDetector,frame);
            hand = handDetector(cimg);

            // hand = detector(cimg); // detect the faces from cimg frame

            qDebug()<< "Number of hand detected: " << hand.size() << endl;
            // Find the pose of each face.
            if (hand.size() > 0) {

                shape = landMarkOfHand(cimg, hand[0]); //work only with 1 face

                mHandDetectStatus=HAND_DETECTING_STATUS;

                for (int b = 0; b < 9; b++) {
                    locationPointsOfHand.x = shape.part(b).x()*HAND_DOWNSAMPLE_RATIO;
                    locationPointsOfHand.y = shape.part(b).y()*HAND_DOWNSAMPLE_RATIO;
                    pointsOfHandResize.push_back(locationPointsOfHand);
                }

                // restore size and location of point as fist frame for draw on camera output

                for(unsigned long i=0;i < shape.num_parts();i++){
                    shape.part(i).x()=shape.part(i).x()*HAND_DOWNSAMPLE_RATIO;
                    shape.part(i).y()=shape.part(i).y()*HAND_DOWNSAMPLE_RATIO;
                }

                frame1=DrawEyeLineOnFrame(shape,frame);

                frame2=DrawHandDetectStatus(frame1,mHandDetectStatus);

                emit SendHandFrameDrawed(frame2);
                qDebug()<< "Emit detect frame for view " << endl;
                if(mHandDetectStatus==HAND_DETECTING_STATUS)
                {
                    qDebug()<< "Emit frame for save file " << endl;
                    emit GetFrameForSaveToFile(frame1);
                }
                pointsOfHandResize.clear();
                char c;
                c = (char)waitKey(70);
            }
        }
        else
        {
            mHandDetectStatus=NOT_HAND_DETECT_STATUS;
            frame2=DrawHandDetectStatus(frame,mHandDetectStatus);
            emit SendHandFrameDrawed(frame2);

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
        //  cout << "   http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
        cout << endl
             << e.what() << endl;
    }
}
