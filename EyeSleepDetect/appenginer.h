#ifndef APPENGINER_H
#define APPENGINER_H

#include <QObject>
#include"FacesDetectClass.h"
#include"handDetectClass.h"
#include"cameramanager.h"
#include"GlobalFile.h"
#include"Traning/train_shape_predictor.h"
#include"phonedetectclass.h"
#include"capturedataimage.h"
#include"roadmarkerdetect.h"
#include"dnn_mmod_find_verhicle.h"
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
    PhoneDetectClass mPhoneDetectClass;
    CaptureDataImage mCaptureDataImage;
    RoadMarkerDetect mRoadMarkerDetect;
    dnn_mmod_find_verhicle mDnn_mmod_find_verhicle;

};

#endif // APPENGINER_H
