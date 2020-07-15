#ifndef HANDDETECTCLASS_H
#define HANDDETECTCLASS_H

#include <QObject>
#include <dlib/opencv.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>

#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<GlobalFile.h>

using namespace dlib;
using namespace std;
using namespace cv;
using namespace cv::dnn;
class HandDetectClass : public QObject
{
    Q_OBJECT
public:
    explicit HandDetectClass(QObject *parent = nullptr);
public slots:
    void DetectHand(cv::Mat frame, image_window *mWin);
private:
    const int POSE_PAIRS[20][2] =
    {
        {0,1}, {1,2}, {2,3}, {3,4},         // thumb
        {0,5}, {5,6}, {6,7}, {7,8},         // index
        {0,9}, {9,10}, {10,11}, {11,12},    // middle
        {0,13}, {13,14}, {14,15}, {15,16},  // ring
        {0,17}, {17,18}, {18,19}, {19,20}   // small
    };

    string protoFile = PROTO_FILE;
    string weightsFile = WEIGHTS_FILE;
    int countNumberOfFrame=0;
    int nPoints = 22;
    double t=0;

signals:

};

#endif // HANDDETECTCLASS_H
