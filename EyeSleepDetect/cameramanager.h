#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <QObject>
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include<GlobalFile.h>
#include<QDebug>
using namespace dlib;
using namespace std;
using namespace cv;

class CameraManager : public QObject
{
    Q_OBJECT
public:
    explicit CameraManager(QObject *parent = nullptr);
    bool StartWebCam();
signals:
    void SendFramegetFromCamera(cv::Mat frame,image_window *win);
public:
     cv::VideoCapture* m_videoCapture;
     image_window mWin;

};

#endif // CAMERAMANAGER_H
