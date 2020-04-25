TEMPLATE += app

QT += widgets \
      charts \
      multimedia

CONFIG += c++11

TARGET = handDetection

win32{
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

INCLUDEPATH += $$PWD/inc/

DEFINES *= QT_USE_QSTRINGBUILDER

HEADERS += \
    inc/camProcess.h \
    inc/camWidget.h \
    inc/global.h \
    inc/kernels.h

SOURCES += \
    src/camProcess.cpp \
    src/camWidget.cpp \
    src/main.cpp
