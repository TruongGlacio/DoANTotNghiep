#ifndef EYESLEEPDETECTCLASS_H
#define EYESLEEPDETECTCLASS_H

#include <QObject>
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include<GlobalFile.h>
using namespace dlib;
using namespace std;
using namespace cv;

class FacesDetectClass : public QObject
{

    Q_OBJECT
public:
    explicit FacesDetectClass(QObject *parent = nullptr);
    double ComputerAspectRatioForEye(std::vector<cv::Point> vec);
    double ComputerAspectRatioForEarAndNose(std::vector<cv::Point> vec);
    double ComputerAspectRatioForMouth(std::vector<cv::Point> vec);

    //bool StartWebCam();
    void InitialFaceDetector(std::string shape_Predirtor);
    std::vector<image_window::overlay_line> DrawEyeLineOnFrame(full_object_detection shape);
    std::vector<image_window::overlay_line> DrawEarAndNoseLineOnFrame(full_object_detection shape);
    std::vector<image_window::overlay_line> DrawMouthLineOnFrame(full_object_detection shape);

signals:
    void SendFramegetFromCamera(cv::Mat frame);
public slots:
    void DetectEyeSleep(cv::Mat frame, image_window *mWin);
    void DetectEarAndNose(cv::Mat frame, image_window *mWin);
    void DetectYawnMouth(cv::Mat frame, image_window *mWin);


private:
  cv::VideoCapture* m_videoCapture;
  shape_predictor landMarkOfFace;
  char c;
  cv::Point locationPointsOfEye;
  cv::Point locationPointsOfEar;
  cv::Point locationPointsOfNose;
  int countNumberOfFrame=0;
  std::string shape_Predirtor;
  frontal_face_detector detector;

};

#endif // EYESLEEPDETECTCLASS_H
