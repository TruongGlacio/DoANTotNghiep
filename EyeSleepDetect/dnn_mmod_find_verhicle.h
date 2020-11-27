#ifndef DNN_MMOD_FIND_VERHICLE_H
#define DNN_MMOD_FIND_VERHICLE_H

#include <QObject>
#include <GlobalLib.h>
#include<GlobalFile.h>
using namespace std;
using namespace dlib;
using namespace cv;
// The rear view vehicle detector network
template <long num_filters, typename SUBNET> using con5d = con<num_filters,5,5,2,2,SUBNET>;
template <long num_filters, typename SUBNET> using con5  = con<num_filters,5,5,1,1,SUBNET>;
template <typename SUBNET> using downsampler  = relu<affine<con5d<32, relu<affine<con5d<32, relu<affine<con5d<16,SUBNET>>>>>>>>>;
template <typename SUBNET> using rcon5  = relu<affine<con5<55,SUBNET>>>;
using net_type = loss_mmod<con<1,9,9,1,1,rcon5<rcon5<rcon5<downsampler<input_rgb_image_pyramid<pyramid_down<6>>>>>>>>;

typedef scan_fhog_pyramid<pyramid_down<6> > image_scanner_type;

// ----------------------------------------------------------------------------------------
class dnn_mmod_find_verhicle : public QObject
{
    Q_OBJECT
public:
    explicit dnn_mmod_find_verhicle(QObject *parent = nullptr);

signals:
    void SendVerhicleFrameDrawed(cv::Mat frame);
    void GetFrameForSaveToFile(cv::Mat frame);
public slots:
    void DetectVerhicle(cv::Mat frame);
    void InitialVerhicleDetector(std::string shapeDetectorPath);
    cv::Mat DrawandVerhicleLineOnFrame(full_object_detection shape,cv::Mat frame);
    cv::Mat DrawRVerhicleDetectStatus(cv::Mat frame, std::string verhicledetectStatus);
    std::vector<dlib::rectangle> ResizeBoxes(std::vector<dlib::rectangle> rects, int scaleFactor);
private:

    int countNumberOfFrame=0;
    std::string shapeVerhicleDetectorPath;
    shape_predictor landMarkOfRVerhicle;
    net_type mNet;
    shape_predictor mSp;
    object_detector<image_scanner_type> verhicleDetector;
    std::string mVerhicleDetectStatus;
};

#endif // DNN_MMOD_FIND_VERHICLE_H
