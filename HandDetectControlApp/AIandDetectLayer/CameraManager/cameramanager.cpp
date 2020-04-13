#define IMAGE_HIGH_QUALITY 3 //HighQuality
#define IMAGE_HEIGHT_SIZE 720
#define IMAGE_WIDTH_SIZE 1280
#define IMAGE_FORMAT "png"
#include "cameramanager.h"

CameraManager::CameraManager(QObject *parent) : QObject(parent)
{
    cameraengine.load(QUrl("qrc:/Qml/CameraManeger.qml"));
    if (cameraengine.rootObjects().isEmpty())
        return;
     bool checkCameraresult=CheckAvaiableCamera();
     if(checkCameraresult!=true)

     {
         QMessageBox msgBox;
         msgBox.setText("Camera is not avaiable");
         msgBox.exec();
         return;
     }
     setCamera(QCameraInfo::defaultCamera());
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

      // myCamera->load();

   return avaiableCamera;
}

bool CameraManager::StopCamera()
{
     m_camera->stop();
}

QString CameraManager::CaptureImage()
{

}

QString CameraManager::CaptureVideo()
{

}

bool CameraManager::CheckAvaiableCamera()
{
    bool returnValue=true;
    const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if (cameras.isEmpty()){
         qDebug() << "Camera not avaiable";
         returnValue= false;
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
                    //myCamera = new QCamera(cameraInfo);
                    qDebug() << "open Font face camera";
                }
                else {
                     qDebug() << "Can't open Font face camera";
                     returnValue= false;
                }
            }

        }
        else {
             returnValue= false;
             qDebug() << "Not find information of cameras";;
        }
    }
}

void CameraManager::setCamera(const QCameraInfo &cameraInfo)
{
    m_camera.reset(new QCamera(cameraInfo));
   // ui->takeImageButton->setEnabled(true);
    connect(m_camera.data(), QOverload<QCamera::Error>::of(&QCamera::error), this, &CameraManager::displayCameraError);

    m_mediaRecorder.reset(new QMediaRecorder(m_camera.data()));
    m_imageCapture.reset(new QCameraImageCapture(m_camera.data()));

    connect(m_mediaRecorder.data(), &QMediaRecorder::durationChanged, this, &CameraManager::updateRecordTime);
    connect(m_mediaRecorder.data(), QOverload<QMediaRecorder::Error>::of(&QMediaRecorder::error),
            this, &CameraManager::displayRecorderError);

    connect(m_imageCapture.data(), &QCameraImageCapture::imageSaved, this, &CameraManager::imageSaved);
    connect(m_imageCapture.data(), QOverload<int, QCameraImageCapture::Error, const QString &>::of(&QCameraImageCapture::error),this, &CameraManager::displayCaptureError);
    m_camera->start();
    configureImageSettings();
}

void CameraManager::startCamera()
{
m_camera->start();
}

void CameraManager::record()
{
    m_mediaRecorder->record();
    updateRecordTime();
}

void CameraManager::pause()
{
     m_mediaRecorder->pause();
}

void CameraManager::stop()
{
 m_mediaRecorder->stop();
}

void CameraManager::setMuted(bool muted)
{
 m_mediaRecorder->setMuted(muted);
}

void CameraManager::takeImage()
{
    m_isCapturingImage = true;
    m_imageCapture->capture();
}

void CameraManager::displayCaptureError(int id, QCameraImageCapture::Error error, const QString &errorString)
{
    Q_UNUSED(id);
    Q_UNUSED(error);
    m_isCapturingImage = false;
}

void CameraManager::configureImageSettings()
{
    m_camera->setCaptureMode(QCamera::CaptureStillImage);
    const QStringList supportedImageCodecs = m_imageCapture.data()->supportedImageCodecs();
    for (const QString &codecName : supportedImageCodecs) {
        QString description = m_imageCapture.data()->imageCodecDescription(codecName);
        qDebug()<<"camera codec support"<<codecName<<"\n";
    }


    const QList<QSize> supportedResolutions = m_imageCapture.data()->supportedResolutions();
    for (const QSize &resolution : supportedResolutions) {
        qDebug()<<"camera Resolutions support "<<"width:"<<resolution.width()<<"\n height="<<resolution.height()<<"\n";
    }
    m_camera->setCaptureMode(QCamera::CaptureStillImage);
    QImageEncoderSettings settings;// = m_imageCapture.data()->encodingSettings();
    QSize imageSize=QSize(IMAGE_WIDTH_SIZE,IMAGE_HEIGHT_SIZE);
    settings.setCodec(IMAGE_FORMAT);
    settings.setQuality(QMultimedia::EncodingQuality(IMAGE_HIGH_QUALITY));
    settings.setResolution(imageSize);
    m_imageSettings=settings;
    m_imageCapture->setEncodingSettings(m_imageSettings);
}

void CameraManager::displayRecorderError()
{

}

void CameraManager::displayCameraError()
{

}

void CameraManager::updateRecordTime()
{

}

void CameraManager::imageSaved(int id, const QString &fileName)
{
    Q_UNUSED(id);
    QString imagePath=QDir::toNativeSeparators(fileName);
    emit getImagePath(imagePath);
    qDebug()<<"image path: "<<imagePath;

   // ui->statusbar->showMessage(tr("Captured \"%1\"").arg(QDir::toNativeSeparators(fileName)));
}
