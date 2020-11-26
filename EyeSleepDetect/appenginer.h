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

};

#endif // APPENGINER_H
