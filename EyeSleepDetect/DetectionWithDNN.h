#ifndef DETECTIONWITHDNN_H
#define DETECTIONWITHDNN_H

#include <QObject>
#include <iostream>
#include <dlib/dnn.h>
#include <dlib/data_io.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/opencv.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_io.h>


#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<GlobalFile.h>

using namespace std;
using namespace dlib;
using namespace cv;
using namespace cv::dnn;

class DetectionWithDNN : public QObject
{
    Q_OBJECT
public:
    explicit DetectionWithDNN(QObject *parent = nullptr);
    void InitialDetecWithDNN();
public slots:
    void DetectWithDNN(cv::Mat frame);


signals:
    void SendFrameDetectDNN(cv::Mat frame);
private:

    // ----------------------------------------------------------------------------------------

    template <long num_filters, typename SUBNET> using con5d = con<num_filters,5,5,2,2,SUBNET>;
    template <long num_filters, typename SUBNET> using con5  = con<num_filters,5,5,1,1,SUBNET>;

    template <typename SUBNET> using downsampler  = relu<affine<con5d<32, relu<affine<con5d<32, relu<affine<con5d<16,SUBNET>>>>>>>>>;
    template <typename SUBNET> using rcon5  = relu<affine<con5<45,SUBNET>>>;

    using net_type = loss_mmod<con<1,9,9,1,1,rcon5<rcon5<rcon5<downsampler<input_rgb_image_pyramid<pyramid_down<6>>>>>>>>;
    net_type mNet;
    std::string mPredirtorFilePath;
    // ----------------------------------------------------------------------------------------
};

#endif // DETECTIONWITHDNN_H
