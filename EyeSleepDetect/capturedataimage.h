#ifndef CAPTUREDATAIMAGE_H
#define CAPTUREDATAIMAGE_H

#include <QObject>
#include"GlobalLib.h"
#include<GlobalFile.h>

using namespace dlib;
using namespace std;
using namespace cv;
using namespace cv::dnn;
typedef scan_fhog_pyramid<pyramid_down<6> > image_scanner_type;
class CaptureDataImage : public QObject
{
    Q_OBJECT
public:
    explicit CaptureDataImage(QObject *parent = nullptr);

signals:
    void SendPhoneFrameDrawed(cv::Mat frame);
    void GetFrameForSaveToFile(cv::Mat frame);
public slots:
void GetPhoneFrame(cv::Mat frame);
private:
int countNumberOfFrame=0;
};

#endif // CAPTUREDATAIMAGE_H
