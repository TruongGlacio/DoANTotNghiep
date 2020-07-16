#include "handDetectClass.h"
#include<QDebug>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include "opencv2/opencv.hpp"
#include"opencv2/videoio.hpp"


HandDetectClass::HandDetectClass(QObject *parent) : QObject(parent)
{
    FUNCTION_LOG();



}

void HandDetectClass::DetectHand(cv::Mat frame, image_window *mWin)
{

    FUNCTION_LOG();

    cout << "USAGE : ./handPoseImage <imageFile> " << endl;
    float thresh = 0.01;

    Mat frameCopy = frame.clone();

    //if detect hand key point finish, get next frame for detect
    if(countNumberOfFrame % SKIP_FRAMES_HAND == 0){
        int frameWidth = frame.cols;
        int frameHeight = frame.rows;

        float aspect_ratio = frameWidth/(float)frameHeight;
        int inHeight = 368;
        int inWidth = (int(aspect_ratio*inHeight) * 8) / 8;

        cout << "inWidth = " << inWidth << " ; inHeight = " << inHeight << endl;

        t = (double) cv::getTickCount();
        Net net = readNetFromCaffe(protoFile, weightsFile);

        Mat inpBlob = blobFromImage(frame, 1.0 / 255, Size(inWidth, inHeight), Scalar(0, 0, 0), false, false);

        net.setInput(inpBlob);

        Mat output = net.forward();

        int H = output.size[2];
        int W = output.size[3];

        // find the position of the body parts
        std::vector<Point> points(nPoints);
        for (int n=0; n < nPoints; n++)
        {
            // Probability map of corresponding body's part.
            Mat probMap(H, W, CV_32F, output.ptr(0,n));
            resize(probMap, probMap, Size(frameWidth, frameHeight));

            Point maxLoc;
            double prob;
            minMaxLoc(probMap, 0, &prob, 0, &maxLoc);
            if (prob > thresh)
            {
                circle(frameCopy, cv::Point((int)maxLoc.x, (int)maxLoc.y), 8, Scalar(0,255,255), -1);
                cv::putText(frameCopy, cv::format("%d", n), cv::Point((int)maxLoc.x, (int)maxLoc.y), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 0, 255), 2);

            }
            points[n] = maxLoc;
        }

        int nPairs = sizeof(POSE_PAIRS)/sizeof(POSE_PAIRS[0]);

        for (int n = 0; n < nPairs; n++)
        {
            // lookup 2 connected body/hand parts
            Point2f partA = points[POSE_PAIRS[n][0]];
            Point2f partB = points[POSE_PAIRS[n][1]];

            if (partA.x<=0 || partA.y<=0 || partB.x<=0 || partB.y<=0)
                continue;

            cv::line(frame, partA, partB, Scalar(0,255,255), 8);
            circle(frame, partA, 8, Scalar(0,0,255), -1);
            circle(frame, partB, 8, Scalar(0,0,255), -1);
        }

        t = ((double)cv::getTickCount() - t)/cv::getTickFrequency();
        cout << "Time Taken = " << t << endl;
    }

    cv_image<bgr_pixel> cimg(frame);
    mWin->clear_overlay();
    mWin->set_image(cimg);
    countNumberOfFrame ++;
    if(countNumberOfFrame ==100)
    {
        countNumberOfFrame =0;
    }
    //  imshow("Output-Keypoints", frameCopy);
    // imshow("Output-Skeleton", frame);
    //  imwrite("Output-Skeleton.jpg", frame);

    waitKey();

}
