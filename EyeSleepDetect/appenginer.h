#ifndef APPENGINER_H
#define APPENGINER_H

#include <QObject>
#include"FacesDetectClass.h"
#include"handDetectClass.h"
#include"cameramanager.h"
#include"GlobalFile.h"
#include"train_shape_predictor.h"
#include"phonedetectclass.h"
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

};

#endif // APPENGINER_H
