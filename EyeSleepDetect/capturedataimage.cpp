#include "capturedataimage.h"

CaptureDataImage::CaptureDataImage(QObject *parent) : QObject(parent)
{

}

void CaptureDataImage::GetPhoneFrame(Mat frame)
{
    if ( countNumberOfFrame % SKIP_FRAMES == 0 )
    {

     Size size(640,640);//the dst image size,e.g.100x100
     Mat imageTosave;//dst image
     cv::resize(frame,imageTosave,size);//resize image
    qDebug()<< "Emit frame for save file " << endl;
    emit GetFrameForSaveToFile(imageTosave);
    emit SendPhoneFrameDrawed(imageTosave);

    }
    countNumberOfFrame ++;
    if(countNumberOfFrame ==100)
    {
        countNumberOfFrame =0;
    }
}
