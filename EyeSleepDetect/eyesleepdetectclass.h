#ifndef EYESLEEPDETECTCLASS_H
#define EYESLEEPDETECTCLASS_H

#define CAM_WIDTH 640
#define CAM_HEIGHT 480
#define SHAPE_PREDIRTOR_68_FACE_LANDMARK "E:\\GitProiects\\DoANTotNghiep\\dlib\\shape_predictor_68_face_landmarks.dat"
#include <QObject>
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include<QTimer>
//#include "opencv2/opencv.hpp"
//#include"opencv2/videoio.hpp"
#include<QThread>

using namespace dlib;
using namespace std;
using namespace cv;

class EyeSleepDetectClass : public QObject
{

    Q_OBJECT
public:
    explicit EyeSleepDetectClass(QObject *parent = nullptr);
    double compute_EAR(std::vector<cv::Point> vec);
    void DrawFaceAfterDetect(image_window *mwin,cv_image<bgr_pixel> *cimg,std::vector<dlib::rectangle> *faces,  shape_predictor sp);
    int StartDetectEyeSleep();
signals:
   void GetCvImage(std::vector<dlib::rectangle> faces);
   void GetShape_predictor(shape_predictor sp);
public slots:
   void  DeserializeFace();
   void SetCvImage(std::vector<dlib::rectangle> faces);
   void SetShape_predictor(shape_predictor sp);
public:
   cv_image<bgr_pixel> mCimg;

private:
  cv::VideoCapture* m_videoCapture;
  image_window win;
  shape_predictor mSp;
  std::vector<dlib::rectangle> mFaces;
  std::vector<cv::Point> righteye;
  std::vector<cv::Point> lefteye;
  char c;
  cv::Point p;
  QThread thread;
};

#endif // EYESLEEPDETECTCLASS_H
