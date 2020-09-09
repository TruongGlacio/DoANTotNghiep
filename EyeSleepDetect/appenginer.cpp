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


//    connect(mCameraManager, SIGNAL(SendFrameGetFromCameraForDetect(cv::Mat)),&mDetectionWithHOG,SLOT(DetectWithHOG(cv::Mat)));
//    connect(&mDetectionWithHOG, SIGNAL(SendFrameDetectHOG(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));


    connect(mCameraManager, SIGNAL(SendFrameGetFromCameraForDetect(cv::Mat)),&mImageProccessing,SLOT(UpdateImageFrameForImagProccessing(cv::Mat)));
    connect(&mImageProccessing, SIGNAL(SendFrameOutput(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));
    connect(mCameraManager, SIGNAL(SendFrameForImageView(cv::Mat)),&mImageProccessing,SLOT(UpdateImageFrameForImagProccessing(cv::Mat)));
    connect(&mImageProccessing, SIGNAL(SendFrameForSaveToFile(cv::Mat)),mCameraManager,SLOT(SaveImageToFile(cv::Mat)));




    connect(parent, SIGNAL(qmlStopCameraSignal()),mCameraManager,SLOT(StopWebCam()));
    connect(parent, SIGNAL(qmlStartCameraSignal()),mCameraManager,SLOT(StartWebCam()));
    connect(parent, SIGNAL(qmlSwitchImage(bool)),mCameraManager,SLOT(SetImagePathForView(bool)));
    connect(parent, SIGNAL(qmlSendThresholdValue(int)),&mImageProccessing,SLOT(SetThresHoldValue(int)));
    connect(parent, SIGNAL(qmlSendThresholdType(int)),&mImageProccessing,SLOT(SetThreadholdType(int)));
    connect(parent, SIGNAL(qmlFileBroswer()),&mFileManager,SLOT(GetListImageFromFileBroswer()));


    connect(&mFileManager, SIGNAL(SendUpdateCurrentIndex(int)),mCameraManager,SLOT(UpdateCurrentIndex(int)));
    connect(&mFileManager, SIGNAL(SendUpdateFolderPath(QString)),mCameraManager,SLOT(UpdateImageFolderPathToView(QString)));

  //  connect(&mFileManager, SIGNAL(SendUpdateFolderPath(QString)),parent,SLOT(showFolderPath(QString)));


    //QString datFile= HAND_PREDICTO_DAT_FILE_NAME;
//    mTrain_Shape_Predictor.GeneratedtrainerFile(datFile);





}
