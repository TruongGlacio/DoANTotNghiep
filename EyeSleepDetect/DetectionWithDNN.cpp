#include "DetectionWithDNN.h"

DetectionWithDNN::DetectionWithDNN(QObject *parent) : QObject(parent)
{
    FUNCTION_LOG();

    InitialDetecWithDNN();
}

void DetectionWithDNN::InitialDetecWithDNN()
{
    FUNCTION_LOG();

    mPredirtorFilePath=PREDIRTOR_WITH_DNN;

    deserialize(mPredirtorFilePath) >> mNet;

}

void DetectionWithDNN::DetectWithDNN(Mat frame)
{    FUNCTION_LOG();

     try
     {/*
        if (argc == 1)
        {
            cout << "Call this program like this:" << endl;
            cout << "./dnn_mmod_face_detection_ex mmod_human_face_detector.dat faces/*.jpg" << endl;
            cout << "\nYou can get the mmod_human_face_detector.dat file from:\n";
            cout << "http://dlib.net/files/mmod_human_face_detector.dat.bz2" << endl;
            return 0;
        }*/


        net_type net=mNet;

        //image_window win;
        cv::Mat im_small, im_display;
        matrix<rgb_pixel> matrix;
        cv::resize(frame, im_small, cv::Size(), 1.0/FACE_DOWNSAMPLE_RATIO, 1.0/FACE_DOWNSAMPLE_RATIO);

        cv_image<bgr_pixel>image(im_small);
        assign_image(matrix,image);
        qDebug()<<"assign_image Frame";

        //load_image(img, argv[i]);

        // Upsampling the image will allow us to detect smaller faces but will cause the
        // program to use more RAM and run longer.
//        while(matrix.size() > 1800*1800)
//        {
//            qDebug()<<"Pyup net Frame, matrix size="<<matrix.size();
        pyramid_up(matrix);
//        }

        // Note that you can process a bunch of images in a std::vector at once and it runs
        // much faster, since this will form mini-batches of images and therefore get
        // better parallelism out of your GPU hardware.  However, all the images must be
        // the same size.  To avoid this requirement on images being the same size we
        // process them individually in this example.
        auto dets = net(matrix);
        qDebug()<<"net Frame";
        //win.clear_overlay();
        //win.set_image(matrix);
        cv::Rect rect;
        if(dets.size()<=0)
            qDebug()<<"Can't detect any face";
        for (auto&& d : dets)
        {
            rect=Rect(d.rect.left(),d.rect.top(),d.rect.width()*FACE_DOWNSAMPLE_RATIO,d.rect.height()*FACE_DOWNSAMPLE_RATIO);
            cv::rectangle(frame,rect,Scalar(255,0,0));
        }
        qDebug()<<"Send Frame to camera manager";
        emit SendFrameDetectDNN(frame);
        //  win.add_overlay(d);

        cout << "Hit enter to process the next image." << endl;
        // cin.get();
     }
     catch(std::exception& e)
    {
        cout << e.what() << endl;
    }


}
