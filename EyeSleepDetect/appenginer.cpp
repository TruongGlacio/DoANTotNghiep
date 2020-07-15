#include "appenginer.h"

AppEnginer::AppEnginer(QObject *parent,CameraManager *mCameraManager) : QObject(parent)
{
    qDebug()<< "Function name : "<<__FUNCTION__  <<endl;

    connect(mCameraManager, SIGNAL(SendFramegetFromCamera(cv::Mat,image_window*)),&mFaceDetectClass,SLOT(DetectEyeSleep(cv::Mat,image_window*)));
    connect(mCameraManager, SIGNAL(SendFramegetFromCamera(cv::Mat,image_window*)),&mFaceDetectClass,SLOT(DetectEarAndNose(cv::Mat,image_window*)));
    connect(mCameraManager, SIGNAL(SendFramegetFromCamera(cv::Mat,image_window*)),&mFaceDetectClass,SLOT(DetectYawnMouth(cv::Mat,image_window*)));
   // connect(&mCameraManager, SIGNAL(SendFramegetFromCamera(cv::Mat,image_window*)),&mHandDetectClass,SLOT(DetectHand(cv::Mat,image_window*)));

   // mCameraManager.StartWebCam();

   // mTrain_Shape_Predictor.GeneratedtrainerFile();
}
