#include "phonedetectclass.h"

PhoneDetectClass::PhoneDetectClass(QObject *parent) : QObject(parent)
{
    FUNCTION_LOG();
    InitialPhoneDetector(SHAPE_PREDIRTOR_PHONE_LANDMARK,SHAPE_PHONE_DETECTOR_PATH);

}

void PhoneDetectClass::InitialPhoneDetector(string PredirtorPath, string shapeDetectorPath)
{
    FUNCTION_LOG();

    this->shapeLandMarkPredirtorPath=PredirtorPath;
    this->shapePhoneDetectorPath=shapeDetectorPath;
    // Load face detection and deserialize face landmarks model.
    deserialize(this->shapeLandMarkPredirtorPath) >> landMarkOfPhone;
    deserialize(this->shapePhoneDetectorPath) >> phoneDetector;
}

void PhoneDetectClass::DetectPhone(Mat frame)
{
    FUNCTION_LOG();
    std::vector<cv::Point> pointsOfHandResize;

    try{
        cv::Mat im_small, im_display;
        cv::Mat frame1,frame2;
        //resize frame to increase performance
        cv::resize(frame, im_small, cv::Size(), 1.0/PHONE_DOWNSAMPLE_RATIO, 1.0/PHONE_DOWNSAMPLE_RATIO);
        cv_image<bgr_pixel> cimg(im_small);
        // Resize image for face detection
        full_object_detection shape;

        // Detect faces
        std::vector<dlib::rectangle> hand;
        if ( countNumberOfFrame % SKIP_FRAMES == 0 )
        {
            // hand = DetectHandsBox(handDetector,frame);
            hand = phoneDetector(cimg);

            qDebug()<< "Number of object detected: " << hand.size() << endl;
            // Find the pose of each face.
            if (hand.size() > 0) {

                shape = landMarkOfPhone(cimg, hand[0]); //work only with 1 face

                mPhoneDetectStatus=PHONE_DETECTING_STATUS;

                // restore size and location of point as fist frame for draw on camera output

                for(unsigned long i=0;i < shape.num_parts();i++){
                    shape.part(i).x()=shape.part(i).x()*PHONE_DOWNSAMPLE_RATIO;
                    shape.part(i).y()=shape.part(i).y()*PHONE_DOWNSAMPLE_RATIO;
                }

                frame1=DrawandPhoneLineOnFrame(shape,frame);

                frame2=DrawPhoneDetectStatus(frame1,mPhoneDetectStatus);

                emit SendPhoneFrameDrawed(frame2);
                qDebug()<< "Emit detect frame for view " << endl;
                if(mPhoneDetectStatus==PHONE_DETECTING_STATUS)
                {
                    qDebug()<< "Emit frame for save file " << endl;
                    emit GetFrameForSaveToFile(frame);
                }
                char c;
                c = (char)waitKey(70);
            }
            else
            {
                qDebug()<< "Emit frame for save file  training data" << endl;
                emit GetFrameForSaveToFile(frame);

            }
        }
        else
        {
            mPhoneDetectStatus=NOT_PHONE_DETECT_STATUS;
            frame2=DrawPhoneDetectStatus(frame,mPhoneDetectStatus);
            emit SendPhoneFrameDrawed(frame2);

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


Mat PhoneDetectClass::DrawandPhoneLineOnFrame(full_object_detection shape, Mat frame)
{
    FUNCTION_LOG();
    if(shape.num_parts()<=1)
        return frame;
    // full_object_detection subShape;
    cv::Mat frame1=frame.clone();

    cv::Scalar scalar(0,255,0);
    // draw phone body
    cv::line(frame1, cv::Point(shape.part(0).x(),shape.part(0).y()), cv::Point(shape.part(1).x(),shape.part(1).y()),scalar, 2, 8, 0);

    cv::line(frame1, cv::Point(shape.part(2).x(),shape.part(2).y()), cv::Point(shape.part(3).x(),shape.part(3).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(3).x(),shape.part(3).y()), cv::Point(shape.part(4).x(),shape.part(4).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(5).x(),shape.part(5).y()), cv::Point(shape.part(6).x(),shape.part(6).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(6).x(),shape.part(6).y()), cv::Point(shape.part(7).x(),shape.part(7).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(8).x(),shape.part(8).y()), cv::Point(shape.part(9).x(),shape.part(9).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(9).x(),shape.part(9).y()), cv::Point(shape.part(10).x(),shape.part(10).y()),scalar, 2, 8, 0);

    return frame1;

}

Mat PhoneDetectClass::DrawPhoneDetectStatus(Mat frame, string phonedetectStatus)
{
    FUNCTION_LOG();

    cv::Mat frame1=frame.clone();
    cv::putText(frame1, phonedetectStatus, cv::Point(20,200), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, cv::Scalar(0,255,0),1, cv::LINE_AA);
    return  frame1;
}

std::vector<dlib::rectangle> PhoneDetectClass::ResizeBoxes(std::vector<dlib::rectangle> rects, int scaleFactor)
{
    FUNCTION_LOG();

    for(int k=0; k<(int)rects.size();k++)
    {
        rects[k] = dlib::rectangle(rects[k].left()/scaleFactor,rects[k].top()/scaleFactor,rects[k].right()/scaleFactor,rects[k].bottom()/scaleFactor);
    }
    return rects;

}
