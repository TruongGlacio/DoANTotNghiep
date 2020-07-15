#include "cameramanager.h"
#include<QDebug>
#include <QAbstractVideoSurface>
#include <iostream>

#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include "opencv2/opencv.hpp"
#include"opencv2/videoio.hpp"
QAbstractVideoSurface *CameraManager::videoSurface() const
{
    qDebug()<< "Function name : "<<__FUNCTION__  <<endl;
    return m_surface;
}

CameraManager::CameraManager(QObject *parent) : QObject(parent)
{
    qDebug()<< "Function name : "<<__FUNCTION__  <<endl;
    connect(this, SIGNAL(SendTrackingFrameToVideoOutput(cv::Mat)), this,SLOT(onVideoFrameReady(cv::Mat)));
    connect(&timer,SIGNAL(timeout()), this, SLOT(getFrame()));
    timer.setInterval(30);
}

bool CameraManager::StartWebCam()
{
    qDebug()<< "Function name : "<<__FUNCTION__  <<endl;
    try {
        //cv::VideoCapture cap(0);
        int deviceID = 0;             // 0 = open default camera
        int apiID = cv::CAP_ANY;      // 0 = autodetect default API
        m_videoCapture = new cv::VideoCapture(0);

        // open selected camera using selected API
        m_videoCapture->open(deviceID, apiID);
        m_videoCapture->set(CAP_PROP_FRAME_WIDTH, CAM_WIDTH);//use small resolution for fast processing
        m_videoCapture->set(CAP_PROP_FRAME_HEIGHT, CAM_HEIGHT);
        if (!m_videoCapture->isOpened()) {
            qDebug() << "Unable to connect to camera";
            return false;
        }
        qDebug()<< "camera started " <<endl;
        timer.start();

    }
    catch (exception& e) {
        cout << e.what() << endl;
        qDebug()<< "catch error: "<<e.what()<<endl;
    }
    return true;
}

void CameraManager::getFrame()
{
    qDebug()<< "Function name : "<<__FUNCTION__  <<endl;
    cv::Mat frame;
    m_videoCapture->read(frame);

    if (!frame.empty())
    {
        updateFrame(frame);
        //  emit  SendFramegetFromCamera(frame,&mWin);
    }

    else {
        qDebug()<< "Frame is empty " <<endl;
    }
}

void CameraManager::onVideoFrameReady(Mat currentFrame)
{
    qDebug()<< "Function name : "<<__FUNCTION__  <<endl;
    if (!m_surface || currentFrame.empty())
        return;
    cv::Mat continuousFrame;
    if (!currentFrame.isContinuous())
        continuousFrame = currentFrame.clone();
    else
        continuousFrame = currentFrame;
    if (!m_isFormatSet) {
        setFormat(continuousFrame.cols,
                  continuousFrame.rows,
                  QVideoFrame::Format_RGB32);
        m_isFormatSet = true;
    }
    m_image = QImage(continuousFrame.data, continuousFrame.cols, continuousFrame.rows,continuousFrame.step, QImage::Format_RGB888);
    m_image = m_image.rgbSwapped();
    m_image.convertTo(QVideoFrame::imageFormatFromPixelFormat(QVideoFrame::Format_RGB32));
    m_surface->present(QVideoFrame(m_image));
}

void CameraManager::updateFrame(cv::Mat frame)
{
    qDebug()<< "Function name : "<<__FUNCTION__  <<endl;
    if (!frame.empty())
        Q_EMIT SendTrackingFrameToVideoOutput(frame);
}

void CameraManager::setVideoSurface(QAbstractVideoSurface *surface)
{
    qDebug()<< "Function name : "<<__FUNCTION__  <<endl;
    if (m_surface == surface)
        return;
    if(m_surface && m_surface != surface && m_surface->isActive())
        m_surface->stop();
    m_surface = surface;
    Q_EMIT surfaceChanged(m_surface);
    this->StartWebCam();
    if (m_surface && m_format.isValid()) {
        m_format = m_surface->nearestFormat(m_format);
        m_surface->start(m_format);
    }
}

void CameraManager::setFormat(int width, int height, QVideoFrame::PixelFormat frameFormat)
{
    qDebug()<< "Function name : "<<__FUNCTION__  <<endl;

    QSize size(width, height);
    QVideoSurfaceFormat format(size, frameFormat);
    m_format = format;
    if (m_surface) {
        if (m_surface->isActive())
            m_surface->stop();
        m_format = m_surface->nearestFormat(m_format);
        m_surface->start(m_format);
    }
}
