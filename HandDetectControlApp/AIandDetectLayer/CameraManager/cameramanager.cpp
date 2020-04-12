#include "cameramanager.h"

CameraManager::CameraManager(QObject *parent) : QObject(parent)
{
    cameraengine.load(QUrl("qrc:/Qml/CameraManeger.qml"));
    if (cameraengine.rootObjects().isEmpty())
        return;
}

CameraManager::~CameraManager()
{
    StopCamera();
    delete myCamera;
}

bool CameraManager::OpenCamera()
{
   bool avaiableCamera= CheckAvaiableCamera();
   if (avaiableCamera==true)
       myCamera->load();

   return avaiableCamera;
}

bool CameraManager::StopCamera()
{
    if(myCamera->availability())
    {

    }

}

QString CameraManager::CaptureImage()
{

}

QString CameraManager::CaptureVideo()
{

}

bool CameraManager::CheckAvaiableCamera()
{
    const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if (cameras.isEmpty()){
         qDebug() << "Camera not avaiable";
         return false;
    }
    QString fontFaceCamera;
    QString backFaceCamera;

    // get infor of list camera
    for (const QCameraInfo &cameraInfo : cameras) {
        if(!cameraInfo.isNull()){
            qDebug() << "device name: "<<cameraInfo.deviceName();
            if (cameraInfo.position() == QCamera::FrontFace)
            {
                fontFaceCamera=cameraInfo.deviceName();
                qDebug() << "The camera is on the front face of the hardware system.";
            }
            else if (cameraInfo.position() == QCamera::BackFace)
            {
                backFaceCamera=cameraInfo.deviceName();
                qDebug() << "The camera is on the back face of the hardware system.";
            }
            else if (cameraInfo.position() ==QCamera::UnspecifiedPosition)
            {
                 qDebug() << "The camera is on Unspecified, need action from User ";
            }

            // check if camera is font face camera, open it
            for (const QCameraInfo &cameraInfo : cameras) {
                if (cameraInfo.deviceName() == fontFaceCamera)
                {
                    myCamera = new QCamera(cameraInfo);
                    qDebug() << "open Font face camera";
                }
            }

        }
    }
}
