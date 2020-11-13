#ifndef GLOBALFILE_H
#define GLOBALFILE_H
#include<QtDebug>
#define CAM_WIDTH 640
#define CAM_HEIGHT 480
#define FACE_DOWNSAMPLE_RATIO 0.5
#define HAND_DOWNSAMPLE_RATIO 0.5
#define HAND_IMAGE_SCALE_RESIZE 3
#define SKIP_FRAMES 2
#define SKIP_FRAMES1 1
#define SKIP_FRAMES_HAND 30
#define TWO_EYELID_ASPECT_RATIO_STANDARD 0.2
#define EAR_ASPECT_RATIO_STANDARD_LOW 0.8
#define EAR_ASPECT_RATIO_STANDARD_HIGH 1.25
#define MOUTH_ASPECT_RATIO_STANDARD  0.45

#if __linux__
//#define SHAPE_PREDIRTOR_68_FACE_LANDMARK "..//dlib//shape_predictor_68_face_landmarks.dat"
//#define FILE_PATH_FOR_TRAIN "../GenerateHandDataSet/Hands-Detection-master/images_training/hands_training.xml"
//#define SHAPE_PREDIRTOR_HAND_LANDMARK "..//dlib//handModels//Hand_9_Landmarks_Detector.dat"
//#define SHAPE_HAND_DETECTOR_PATH "../dlib/handModels/HandDetector.svm"
#define SHAPE_PREDIRTOR_68_FACE_LANDMARK "shape_predictor_68_face_landmarks.dat"
#define FILE_PATH_FOR_TRAIN "hands_training.xml"
#define SHAPE_PREDIRTOR_HAND_LANDMARK "Hand_9_Landmarks_Detector.dat"
#define SHAPE_HAND_DETECTOR_PATH "HandDetector.svm"
#define FOLDER_PATH_SAVE_IMAGE "/ImageSave"


#else

#define SHAPE_PREDIRTOR_68_FACE_LANDMARK "..\\dlib\\shape_predictor_68_face_landmarks.dat"
#define SHAPE_PREDIRTOR_HAND_LANDMARK "..\\dlib\\handModels\\Hand_9_Landmarks_Detector.dat"
#define SHAPE_HAND_DETECTOR_PATH "..\\dlib\\handModels\\HandDetector.svm"
#define FILE_PATH_FOR_TRAIN "..\\GenerateHandDataSet\\Hands-Detection-master\\images_training\\hands_training.xml"
#define FOLDER_PATH_SAVE_IMAGE "/ImageSave"
#endif

#define TO_REPLACE_STRING ":"
#define TO_REPLACE_STRING1 " "
#define REPLACE_WITH_STRING "_"
#define FUNCTION_LOG() (qDebug()<<"Function name: "<<__FUNCTION__ <<endl)

//define status
#define SLEEPING_STATUS "Sleeping"
#define NOT_SLEEPING_STATUS "Not sleeping"
#define YAWNING_MOUTH_STATUS "Yawning mouth"
#define NOT_YAWNING_MOUTH_STATUS "Not yawning mouth"
#define HEADING_PHONE_STATUS "Heading phone"
#define NOT_HEADING_PHONE_STATUS "Not heading phone"
#define HAND_DETECTING_STATUS "Detecting hand"
#define NOT_HAND_DETECT_STATUS "Not detect hand"

#endif // GLOBALFILE_H
