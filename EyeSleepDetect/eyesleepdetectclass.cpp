#define FACE_DOWNSAMPLE_RATIO 2
#define SKIP_FRAMES 4
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
    StartDetectEyeSleep();
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

int EyeSleepDetectClass:: StartDetectEyeSleep()
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
        frontal_face_detector detector = get_frontal_face_detector();

        deserialize(SHAPE_PREDIRTOR_68_FACE_LANDMARK) >> sp;

        // Grab and process frames until the main window is closed by the user.
        while (!win.is_closed()) {
            // Grab a frame
            cv::Mat temp;
            cv::Mat im_small, im_display;
            if (!m_videoCapture->read(temp)) {
                break;
            }
            cv::resize(temp, im_small, cv::Size(), 1.0/FACE_DOWNSAMPLE_RATIO, 1.0/FACE_DOWNSAMPLE_RATIO);
            cv_image<bgr_pixel> cimg(im_small);
            cv_image<bgr_pixel> cimgForView(temp);
            // Resize image for face detection
            full_object_detection shape;

            // Detect faces
            std::vector<dlib::rectangle> faces;
            if ( count % SKIP_FRAMES == 0 )
            {
                faces = detector(cimg);
                qDebug()<< "Number of faces detected: " << faces.size() << endl;
            }
           // qDebug()<< "Number of faces detected: " << faces.size() << endl;

            win.clear_overlay();
           // win.set_image(cimgForView);

            // Find the pose of each face.
            if (faces.size() > 0) {

                shape = sp(cimg, faces[0]); //work only with 1 face

                for (int b = 36; b < 42; ++b) {
                    p.x = shape.part(b).x()*FACE_DOWNSAMPLE_RATIO;
                    p.y = shape.part(b).y()*FACE_DOWNSAMPLE_RATIO;
                    lefteye.push_back(p);
                }
                for (int b = 42; b < 48; ++b) {
                    p.x = shape.part(b).x()*FACE_DOWNSAMPLE_RATIO;
                    p.y = shape.part(b).y()*FACE_DOWNSAMPLE_RATIO;
                    righteye.push_back(p);
                }
                //Compute Eye aspect ration for eyes
                double right_ear = compute_EAR(righteye);
                double left_ear = compute_EAR(lefteye);

                //if the avarage eye aspect ratio of lef and right eye less than 0.2, the status is sleeping.
                if ((right_ear + left_ear) / 2 < 0.2)
                {
                    qDebug()<< "Sleeping" << endl;
                   // win.add_overlay(dlib::image_window::overlay_rect(faces[0], rgb_pixel(255, 255, 255), "Sleeping"));
                }
                else
                {
                     qDebug()<< "Not sleeping" << endl;
                   // win.add_overlay(dlib::image_window::overlay_rect(faces[0], rgb_pixel(255, 255, 255), "Not sleeping"));
                }

                righteye.clear();
                lefteye.clear();

               // win.add_overlay(render_face_detections(shape));

                c = (char)waitKey(30);
                if (c == 27)
                    break;
            }
            count ++;
            if(count ==100)
            {
                count =0;
            }
        }
    }
    catch (serialization_error& e) {
        cout << "Check the path to dlib's default face landmarking model file to run this example." << endl;
        cout << "You can get it from the following URL: " << endl;
        cout << "   http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
        cout << endl
             << e.what() << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}
