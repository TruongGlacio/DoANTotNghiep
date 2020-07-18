#ifndef GLOBALFILE_H
#define GLOBALFILE_H
#include<QtDebug>
#define CAM_WIDTH 640
#define CAM_HEIGHT 480
#define FACE_DOWNSAMPLE_RATIO 2
#define SKIP_FRAMES 4
#define SKIP_FRAMES1 2
#define SKIP_FRAMES_HAND 30
#define TWO_EYELID_ASPECT_RATIO_STANDARD 0.24
#define EAR_ASPECT_RATIO_STANDARD_LOW 0.8
#define EAR_ASPECT_RATIO_STANDARD_HIGH 1.25
#define MOUTH_ASPECT_RATIO_STANDARD  0.45
#if __linux__

#define SHAPE_PREDIRTOR_68_FACE_LANDMARK "..\\dlib\\shape_predictor_68_face_landmarks.dat"//"D:\\Projects\\GitProjects\\DoAnTotNghiep\\DoANTotNghiep\\dlib\\shape_predictor_68_face_landmarks.dat"
#define PROTO_FILE "D:\\Projects\\GitProjects\\DoAnTotNghiep\\DoANTotNghiep\\dlib\\pose_deploy.prototxt"
#define WEIGHTS_FILE "D:\\Projects\\GitProjects\\DoAnTotNghiep\\DoANTotNghiep\\dlib\\pose_iter_102000.caffemodel"
#define FILE_PATH_FOR_TRAIN "D:\\Projects\\GitProjects\\DoAnTotNghiep\\DoANTotNghiep\\GenerateHandDataSet\\Hands-Detection-master\\images_training\\hands_training.xml"
#define FOLDER_PATH_SAVE_IMAGE "/ImageSave"
#else

#define SHAPE_PREDIRTOR_68_FACE_LANDMARK "..\\dlib\\shape_predictor_68_face_landmarks.dat"//"D:\\Projects\\GitProjects\\DoAnTotNghiep\\DoANTotNghiep\\dlib\\shape_predictor_68_face_landmarks.dat"
#define PROTO_FILE "D:\\Projects\\GitProjects\\DoAnTotNghiep\\DoANTotNghiep\\dlib\\pose_deploy.prototxt"
#define WEIGHTS_FILE "D:\\Projects\\GitProjects\\DoAnTotNghiep\\DoANTotNghiep\\dlib\\pose_iter_102000.caffemodel"
#define FILE_PATH_FOR_TRAIN "D:\\Projects\\GitProjects\\DoAnTotNghiep\\DoANTotNghiep\\GenerateHandDataSet\\Hands-Detection-master\\images_training\\hands_training.xml"
#define FOLDER_PATH_SAVE_IMAGE "/ImageSave"
#endif



#define TO_REPLACE_STRING ":"
#define TO_REPLACE_STRING1 " "
#define REPLACE_WITH_STRING "_"
#define FUNCTION_LOG() //(qDebug()<<"Function name: "<<__FUNCTION__ <<endl)

//define status
#define SLEEPING_STATUS "Sleeping"
#define NOT_SLEEPING_STATUS "Not sleeping"
#define YAWNING_MOUTH_STATUS "Yawning mouth"
#define NOT_YAWNING_MOUTH_STATUS "Not yawning mouth"
#define HEADING_PHONE_STATUS "Heading phone"
#define NOT_HEADING_PHONE_STATUS "Not heading phone"

#endif // GLOBALFILE_H
