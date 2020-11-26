#ifndef ROADMARKERDETECT_H
#define ROADMARKERDETECT_H

#include <QObject>
#include"GlobalLib.h"
#include<GlobalFile.h>

using namespace dlib;
using namespace std;
using namespace cv;
using namespace cv::dnn;
typedef scan_fhog_pyramid<pyramid_down<6> > image_scanner_type;

class RoadMarkerDetect : public QObject
{
    Q_OBJECT
public:
    explicit RoadMarkerDetect(QObject *parent = nullptr);

signals:
    void SendRoadMarkerFrameDrawed(cv::Mat frame);
    void GetFrameForSaveToFile(cv::Mat frame);
public slots:
void DetectRoadMarker(cv::Mat frame);
void InitialRoadMarkerDetector(std::string PredirtorPath,std::string shapeDetectorPath);
cv::Mat DrawandRoadMarkerLineOnFrame(full_object_detection shape,cv::Mat frame);
cv::Mat DrawRoadMarkerDetectStatus(cv::Mat frame, std::string roadMarkerdetectStatus);
std::vector<dlib::rectangle> ResizeBoxes(std::vector<dlib::rectangle> rects, int scaleFactor);


private:

int countNumberOfFrame=0;
std::string shapeLandMarkPredirtorPath;
std::string shapeRoadMarkerDetectorPath;

cv::Point locationPointsOfPhone;
frontal_face_detector detector;
shape_predictor landMarkOfRoadmarker;

object_detector<image_scanner_type> roadmarkerDetector;
std::string mRoadMarkerDetectStatus;

};


#endif // ROADMARKERDETECT_H
