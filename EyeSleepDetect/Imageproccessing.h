#ifndef IMAGEPROCCESSING_H
#define IMAGEPROCCESSING_H

#include <QObject>
//#include <dlib/data_io.h>
//#include <dlib/image_processing.h>
//#include <dlib/opencv.h>
//#include <dlib/image_io.h>
//#include <opencv2/imgproc.hpp>
#include"GlobalFile.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"


using namespace std;
using namespace cv;

Q_ENUMS(ThreadHoldType)

enum ThreadHoldType
     {
        Binary,
        BinaryInverted,
        Truncate,
        ToZero,
        ToZeroInverted,
     };
struct ExtremePoints{
    Point ExtremePointsMinX=Point(0,0);
    Point ExtremePointsMaxX=Point(0,0);
    Point ExtremePointsMinY=Point(0,0);
    Point ExtremePointsMaxY=Point(0,0);
};
struct MarkContours{
    int markExtremePointsMinX=0;
    int markExtremePointsMaxX=0;
    int markExtremePointsMinY=0;
    int markExtremePointsMaxY=0;
    };
struct ExtremePointsWithMark{
    ExtremePoints extremePoints;
    MarkContours markContours;
};
//typedef  std::vector<vector<Point>> Contours;
class ImageProccessing : public QObject
{
    Q_OBJECT
public:
    explicit ImageProccessing(QObject *parent = nullptr);

public slots:
    void ThresHoldingImage(cv::Mat frame);
    void SetThresHoldValue(int value);
    void SetThreadholdType(int threadholdType);
    void UpdateImageFrameForImagProccessing(cv::Mat frame);
    ExtremePointsWithMark FindExtremePoints(std::vector<std::vector<Point>> contours);
    int GetMediumThresholdValue(cv::Mat &frame);

signals:
    void SendFrameOutput(cv::Mat frame);
    void SendFrameInputImageProccessing(cv::Mat frame);
    void SendFrameForSaveToFile(cv::Mat frame);

private:
    int mThreshold_value =128;// recomment threshold value for braintumor : 0.6*thresholdValueMax
    const int thresholdValueMax=255;
    const int thresholdValueStep=1;//(int)65535/255;
    int mThreshold_type=0 ;
    Mat mImageFrame;

};

#endif // IMAGEPROCCESSING_H
