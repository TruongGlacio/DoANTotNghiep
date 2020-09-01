#include "appenginer.h"

AppEnginer::AppEnginer(QObject *parent,CameraManager *mCameraManager) : QObject(parent)
{
    FUNCTION_LOG();

    /*Connect for face detect class*/
//    connect(mCameraManager, SIGNAL(SendFrameGetFromCameraForDetect(cv::Mat)),&mFaceDetectClass,SLOT(DetectFace(cv::Mat)));
//    connect(&mFaceDetectClass, SIGNAL(SendFrameDrawed(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));
//    connect(&mFaceDetectClass, SIGNAL(GetFrameForSaveToFile(cv::Mat)),mCameraManager,SLOT(SaveImageToFile(cv::Mat)));

    /*connect for hand detect class*/
//    connect(mCameraManager, SIGNAL(SendFrameGetFromCameraForDetect(cv::Mat)),&mHandDetectClass,SLOT(DetectHand(cv::Mat)));
//    connect(&mHandDetectClass, SIGNAL(SendHandFrameDrawed(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));
//    connect(&mHandDetectClass, SIGNAL(GetFrameForSaveToFile(cv::Mat)),mCameraManager,SLOT(SaveImageToFile(cv::Mat)));

//    connect(mCameraManager, SIGNAL(SendFrameGetFromCameraForDetect(cv::Mat)),&mDetectionWithDNN,SLOT(DetectWithDNN(cv::Mat)));
//    connect(&mDetectionWithDNN, SIGNAL(SendFrameDetectDNN(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));

    connect(mCameraManager, SIGNAL(SendFrameGetFromCameraForDetect(cv::Mat)),&mDetectionWithHOG,SLOT(DetectWithHOG(cv::Mat)));
    connect(&mDetectionWithHOG, SIGNAL(SendFrameDetectHOG(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));

    connect(parent, SIGNAL(qmlStopCameraSignal()),mCameraManager,SLOT(StopWebCam()));
    connect(parent, SIGNAL(qmlStartCameraSignal()),mCameraManager,SLOT(StartWebCam()));
    connect(parent, SIGNAL(qmlSwitchImage(bool)),mCameraManager,SLOT(SetImagePathForView(bool)));
    QString datFile= HAND_PREDICTO_DAT_FILE_NAME;
//    mTrain_Shape_Predictor.GeneratedtrainerFile(datFile);





}
