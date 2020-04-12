#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <QObject>
#include <QCameraInfo>
#include <QCamera>
#include <QQmlApplicationEngine>
class CameraManager : public QObject
{

    Q_OBJECT
public:
    explicit CameraManager(QObject *parent = nullptr);
    ~CameraManager();
    bool OpenCamera();
    bool StopCamera();
    QString CaptureImage();
    QString CaptureVideo();
private:
    bool CheckAvaiableCamera();

    QCamera *myCamera;
     QQmlApplicationEngine cameraengine;

signals:

};

#endif // CAMERAMANAGER_H
