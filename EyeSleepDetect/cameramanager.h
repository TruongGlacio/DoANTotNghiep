#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <QObject>
#include <QPointer>
#include <QVideoFrame>
#include <QVideoSurfaceFormat>

#include <opencv2/core/mat.hpp>
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>

#include <opencv2/core/mat.hpp>
#include <opencv2/videoio.hpp>
#include<GlobalFile.h>
#include<QDebug>
#include<QDateTime>
#include <QTimer>
#include <QDir>

using namespace dlib;
using namespace std;
using namespace cv;
class QAbstractVideoSurface;
class CameraManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface* videoSurface READ videoSurface WRITE setVideoSurface NOTIFY surfaceChanged)
    QAbstractVideoSurface* videoSurface() const;
    Q_PROPERTY(QString folderPath MEMBER mFolderPathSaveImage NOTIFY sendUpdateFolderPathToQml)


public:
    explicit CameraManager(QObject *parent = nullptr);
signals:
    void SendFrameGetFromCameraForDetect(cv::Mat frame);
    void SendNormalFrameGetFromCamera(cv::Mat frame);
    void SendTrackingFrameToVideoOutput(cv::Mat currentFrame);
    void SendFrameForImageView(cv::Mat currentFrame);
    void surfaceChanged(QAbstractVideoSurface* surface);
    void sendUpdateFolderPathToQml(QString folderPath);
private Q_SLOTS:
    void onVideoFrameReady(cv::Mat currentFrame);
    void updateFrame(cv::Mat frame);

public Q_SLOTS:
    void setVideoSurface(QAbstractVideoSurface* surface);
    void getFrame();
    void SaveImageToFile(cv::Mat frame);
    bool StartWebCam();
    void StopWebCam();
    void SetImagePathForView(bool distance);
    void UpdateCurrentIndex(int currentIndex);
    void UpdateImageFolderPathToView(QString folderPath);

private:
    void setFormat(int width, int height, QVideoFrame::PixelFormat frameFormat);

public:
    cv::VideoCapture *m_videoCapture;
    // image_window mWin;
    QPointer<QAbstractVideoSurface> m_surface;
    //QScopedPointer<Backend> m_backend;
    QVideoSurfaceFormat m_format;
    QImage m_image;
    QTimer *timer;
    int countFrame=0;
    QString mImagepathForView;
    QString mFolderPathSaveImage;
    int mImageFileIndex =0;
    bool mCameraStatus=false;


};

#endif // CAMERAMANAGER_H
