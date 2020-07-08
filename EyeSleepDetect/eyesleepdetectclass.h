#ifndef EYESLEEPDETECTCLASS_H
#define EYESLEEPDETECTCLASS_H

#define CAM_WIDTH 640
#define CAM_HEIGHT 480
#define SHAPE_PREDIRTOR_68_FACE_LANDMARK "D:\\Projects\\GitProjects\\DoAnTotNghiep\\DoANTotNghiep\\dlib\\shape_predictor_68_face_landmarks.dat"
#include <QObject>
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>

using namespace dlib;
using namespace std;
using namespace cv;

class EyeSleepDetectClass : public QObject
{

    Q_OBJECT
public:
    explicit EyeSleepDetectClass(QObject *parent = nullptr);
    double computeAveragPositionForEye(std::vector<cv::Point> vec);
    bool StartWebCam();
    void InitialFaceDetector(std::string shape_Predirtor);
    std::vector<image_window::overlay_line> GetSubObjectFromFullFace(full_object_detection shape,int startPoint, int endPoint);

signals:
    void SendFramegetFromCamera(cv::Mat frame);
public slots:
    void DetectEyeSleep(cv::Mat frame);
    void DetectLip(cv::Mat frame);

private:
  cv::VideoCapture* m_videoCapture;
  image_window win;
  shape_predictor landMarkOfFace;
  std::vector<cv::Point> pointsOfRightEye;
  std::vector<cv::Point> pointsOfLeftEye;
  char c;
  cv::Point locationPointsOfEye;
  int countNumberOfFrame=0;
  std::string shape_Predirtor;
  frontal_face_detector detector;

};

#endif // EYESLEEPDETECTCLASS_H
