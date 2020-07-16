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
    FUNCTION_LOG();

    return m_surface;
}

CameraManager::CameraManager(QObject *parent) : QObject(parent)
{
    FUNCTION_LOG();

    connect(this, SIGNAL(SendTrackingFrameToVideoOutput(cv::Mat)), this,SLOT(onVideoFrameReady(cv::Mat)));
    connect(&timer,SIGNAL(timeout()), this, SLOT(getFrame()));
    timer.setInterval(100);
}

bool CameraManager::StartWebCam()
{
    FUNCTION_LOG();

    try {
        //cv::VideoCapture cap(0);
        int deviceID = 0;             // 0 = open default camera
        int apiID = cv::CAP_ANY;      // 0 = autodetect default API
        m_videoCapture = new cv::VideoCapture(0);

        // open selected camera using selected API
        m_videoCapture->open(deviceID);
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
    FUNCTION_LOG();

    cv::Mat frame;
    m_videoCapture->read(frame);

    if (!frame.empty())
    {
        updateFrame(frame);
        if(countFrame%3==0)
        {
        emit SendFramegetFromCamera(frame);
        }
        countFrame ++;
        if(countFrame==100)
            countFrame=0;
    }

    else {
        qDebug()<< "Frame is empty " <<endl;
    }
}

void CameraManager::onVideoFrameReady(Mat currentFrame)
{
    FUNCTION_LOG();

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
    FUNCTION_LOG();

    if (!frame.empty())
        Q_EMIT SendTrackingFrameToVideoOutput(frame);
}

void CameraManager::setVideoSurface(QAbstractVideoSurface *surface)
{
    FUNCTION_LOG();

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
    FUNCTION_LOG();

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
