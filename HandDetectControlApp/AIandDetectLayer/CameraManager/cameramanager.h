#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H
#include <QObject>
#include <QCameraInfo>
#include <QCamera>
#include <QQmlApplicationEngine>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QScopedPointer>
#include <QAction>
#include<QMessageBox>
#include<QDir>
#include"StringDefines.h"
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
    bool CheckAvaiableCamera();
    void setCamera(const QCameraInfo &cameraInfo);
    void startCamera();
    void record();
    void pause();
    void stop();
    void setMuted(bool muted);
    void displayCaptureError(int id, QCameraImageCapture::Error error, const QString &errorString);
    void configureImageSettings();
    void displayRecorderError();
    void displayCameraError();
    void updateCameraDevice(QAction *action);
    void setExposureCompensation(int index);
    void updateRecordTime();
    void imageSaved(int id, const QString &fileName);
public slots:
    void takeImage();
private:
     QCamera *myCamera;
     QQmlApplicationEngine cameraengine;

     QScopedPointer<QCamera> m_camera;
     QScopedPointer<QCameraImageCapture> m_imageCapture;
     QScopedPointer<QMediaRecorder> m_mediaRecorder;

     QImageEncoderSettings m_imageSettings;
     bool m_isCapturingImage = false;

signals:
    void getImagePath(QString imagePath);

};

#endif // CAMERAMANAGER_H
