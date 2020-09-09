#ifndef APPENGINER_H
#define APPENGINER_H

#include <QObject>
#include"FacesDetectClass.h"
#include"handDetectClass.h"
#include"cameramanager.h"
#include"GlobalFile.h"
#include"TrainShapePredictor.h"
#include"DetectionWithDNN.h"
#include"DetectionWithHOG.h"
#include "Imageproccessing.h"
#include"Filemanager.h"
class AppEnginer : public QObject
{
    Q_OBJECT
public:

    explicit AppEnginer(QObject *parent = nullptr, CameraManager *mCameraManager=nullptr);

signals:
private:
    CameraManager mCameraManager;
    FacesDetectClass mFaceDetectClass;
    HandDetectClass mHandDetectClass;
    Train_Shape_Predictor mTrain_Shape_Predictor;
    DetectionWithDNN mDetectionWithDNN;
    DetectionWithHOG mDetectionWithHOG;
    ImageProccessing mImageProccessing;
    FileManager mFileManager;

};

#endif // APPENGINER_H
