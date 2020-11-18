#ifndef HANDDETECTCLASS_H
#define HANDDETECTCLASS_H

#include <QObject>
#include"GlobalLib.h"
#include <iostream>
#include<GlobalFile.h>

using namespace dlib;
using namespace std;
using namespace cv;
using namespace cv::dnn;
typedef scan_fhog_pyramid<pyramid_down<6> > image_scanner_type;

class HandDetectClass : public QObject
{
    Q_OBJECT
public:
    explicit HandDetectClass(QObject *parent = nullptr);

signals:
        void SendHandFrameDrawed(cv::Mat frame);
        void GetFrameForSaveToFile(cv::Mat frame);
public slots:
    void DetectHand(cv::Mat frame);
    void InitialHandDetector(std::string shapeLandMarkPredirtorPath,std::string shapeHandDetectorPath);
    cv::Mat DrawandHandLineOnFrame(full_object_detection shape,cv::Mat frame);
    cv::Mat DrawHandDetectStatus(cv::Mat frame, std::string handdetectStatus);
    std::vector<dlib::rectangle> resizeBoxes(std::vector<dlib::rectangle> rects, int scaleFactor);


private:

    int countNumberOfFrame=0;
    std::string shapeLandMarkPredirtorPath;
    std::string shapeHandDetectorPath;

    cv::Point locationPointsOfHand;
    frontal_face_detector detector;
    shape_predictor landMarkOfHand;

    object_detector<image_scanner_type> handDetector;
    std::string mHandDetectStatus;

};

#endif // HANDDETECTCLASS_H
