#include "eyesleepdetectclass.h"
#include<QDebug>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include "opencv2/opencv.hpp"
#include"opencv2/videoio.hpp"
EyeSleepDetectClass::EyeSleepDetectClass(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(GetCvImage(std::vector<dlib::rectangle>)), this, SLOT(SetCvImage(std::vector<dlib::rectangle>)));
    connect(this, SIGNAL(GetShape_predictor(shape_predictor)), this, SLOT(SetShape_predictor(shape_predictor)));
    moveToThread(&thread);
    connect(&thread, SIGNAL(started()), this, SLOT(DeserializeFace())); //cant have parameter sorry, when using connect
    thread.start();
}
double EyeSleepDetectClass::compute_EAR(std::vector<cv::Point> vec)
{

    double a = cv::norm(cv::Mat(vec[1]), cv::Mat(vec[5]));
    double b = cv::norm(cv::Mat(vec[2]), cv::Mat(vec[4]));
    double c = cv::norm(cv::Mat(vec[0]), cv::Mat(vec[3]));
    //compute EAR
    double ear = (a + b) / (2.0 * c);
    return ear;
}
void EyeSleepDetectClass::DeserializeFace()
{
    shape_predictor sp;
    cv_image<bgr_pixel> cimg;
    frontal_face_detector detector = get_frontal_face_detector();
    deserialize(SHAPE_PREDIRTOR_68_FACE_LANDMARK)>> sp;
    std::vector<dlib::rectangle> faces = detector(cimg);
    emit GetCvImage(faces);
    emit GetShape_predictor(sp);

}
int EyeSleepDetectClass::StartDetectEyeSleep()
{
    try {
        cv::VideoCapture cap(0);
        m_videoCapture = new cv::VideoCapture(0);
        m_videoCapture->open(0);
        m_videoCapture->set(CAP_PROP_FRAME_WIDTH, CAM_WIDTH);//use small resolution for fast processing
        m_videoCapture->set(CAP_PROP_FRAME_HEIGHT, CAM_HEIGHT);
        if (!m_videoCapture->isOpened()) {
            qDebug() << "Unable to connect to camera";
            return 1;
        }
        // Load face detection and deserialize  face landmarks model.
       // frontal_face_detector detector = get_frontal_face_detector();
        //deserialize(SHAPE_PREDIRTOR_68_FACE_LANDMARK)>> sp;

        // Grab and process frames until the main window is closed by the user.
        while (!win.is_closed()) {
            // Grab a frame
            cv::Mat temp;
            if (!m_videoCapture->read(temp)) {
                break;
            }

            //cv_image<bgr_pixel> cimg(temp);
            mCimg=cv_image<bgr_pixel>(temp);
            full_object_detection shape;
            // Detect faces
            //std::vector<dlib::rectangle> faces; = detector(cimg);
            //qDebug()<< "Number of faces detected: " << faces.size() << endl;
            //DrawFaceAfterDetect(&win,&mCimg,&mFaces,mSp);
            c = (char)waitKey(50);
            if (c == 27)
                break;
        }
    }
    catch (serialization_error& e) {
        cout << "Check the path to dlib's default face landmarking model file to run this example." << endl;
        cout << "You can get it from the following URL: " << endl;
        cout << "http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
        cout << endl
             << e.what() << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}

void EyeSleepDetectClass::SetShape_predictor(shape_predictor sp)
{
    mSp=sp;
}

void EyeSleepDetectClass::SetCvImage(std::vector<dlib::rectangle> faces)
{
    mFaces=faces;
}
void EyeSleepDetectClass::DrawFaceAfterDetect(image_window *mwin,cv_image<bgr_pixel> *cimg,std::vector<dlib::rectangle> *faces,  shape_predictor sp)
{
    full_object_detection shape;
    std::vector<cv::Point> _righteye;
    std::vector<cv::Point> _lefteye;
    cv::Point p;
    char c;


    mwin->clear_overlay();
    mwin->set_image(*cimg);

    // Find the pose of each face.
    if (faces->size() > 0) {

        shape = sp(*cimg, faces->at(0)); //work only with 1 face

        for (int b = 36; b < 42; ++b) {
            p.x = shape.part(b).x();
            p.y = shape.part(b).y();
            _lefteye.push_back(p);
        }
        for (int b = 42; b < 48; ++b) {
            p.x = shape.part(b).x();
            p.y = shape.part(b).y();
            _righteye.push_back(p);
        }
        //Compute Eye aspect ration for eyes
        double right_ear = compute_EAR(_righteye);
        double left_ear = compute_EAR(_lefteye);

        //if the avarage eye aspect ratio of lef and right eye less than 0.2, the status is sleeping.
        if ((right_ear + left_ear) / 2 < 0.2)
            mwin->add_overlay(dlib::image_window::overlay_rect(faces->at(0), rgb_pixel(255, 255, 255), "Sleeping"));
        else
            mwin->add_overlay(dlib::image_window::overlay_rect(faces->at(0), rgb_pixel(255, 255, 255), "Not sleeping"));

        _righteye.clear();
        _lefteye.clear();

        mwin->add_overlay(render_face_detections(shape));

    }
}


