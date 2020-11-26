#ifndef PHONEDETECTCLASS_H
#define PHONEDETECTCLASS_H

#include <QObject>
#include"GlobalLib.h"
#include<GlobalFile.h>

using namespace dlib;
using namespace std;
using namespace cv;
using namespace cv::dnn;
typedef scan_fhog_pyramid<pyramid_down<6> > image_scanner_type;
class PhoneDetectClass : public QObject
{
    Q_OBJECT
public:
    explicit PhoneDetectClass(QObject *parent = nullptr);
signals:
        void SendPhoneFrameDrawed(cv::Mat frame);
        void GetFrameForSaveToFile(cv::Mat frame);
public slots:
    void DetectPhone(cv::Mat frame);
    void InitialPhoneDetector(std::string PredirtorPath,std::string shapeDetectorPath);
    cv::Mat DrawandPhoneLineOnFrame(full_object_detection shape,cv::Mat frame);
    cv::Mat DrawPhoneDetectStatus(cv::Mat frame, std::string phonedetectStatus);
    std::vector<dlib::rectangle> ResizeBoxes(std::vector<dlib::rectangle> rects, int scaleFactor);


private:

    int countNumberOfFrame=0;
    std::string shapeLandMarkPredirtorPath;
    std::string shapePhoneDetectorPath;

    cv::Point locationPointsOfPhone;
    frontal_face_detector detector;
    shape_predictor landMarkOfPhone;

    object_detector<image_scanner_type> phoneDetector;
    std::string mPhoneDetectStatus;

};

#endif // PHONEDETECTCLASS_H
