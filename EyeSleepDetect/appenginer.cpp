#include "appenginer.h"

AppEnginer::AppEnginer(QObject *parent,CameraManager *mCameraManager) : QObject(parent)
{
    FUNCTION_LOG();

    connect(mCameraManager, SIGNAL(SendFramegetFromCamera(cv::Mat)),&mFaceDetectClass,SLOT(DetectFace(cv::Mat)));
    connect(&mFaceDetectClass, SIGNAL(SendFrameDrawed(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));
    connect(&mFaceDetectClass, SIGNAL(GetFrameForSaveToFile(cv::Mat)),mCameraManager,SLOT(SaveImageToFile(cv::Mat)));
    connect(parent, SIGNAL(qmlStopCameraSignal()),mCameraManager,SLOT(StopWebCam()));
    connect(parent, SIGNAL(qmlStartCameraSignal()),mCameraManager,SLOT(StartWebCam()));
    connect(parent, SIGNAL(qmlSwitchImage(bool)),mCameraManager,SLOT(SetImagePathForView(bool)));



    // mTrain_Shape_Predictor.GeneratedtrainerFile();
}
