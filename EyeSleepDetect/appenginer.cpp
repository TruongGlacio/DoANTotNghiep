#include "appenginer.h"

AppEnginer::AppEnginer(QObject *parent) : QObject(parent)
{
    connect(&mCameraManager, SIGNAL(SendFramegetFromCamera(cv::Mat,image_window*)),&mFaceDetectClass,SLOT(DetectEyeSleep(cv::Mat,image_window*)));

    mCameraManager.StartWebCam();

}
