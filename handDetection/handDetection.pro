TEMPLATE += app

QT += widgets \
      charts \
      multimedia

CONFIG += c++11

TARGET = handDetection

#INCLUDEPATH += C:\opencv\release\install\include
#LIBS += C:\opencv\release\bin\libopencv_core320.dll \
#        C:\opencv\release\bin\libopencv_videoio320.dll \
#        C:\opencv\release\bin\libopencv_imgproc320.dll \
#        C:\opencv\release\bin\libopencv_video320.dll

win32{
#INCLUDEPATH += $$PWD/../opencv/build_Mingw32#include#opencv/build_Mingw32/install/include#$$PWD/opencv/build/include
INCLUDEPATH += $$PWD/../opencv/build_Mingw32/install/include
DEPENDPATH += $$PWD/../opencv/build_Mingw32/install/include

LIBS +=  -L$$PWD/../opencv/build_Mingw32/install/x64/mingw/bin/
LIBS += -llibopencv_calib3d430 -llibopencv_core430
LIBS += -llibopencv_dnn430 -llibopencv_features2d430
LIBS += -llibopencv_flann430 -llibopencv_gapi430 -llibopencv_highgui430
LIBS +=-llibopencv_imgcodecs430 -llibopencv_imgproc430 -llibopencv_ml430
LIBS += -llibopencv_objdetect430 -llibopencv_photo430 -llibopencv_stitching430
LIBS += -llibopencv_video430 -llibopencv_videoio430

}

SOURCES += $$PWD/src/*.cpp \

HEADERS += $$PWD/inc/*.h \

INCLUDEPATH += $$PWD/inc/

DEFINES *= QT_USE_QSTRINGBUILDER
