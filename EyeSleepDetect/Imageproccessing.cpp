#include "Imageproccessing.h"

ImageProccessing::ImageProccessing(QObject *parent) : QObject(parent)
{
    FUNCTION_LOG();
    connect(this, SIGNAL(SendFrameInputImageProccessing(cv::Mat)),this,SLOT(ThresHoldingImage(cv::Mat)));
}

void ImageProccessing::ThresHoldingImage(cv::Mat frame)
{
    FUNCTION_LOG();


    cv::Mat src_gray, frameOutput;
    RNG rng(12345);
    std::vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    int countBrainTumor=0;
    std::string tumorStatus="";
    // Convert the image to Gray
    qDebug()<<"Chanel of frame input ="<<frame.channels()<<endl;
    qDebug() << "Width : " << frame.size().width << endl;
    qDebug() << "Height: " << frame.size().height << endl;
    double scalesize=frame.size().height/frame.size().width;
    resize(frame, frame, Size(640, 640*frame.size().height/frame.size().width), 0, 0, INTER_CUBIC); // resize to 1024x768 resolution

    cvtColor( frame, frameOutput, COLOR_RGB2GRAY);
  //  int thresholdMedium=GetMediumThresholdValue(frameOutput);
    double ret= threshold( frameOutput, src_gray, 0.6* thresholdValueMax, thresholdValueMax ,mThreshold_type );
    //threshold( frame, src_gray, 128, thresholdValueMax ,mThreshold_type );


    cv::GaussianBlur(src_gray,src_gray, cv::Size(5,5), 2);
    cv::erode(src_gray,src_gray,5);
    cv::dilate(src_gray, src_gray, 5);
    blur( src_gray, src_gray, Size(3,3) );
    Canny( src_gray, src_gray,0.6* thresholdValueMax,0.6* thresholdValueMax*2);// thresholdValueMax );
    cv::findContours(src_gray, contours,hierarchy,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    ExtremePointsWithMark extremePoints=FindExtremePoints(contours);
    qDebug()<<"extremePoints.markContours.markExtremePointsMaxX="<<extremePoints.markContours.markExtremePointsMaxX<<endl;
    qDebug()<<"extremePoints.markContours.markExtremePointsMinX="<<extremePoints.markContours.markExtremePointsMinX<<endl;
    qDebug()<<"extremePoints.markContours.markExtremePointsMaxY="<<extremePoints.markContours.markExtremePointsMaxY<<endl;
    qDebug()<<"extremePoints.markContours.markExtremePointsMinY="<<extremePoints.markContours.markExtremePointsMinY<<endl;
    //Mat drawing = Mat::zeros( src_gray.size(), CV_8UC3  );
    qDebug()<<"contours.size="<<contours.size()<<endl<<"hierarchy.size="<<hierarchy.size()<<endl;

    for( size_t i = 0; i< contours.size(); i++ )
    {

        Scalar color = Scalar( 255, 1, 1 );

        vector<Point> contourI=contours.at(i);
        qDebug()<<"Area of countors["<<i<<"] ="<<contourArea(contours.at(i))<<endl;
        if( contourArea(contourI)>scalesize*100)// && contourArea(contourI)<7000*9 )//\
//            && extremePoints.markContours.markExtremePointsMaxX!=(int)i\
//            && extremePoints.markContours.markExtremePointsMinX!=(int)i\
//            && extremePoints.markContours.markExtremePointsMaxY!=(int)i\
//            && extremePoints.markContours.markExtremePointsMinY!=(int)i)

        {   countBrainTumor++;
            qDebug()<<"Area of countors was drawed["<<i<<"] ="<<contourArea(contours.at(i))<<endl;
            for (size_t j=0;j<contourI.size()-1 ;j++) {

                cv::line(frame, contourI.at(j),  contourI.at(j+1), color, 1, 8, 0);
            }

        }

    }
    if(countBrainTumor<=0)
    {
        tumorStatus="Not find tumor";

    }
    else {
        tumorStatus= "Find number of tumor: "+ std::to_string(countBrainTumor);
    }
    cv::putText(frame, tumorStatus, cv::Point(20,200), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, cv::Scalar(0,255,0),1, cv::LINE_AA);

    emit SendFrameOutput(frame);
    //emit SendFrameForSaveToFile(drawing);

}

void ImageProccessing::SetThresHoldValue(int value)
{
    FUNCTION_LOG();

    mThreshold_value=value*thresholdValueStep;
    qDebug()<<"ThresHoldValue="<<mThreshold_value<<endl;
    emit SendFrameInputImageProccessing(mImageFrame);
}

void ImageProccessing::SetThreadholdType(int threadholdType)
{
    FUNCTION_LOG();

    mThreshold_type= (ThreadHoldType)threadholdType;
    qDebug()<<"ThreadholdType= "<<mThreshold_type<<endl;
    emit SendFrameInputImageProccessing(mImageFrame);

}

void ImageProccessing::UpdateImageFrameForImagProccessing(Mat frame)
{
    FUNCTION_LOG();

    mImageFrame=frame;
    qDebug()<<"Image frame was updated "<<endl;
    emit SendFrameInputImageProccessing(mImageFrame);


}

ExtremePointsWithMark ImageProccessing::FindExtremePoints(std::vector<std::vector<Point>> contours)
{
    ExtremePointsWithMark extremePointsWithMark;
    ExtremePoints extremePoints;
    MarkContours markContours;
    std::vector<ExtremePoints>ExtremePointsVector;

    //initial ouput

    /*______________________________________*/
    extremePoints.ExtremePointsMaxX=Point(0,0);
    extremePoints.ExtremePointsMaxY=Point(0,0);
    extremePoints.ExtremePointsMinX=Point(0,0);
    extremePoints.ExtremePointsMinY=Point(0,0);

    markContours.markExtremePointsMinX=0;
    markContours.markExtremePointsMaxX=0;
    markContours.markExtremePointsMinY=0;
    markContours.markExtremePointsMaxY=0;

    extremePointsWithMark.extremePoints=extremePoints;
    extremePointsWithMark.markContours=markContours;
    /*______________________________________*/

    if(contours.size()<=0)
    {

        return  extremePointsWithMark;
    }


    for( size_t i = 0; i< contours.size(); i++ )
    {
        ExtremePoints extremePointstemp;
        Point extremePointsMinX=contours[i].at(0);
        Point extremePointsMaxX=contours[i].at(0);
        Point extremePointsMinY=contours[i].at(0);
        Point extremePointsMaxY=contours[i].at(0);

        for (size_t j=0;j<contours[i].size()-1 ;j++) {

            //find MinX
            if(extremePointsMinX.x>contours[i].at(j).x)
                extremePointsMinX.x=contours[i].at(j).x;
            //find MaxX
            if(extremePointsMaxX.x<contours[i].at(j).x)
                extremePointsMaxX.x=contours[i].at(j).x;
            //find MinY
            if(extremePointsMinY.y>contours[i].at(j).y)
                extremePointsMaxX.y=contours[i].at(j).y;
            //find MaxY
            if(extremePointsMaxY.y<contours[i].at(j).y)
                extremePointsMaxY.y=contours[i].at(j).y;
        }
        extremePointstemp.ExtremePointsMaxX=extremePointsMaxX;
        extremePointstemp.ExtremePointsMinX=extremePointsMinX;
        extremePointstemp.ExtremePointsMaxY=extremePointsMaxY;
        extremePointstemp.ExtremePointsMinY=extremePointsMinY;
        ExtremePointsVector.push_back(extremePointstemp);
    }


    if(ExtremePointsVector.size()<=0)
        return extremePointsWithMark;


    extremePoints=ExtremePointsVector.at(0);
    for (size_t k=0;k<ExtremePointsVector.size()-1 ;k++) {

        //find MaxX
        if(extremePoints.ExtremePointsMaxX.x<ExtremePointsVector.at(k).ExtremePointsMaxX.x)
        {
            extremePoints.ExtremePointsMaxX.x=ExtremePointsVector.at(k).ExtremePointsMaxX.x;
            markContours.markExtremePointsMaxX=k;
        }
        //find MinX
        if(extremePoints.ExtremePointsMinX.x>ExtremePointsVector.at(k).ExtremePointsMinX.x)
        {
            extremePoints.ExtremePointsMinX.x=ExtremePointsVector.at(k).ExtremePointsMinX.x;
            markContours.markExtremePointsMinX=k;

        }
        //find MinY
        if(extremePoints.ExtremePointsMinY.y > ExtremePointsVector.at(k).ExtremePointsMinY.y)
        {
            extremePoints.ExtremePointsMinY.y=ExtremePointsVector.at(k).ExtremePointsMinY.y;
            markContours.markExtremePointsMinY=k;

        }
        //find MaxY
        if(extremePoints.ExtremePointsMaxY.y<ExtremePointsVector.at(k).ExtremePointsMaxY.y)
        {
            extremePoints.ExtremePointsMaxY.y=ExtremePointsVector.at(k).ExtremePointsMaxY.y;
            markContours.markExtremePointsMaxY=k;

        }

    }
    extremePointsWithMark.extremePoints=extremePoints;
    extremePointsWithMark.markContours=markContours;

    return extremePointsWithMark;
}
int ImageProccessing::GetMediumThresholdValue(Mat &frame)
{
    int MediumThresholdValue=0;
    int MaxThresholdValue=frame.at<uchar>(0,0);
    int MinThresholdValue=frame.at<uchar>(0,0);
    for (int i=0; i< frame.rows; i++)
        {
            for (int j=0; j< frame.cols; j++)
            {
                int editValue=frame.at<uchar>(i,j);

                if(editValue> MaxThresholdValue)
                    MaxThresholdValue=editValue;

                if(editValue<MinThresholdValue)
                    MinThresholdValue=editValue;
            }
        }

    MediumThresholdValue=MinThresholdValue+(MaxThresholdValue-MinThresholdValue)/2;
    qDebug()<<"MinThresholdValue="<<MinThresholdValue<<endl<<"MaxThresholdValue="<<MaxThresholdValue<<"MediumThresholdValue="<<MediumThresholdValue <<endl;
    qDebug()<<"frame.rows="<<frame.rows<<endl<<"frame.cols="<<frame.cols<<endl;
    int rowscount=0;
    for (int i=0; i< frame.rows; i++)
        {   rowscount++;
            int colscount=0;
            for (int j=0; j< frame.cols; j++)
            {   colscount++;
                //int editValue=frame.at<uchar>(i,j);
                if((frame.at<uchar>(i,j)>MediumThresholdValue)) //check whether value is within range.
                {
                    frame.at<uchar>(i,j)=255;
                }
                else
                {
                    frame.at<uchar>(i,j)=0;
                }
            }
          //   qDebug()<<"colscount="<<colscount<<endl;
        }
    qDebug()<<"rowscount="<<rowscount<<endl;

    return  MediumThresholdValue;
}
