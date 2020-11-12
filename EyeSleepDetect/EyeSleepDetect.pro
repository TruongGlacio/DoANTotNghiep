QT += core widgets gui quick multimedia websockets concurrent network

CONFIG += c++11 release


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
CMAKE_INSTALL_PREFIX = $$PWD/../dlib/
DEFINES += DLIB_ENABLE_ASSERTS
DEFINES += QT_DEPRECATED_WARNINGS

#DEFINES += DLIB_JPEG_SUPPORT
#DEFINES += DLIB_JPEG_STATIC
#DEFINES += NEED_SHORT_EXTERNAL_NAMES

LIBS += -pthread
QMAKE_CXXFLAGS += -std=c++11 -DDLIB_ENABLE_ASSERTS #-DDLIB_JPEG_SUPPORT -DNEED_SHORT_EXTERNAL_NAMES -DDLIB_JPEG_STATIC #-DHAVE_PROTOTYPES
SOURCES += \
        ../dlib/dlib/all/source.cpp \
    FacesDetectClass.cpp \
    appenginer.cpp \
    cameramanager.cpp \
    handDetectClass.cpp \
    train_shape_predictor.cpp\
    main.cpp \

HEADERS += \
    FacesDetectClass.h \
    GlobalFile.h \
    GlobalLib.h \
    appenginer.h \
    cameramanager.h \ \
    handDetectClass.h \
    train_shape_predictor.h\

RESOURCES += qml.qrc \

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32{
#include path for dlib c++
INCLUDEPATH += $$PWD/../dlib/
#QMAKE_CXXFLAGS_RELEASE += /arch:AVX
QMAKE_CXXFLAGS_RELEASE += -mavx
QMAKE_CXXFLAGS_DEBUG += -mavx

LIBS+= -lgdi32 -lcomctl32 -luser32 -lwinmm -lws2_32
LIBS += -luser32 -lws2_32 -lgdi32 -lcomctl32 -limm32 -lwinmm

DEPENDPATH += "$$PWD/../dlib"
# include path and lib for opencv
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


linux{
INCLUDEPATH += $$PWD/../dlib/
#QMAKE_CXXFLAGS_RELEASE += /arch:AVX
#LIBS+= -lgdi32 -lcomctl32 -luser32 -lwinmm -lws2_32
#LIBS += -luser32 -lws2_32 -lgdi32 -lcomctl32 -limm32 -lwinmm

LIBS += -pthread
CONFIG += link_pkgconfig
PKGCONFIG += x11

#apply for linux system

#install qt creator by :
#sudo apt-get install qtcreator
#sudo apt install qml-module-qtquick-controls2

#build and install opencv by :
#cmake -G "Unix makefile" ..
#cmake --build . --target install --config Release
#sudo make install
#copy folder opencv4 from /usr/local/opencv4 to fle opencv/build_Linux if it not exit
#sudo apt install qml-module-qtquick-controls2
#sudo apt-get install qml-module-qtmultimedia

# include path and lib for opencv

#INCLUDEPATH += $$PWD/../opencv/BuildMingw32_Ubuntu/include
INCLUDEPATH += $$PWD/../opencv/BuildMingw32_Ubuntu/opencv4

#INCLUDEPATH += $$PWD/../opencv/BuildMingw32_Ubuntu/lib
#DEPENDPATH += $$PWD/../opencv/BuildMingw32_Ubuntu/lib
INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include
LIBS += -L$$PWD/../opencv/BuildMingw32_Ubuntu/lib/
LIBS += -lopencv_calib3d -lopencv_core
LIBS += -lopencv_dnn -lopencv_features2d
LIBS += -lopencv_flann -lopencv_gapi -lopencv_highgui
LIBS += -lopencv_imgcodecs -lopencv_imgproc -lopencv_ml
LIBS += -lopencv_objdetect -lopencv_photo -lopencv_stitching
LIBS += -lopencv_video -lopencv_videoio


#LIBS += -L$$PWD/../opencv/BuildMingw32_Ubuntu/lib/
#LIBS += -llibopencv_calib3d -llibopencv_core
#LIBS += -llibopencv_dnn -llibopencv_features2d
#LIBS += -llibopencv_flann -llibopencv_gapi -llibopencv_highgui
#LIBS += -llibopencv_imgcodecs -llibopencv_imgproc -llibopencv_ml
#LIBS += -llibopencv_objdetect -llibopencv_photo -llibopencv_stitching
#LIBS += -llibopencv_video -llibopencv_videoio
#LIBS+=$(shell pkg-config opencv --lib)

}

#unix:!macx: LIBS += -L$$PWD/../opencv/BuildMingw32_Ubuntu/lib/ -lopencv_videoio


