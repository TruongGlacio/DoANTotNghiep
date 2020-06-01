#ifndef EYESLEEPDETECTCLASS_H
#define EYESLEEPDETECTCLASS_H

#define CAM_WIDTH 640
#define CAM_HEIGHT 480
#define SHAPE_PREDIRTOR_68_FACE_LANDMARK "D:\Projects\GitProjects\DoAnTotNghiep\DoANTotNghiep\dlib\shape_predictor_68_face_landmarks.dat"
#include <QObject>
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
//#include "opencv2/opencv.hpp"
//#include"opencv2/videoio.hpp"

using namespace dlib;
using namespace std;
using namespace cv;

class EyeSleepDetectClass : public QObject
{

    Q_OBJECT
public:
    explicit EyeSleepDetectClass(QObject *parent = nullptr);
    double compute_EAR(std::vector<cv::Point> vec);
    int StartDetectEyeSleep();
signals:
private:
  cv::VideoCapture* m_videoCapture;
  image_window win;
  shape_predictor sp;
  std::vector<cv::Point> righteye;
  std::vector<cv::Point> lefteye;
  char c;
  cv::Point p;

};

#endif // EYESLEEPDETECTCLASS_H
