#include "appenginer.h"
AppEnginer::AppEnginer(QObject *parent,CameraManager *mCameraManager) : QObject(parent)
{
    FUNCTION_LOG();

    /*Connect for face detect class*/
//    connect(mCameraManager, SIGNAL(SendFrameGetFromCameraForDetect(cv::Mat)),&mFaceDetectClass,SLOT(DetectFace(cv::Mat)));
//    connect(&mFaceDetectClass, SIGNAL(SendFrameDrawed(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));
//    connect(&mFaceDetectClass, SIGNAL(GetFrameForSaveToFile(cv::Mat)),mCameraManager,SLOT(SaveImageToFile(cv::Mat)));


    /*connect for phone detect class*/
//    connect(mCameraManager, SIGNAL(SendFrameGetFromCameraForDetect(cv::Mat)),&mPhoneDetectClass,SLOT(DetectPhone(cv::Mat)));
//    connect(&mPhoneDetectClass, SIGNAL(SendPhoneFrameDrawed(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));
//    connect(&mPhoneDetectClass, SIGNAL(GetFrameForSaveToFile(cv::Mat)),mCameraManager,SLOT(SaveImageToFile(cv::Mat)));

    /*connect Road marker detect class*/
//    connect(mCameraManager, SIGNAL(SendFrameGetFromCameraForDetect(cv::Mat)),&mRoadMarkerDetect,SLOT(DetectRoadMarker(cv::Mat)));
//    connect(&mRoadMarkerDetect, SIGNAL(SendRoadMarkerFrameDrawed(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));
//    connect(&mRoadMarkerDetect, SIGNAL(GetFrameForSaveToFile(cv::Mat)),mCameraManager,SLOT(SaveImageToFile(cv::Mat)));



    connect(mCameraManager, SIGNAL(SendFrameGetFromCameraForDetect(cv::Mat)),&mDnn_mmod_find_verhicle,SLOT(DetectVerhicle(cv::Mat)));
    connect(&mDnn_mmod_find_verhicle, SIGNAL(SendVerhicleFrameDrawed(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));
    connect(&mDnn_mmod_find_verhicle, SIGNAL(GetFrameForSaveToFile(cv::Mat)),mCameraManager,SLOT(SaveImageToFile(cv::Mat)));


    /*connect for hand detect class*/
//    connect(mCameraManager, SIGNAL(SendFrameGetFromCameraForDetect(cv::Mat)),&mHandDetectClass,SLOT(DetectHand(cv::Mat)));
//    connect(&mHandDetectClass, SIGNAL(SendHandFrameDrawed(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));
//    connect(&mHandDetectClass, SIGNAL(GetFrameForSaveToFile(cv::Mat)),mCameraManager,SLOT(SaveImageToFile(cv::Mat)));


//    /*connect connect for save imageData to training*/
//    connect(mCameraManager, SIGNAL(SendFrameGetFromCameraForDetect(cv::Mat)),&mCaptureDataImage,SLOT(GetPhoneFrame(cv::Mat)));
//    connect(&mCaptureDataImage, SIGNAL(SendPhoneFrameDrawed(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));
//    connect(&mCaptureDataImage, SIGNAL(GetFrameForSaveToFile(cv::Mat)),mCameraManager,SLOT(SaveImageToFile(cv::Mat)));


    connect(parent, SIGNAL(qmlStopCameraSignal()),mCameraManager,SLOT(StopWebCam()));
    connect(parent, SIGNAL(qmlStartCameraSignal()),mCameraManager,SLOT(StartWebCam()));
    connect(parent, SIGNAL(qmlSwitchImage(bool)),mCameraManager,SLOT(SetImagePathForView(bool)));



}
