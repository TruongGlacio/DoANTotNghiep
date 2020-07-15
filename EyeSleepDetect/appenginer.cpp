#include "appenginer.h"

AppEnginer::AppEnginer(QObject *parent,CameraManager *mCameraManager) : QObject(parent)
{
    qDebug()<< "Function name : "<<__FUNCTION__  <<endl;

    connect(mCameraManager, SIGNAL(SendFramegetFromCamera(cv::Mat)),&mFaceDetectClass,SLOT(DetectFace(cv::Mat)));
    connect(&mFaceDetectClass, SIGNAL(SendFrameDrawed(cv::Mat)),mCameraManager,SLOT(updateFrame(cv::Mat)));

    // mTrain_Shape_Predictor.GeneratedtrainerFile();
}
