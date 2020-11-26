#include "roadmarkerdetect.h"

RoadMarkerDetect::RoadMarkerDetect(QObject *parent) : QObject(parent)
{
    FUNCTION_LOG();
    InitialRoadMarkerDetector(SHAPE_PREDIRTOR_ROADMARKER_LANDMARK,SHAPE_ROADMARKER_DETECTOR_PATH);
}

void RoadMarkerDetect::DetectRoadMarker(Mat frame)
{
    FUNCTION_LOG();
    std::vector<cv::Point> pointsOfHandResize;

    try{
        cv::Mat im_small, im_display;
        cv::Mat frame1,frame2;
        //resize frame to increase performance
        cv::resize(frame, im_small, cv::Size(), 1.0/ROADMARKER_DOWNSAMPLE_RATIO, 1.0/ROADMARKER_DOWNSAMPLE_RATIO);
        cv_image<bgr_pixel> cimg(im_small);
        // Resize image for face detection
        full_object_detection shape;

        // Detect faces
        std::vector<dlib::rectangle> hand;
        if ( countNumberOfFrame % SKIP_FRAMES == 0 )
        {
            // hand = DetectHandsBox(handDetector,frame);
            hand = roadmarkerDetector(cimg);

            qDebug()<< "Number of object detected: " << hand.size() << endl;
            // Find the pose of each face.
            if (hand.size() > 0) {
                mRoadMarkerDetectStatus=ROADMARKER_DETECTING_STATUS;
                std::vector<full_object_detection> shapeList;
                for(unsigned long i=0; i< hand.size();i++){
                    shape = landMarkOfRoadmarker(cimg, hand[i]); //work only with 1 face
                    // restore size and location of point as fist frame for draw on camera output

                    for(unsigned long i=0;i < shape.num_parts();i++){
                        shape.part(i).x()=shape.part(i).x()*ROADMARKER_DOWNSAMPLE_RATIO;
                        shape.part(i).y()=shape.part(i).y()*ROADMARKER_DOWNSAMPLE_RATIO;
                    }
                    frame=DrawandRoadMarkerLineOnFrame(shape,frame);
                    frame=DrawRoadMarkerDetectStatus(frame,mRoadMarkerDetectStatus);

                    //shapeList.push_back(shape);
                }


                emit SendRoadMarkerFrameDrawed(frame);
                qDebug()<< "Emit detect frame for view " << endl;
                if(mRoadMarkerDetectStatus==ROADMARKER_DETECTING_STATUS)
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
            mRoadMarkerDetectStatus=NOT_ROADMARKER_DETECT_STATUS;
            frame=DrawRoadMarkerDetectStatus(frame,mRoadMarkerDetectStatus);
            emit SendRoadMarkerFrameDrawed(frame);

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

void RoadMarkerDetect::InitialRoadMarkerDetector(string PredirtorPath, string shapeDetectorPath)
{
    FUNCTION_LOG();

    this->shapeLandMarkPredirtorPath=PredirtorPath;
    this->shapeRoadMarkerDetectorPath=shapeDetectorPath;
    // Load face detection and deserialize face landmarks model.
    deserialize(this->shapeLandMarkPredirtorPath) >> landMarkOfRoadmarker;
    deserialize(this->shapeRoadMarkerDetectorPath) >> roadmarkerDetector;
}

Mat RoadMarkerDetect::DrawandRoadMarkerLineOnFrame(full_object_detection shape, Mat frame)
{
    FUNCTION_LOG();
    if(shape.num_parts()<=1)
        return frame;
    // full_object_detection subShape;
    cv::Mat frame1=frame.clone();

    cv::Scalar scalar(0,255,0);
    // draw phone body
    cv::line(frame1, cv::Point(shape.part(0).x(),shape.part(0).y()), cv::Point(shape.part(1).x(),shape.part(1).y()),scalar, 2, 8, 0);

    cv::line(frame1, cv::Point(shape.part(1).x(),shape.part(1).y()), cv::Point(shape.part(2).x(),shape.part(2).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(2).x(),shape.part(2).y()), cv::Point(shape.part(3).x(),shape.part(3).y()),scalar, 2, 8, 0);
    cv::line(frame1, cv::Point(shape.part(3).x(),shape.part(3).y()), cv::Point(shape.part(0).x(),shape.part(0).y()),scalar, 2, 8, 0);

    return frame1;
}

Mat RoadMarkerDetect::DrawRoadMarkerDetectStatus(Mat frame, string roadMarkerdetectStatus)
{
    FUNCTION_LOG();

    cv::Mat frame1=frame.clone();
    cv::putText(frame1, roadMarkerdetectStatus, cv::Point(20,200), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, cv::Scalar(0,255,0),1, cv::LINE_AA);
    return  frame1;
}

std::vector<dlib::rectangle> RoadMarkerDetect::ResizeBoxes(std::vector<dlib::rectangle> rects, int scaleFactor)
{
    FUNCTION_LOG();

    for(int k=0; k<(int)rects.size();k++)
    {
        rects[k] = dlib::rectangle(rects[k].left()/scaleFactor,rects[k].top()/scaleFactor,rects[k].right()/scaleFactor,rects[k].bottom()/scaleFactor);
    }
    return rects;

}
