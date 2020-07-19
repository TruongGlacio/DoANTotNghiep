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
    timer=new QTimer();
    connect(this, SIGNAL(SendTrackingFrameToVideoOutput(cv::Mat)), this,SLOT(onVideoFrameReady(cv::Mat)));
    connect(this, SIGNAL(SendNormalFrameGetFromCamera(cv::Mat)), this,SLOT(updateFrame(cv::Mat)));
    connect(timer,SIGNAL(timeout()), this, SLOT(getFrame()));
    disconnect(this, SIGNAL(SendFrameForImageView(cv::Mat)), this,SLOT(onVideoFrameReady(cv::Mat)));
    timer->setInterval(100);
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
        m_videoCapture->open(deviceID,apiID);
        m_videoCapture->set(CAP_PROP_FRAME_WIDTH, CAM_WIDTH);//use small resolution for fast processing
        m_videoCapture->set(CAP_PROP_FRAME_HEIGHT, CAM_HEIGHT);
        if (!m_videoCapture->isOpened()) {
            qDebug() << "Unable to connect to camera";
            return false;
        }
        qDebug()<< "camera started " <<endl;

        connect(timer,SIGNAL(timeout()), this, SLOT(getFrame()));
        connect(this, SIGNAL(SendTrackingFrameToVideoOutput(cv::Mat)), this,SLOT(onVideoFrameReady(cv::Mat)));
        disconnect(this, SIGNAL(SendFrameForImageView(cv::Mat)), this,SLOT(onVideoFrameReady(cv::Mat)));

        timer->start();

    }
    catch (exception& e) {
        cout << e.what() << endl;
        qDebug()<< "catch error: "<<e.what()<<endl;
    }
    return true;
}

void CameraManager::StopWebCam()

{
    FUNCTION_LOG();
    m_videoCapture->release();
    disconnect(timer,SIGNAL(timeout()), this, SLOT(getFrame()));
    connect(this, SIGNAL(SendFrameForImageView(cv::Mat)), this,SLOT(onVideoFrameReady(cv::Mat)));
    disconnect(this, SIGNAL(SendTrackingFrameToVideoOutput(cv::Mat)), this,SLOT(onVideoFrameReady(cv::Mat)));

    timer->stop();

    if(timer->isActive())
    {

        qDebug() << "Can't stop timer";
    }
    else
    {
        qDebug() << "Timer stoped";
    }
    qDebug() << "m_videoCapture close";

    if(mFolderPathSaveImage.isEmpty()){
        QString rootFolderPath=QDir::currentPath();
        qDebug()<<"rootFolderPath is : "<<rootFolderPath;
        mFolderPathSaveImage=rootFolderPath+FOLDER_PATH_SAVE_IMAGE;
    }
    if(!QDir(mFolderPathSaveImage).exists())
    {
        qDebug()<<"Folder Path for Save Image not exit"<<endl;
        return;
    }
    QDir directoryImage(mFolderPathSaveImage);
    QStringList imagesList = directoryImage.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);
    mImageFileIndex=imagesList.size()-1;
}

void CameraManager::SetImagePathForView(bool distance)
{
    if(mFolderPathSaveImage.isEmpty()){
        QString rootFolderPath=QDir::currentPath();
        qDebug()<<"rootFolderPath is : "<<rootFolderPath;
        mFolderPathSaveImage=rootFolderPath+FOLDER_PATH_SAVE_IMAGE;
    }
    if(!QDir(mFolderPathSaveImage).exists())
    {
        qDebug()<<"Folder Path for Save Image not exit"<<endl;
        return;
    }
    QDir directoryImage(mFolderPathSaveImage);
    QStringList imagesList = directoryImage.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);

    if(distance) // button next image clicked
    {
        mImageFileIndex++;
    }
    else {
        mImageFileIndex--;
    }
    if(mImageFileIndex >= imagesList.size()) mImageFileIndex=imagesList.size()-1;

    if(mImageFileIndex<=0)  mImageFileIndex=0;
    if (imagesList.isEmpty())
    {
        qDebug()<<"Folder Image path is empty"<<endl;
        return;
    }
#if __linux__
    mImagepathForView=mFolderPathSaveImage + '\'+imagesList.at(mImageFileIndex);
#else
    mImagepathForView=mFolderPathSaveImage + '/'+imagesList.at(mImageFileIndex);
#endif
    qDebug()<<"image file path sahll show on "<<mImagepathForView<<endl;
    // mImagepathForView= mFolderPathSaveImage+
    Mat imageFrame;
    imageFrame = cv::imread(mImagepathForView.toStdString(), 1 );
    if(!imageFrame.data)
    {
        qDebug()<<"Can't load frame from image file"<<endl;
        return;
    }
    emit SendFrameForImageView(imageFrame);
}
void CameraManager::getFrame()
{
    FUNCTION_LOG();

    cv::Mat frame;
    if (!m_videoCapture->isOpened())
        return;
    m_videoCapture->read(frame);

    if (!frame.empty())
    {
        emit SendNormalFrameGetFromCamera(frame);
        if(countFrame%SKIP_FRAMES1==0)
        {
            emit SendFrameGetFromCameraForDetect(frame);
        }
        countFrame ++;
        if(countFrame==100)
            countFrame=0;
    }

    else {
        qDebug()<< "Frame is empty " <<endl;
    }
}

void CameraManager::SaveImageToFile(Mat frame)
{
    //Save detect image file to memory
    QDateTime current = QDateTime::currentDateTime();
    QString rootFolderPath=QDir::currentPath();
    qDebug()<<"rootFolderPath is : "<<rootFolderPath;

    QString folderPathsaveImage=rootFolderPath+FOLDER_PATH_SAVE_IMAGE;
    if(!QDir(folderPathsaveImage).exists())
    {
        qDebug()<<"Creat a new folder for save image if folder don't exit"<<folderPathsaveImage<<endl;
        QDir().mkpath(folderPathsaveImage);
    }
    if(frame.empty())
    {
        qDebug()<<"Frame is empty, return "<<endl;
        return;
    }
    mFolderPathSaveImage=folderPathsaveImage;
    QString imageFileName=current.toString()+".jpg";//FILE_PATH_SAVE_IMAGE+current.toString()+ ".jpg";
    std::string fileName=imageFileName.toStdString();
    while (1){
        std::size_t pos = fileName.find(TO_REPLACE_STRING);
        std::size_t pos1 = fileName.find(TO_REPLACE_STRING1);
        if (pos != std::string::npos){
            fileName.replace(pos, 1, REPLACE_WITH_STRING);
        }
        else{
            if (pos1 != std::string::npos){
                fileName.replace(pos1, 1, REPLACE_WITH_STRING);
            }
            else{
                break;
            }
        }

    }
#if __linux__
    std::string filePath=folderPathsaveImage.toStdString()+'\'+fileName;
#else
    std::string filePath=folderPathsaveImage.toStdString()+'/'+fileName;
#endif
    qDebug()<<"Save detected image frame to memory, file path: "<<filePath.c_str();
    imwrite(filePath, frame); // A JPG FILE IS BEING SAVED

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
    m_image=m_image.convertToFormat(QVideoFrame::imageFormatFromPixelFormat(QVideoFrame::Format_RGB32));
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
