#include "DetectionWithHOG.h"

DetectionWithHOG::DetectionWithHOG(QObject *parent) : QObject(parent)
{

}

void DetectionWithHOG::InitialDetecWithHOG()
{
    FUNCTION_LOG();

    mPredirtorFilePath=PREDIRTOR_WITH_DNN;

    mDetector = get_frontal_face_detector();

}

void DetectionWithHOG::DetectWithHOG(Mat frame)
{
    try
    {
        cv::Mat im_small;
        cv::resize(frame, im_small, cv::Size(), 1.0/FACE_DOWNSAMPLE_RATIO, 1.0/FACE_DOWNSAMPLE_RATIO);
        cv_image<bgr_pixel> img(im_small);
        array2d<unsigned char>imageGray;
        dlib::assign_image(imageGray, img);


        pyramid_up(imageGray);

        // Now tell the face detector to give us a list of bounding boxes
        // around all the faces it can find in the image.
        std::vector<dlib::rectangle> dets = mDetector(imageGray);

        cout << "Number of faces detected: " << dets.size() << endl;
        // Now we show the image on the screen and the face detections as
        // red overlay boxes.
        cv::Rect rect;
        if(dets.size()<=0)
            qDebug()<<"Can't detect any face";
        for (auto&& d : dets)
        {
            rect=Rect(d.left(),d.top(),d.width()*FACE_DOWNSAMPLE_RATIO,d.height()*FACE_DOWNSAMPLE_RATIO);
            cv::rectangle(frame,rect,Scalar(255,0,0));
        }
        qDebug()<<"Send Frame to camera manager";
        emit SendFrameDetectHOG(frame);

        cout << "Hit enter to process the next image..." << endl;
    }
    catch(std::exception& e)
    {
        cout << e.what() << endl;
    }
}
