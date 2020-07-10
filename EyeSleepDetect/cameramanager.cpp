#include "cameramanager.h"
#include<QDebug>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include "opencv2/opencv.hpp"
#include"opencv2/videoio.hpp"
CameraManager::CameraManager(QObject *parent) : QObject(parent)
{

}

bool CameraManager::StartWebCam()
{
    try {
        cv::VideoCapture cap(0);
        m_videoCapture = new cv::VideoCapture(0);
        m_videoCapture->open(0);
        m_videoCapture->set(CAP_PROP_FRAME_WIDTH, CAM_WIDTH);//use small resolution for fast processing
        m_videoCapture->set(CAP_PROP_FRAME_HEIGHT, CAM_HEIGHT);
        if (!m_videoCapture->isOpened()) {
            qDebug() << "Unable to connect to camera";
            return false;
        }
        qDebug()<< "camera started " <<endl;
        while (!mWin.is_closed()) {
            // Grab a frame
            cv::Mat temp;
            if (!m_videoCapture->read(temp)) {
                qDebug()<< "videoCapture error " <<endl;
                break;
            }
            else {
               emit SendFramegetFromCamera(temp,&mWin);
            }
        }

    }
    catch (exception& e) {
        cout << e.what() << endl;
        qDebug()<< "catch error: "<<e.what()<<endl;
    }
    return true;
}
