#include "appenginer.h"

AppEnginer::AppEnginer(QObject *parent,CameraManager *mCameraManager) : QObject(parent)
{
    qDebug()<< "Function name : "<<__FUNCTION__  <<endl;

    connect(mCameraManager, SIGNAL(SendFramegetFromCamera(cv::Mat)),&mFaceDetectClass,SLOT(DetectFace(cv::Mat)));
    connect(&mFaceDetectClass, SIGNAL(SendFrameDrawed(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));
    //connect(mCameraManager, SIGNAL(SendFramegetFromCamera(cv::Mat)),&mFaceDetectClass,SLOT(DetectEarAndNose(cv::Mat)));
    // connect(mCameraManager, SIGNAL(SendFramegetFromCamera(cv::Mat)),&mFaceDetectClass,SLOT(DetectYawnMouth(cv::Mat)));
    // connect(&mCameraManager, SIGNAL(SendFramegetFromCamera(cv::Mat,image_window*)),&mHandDetectClass,SLOT(DetectHand(cv::Mat,image_window*)));

    // mCameraManager.StartWebCam();

    // mTrain_Shape_Predictor.GeneratedtrainerFile();
}
