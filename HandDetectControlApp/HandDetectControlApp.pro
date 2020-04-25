QT += core charts qml widgets gui quick multimedia websockets concurrent network multimediawidgets

CONFIG += c++11
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#ICON = resources/icon.png
#macos: ICON = resources/photosurface.icns
#win32: RC_FILE = resources/photosurface.rc
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CMAKE_INSTALL_PREFIX = $$PWD/dlib/
DEFINES += DLIB_ENABLE_ASSERTS
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        AIandDetectLayer/camProcess.cpp \
        AIandDetectLayer/camWidget.cpp \
        AIandDetectLayer/cameramanager.cpp \
        UserControlLayer/AppTrainer/photosurface.cpp \
        UserControlLayer/MouseController.cpp \
        UserControlLayer/PeopleDetectManager.cpp \
        ConnectLayer/VTIUtility.cpp \
        ConnectLayer/appengine.cpp \
        dlib/dlib/all/source.cpp \
        main.cpp

RESOURCES += qml.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
HEADERS += \
    AIandDetectLayer/camProcess.h \
    AIandDetectLayer/camWidget.h \
    AIandDetectLayer/cameramanager.h \
    AIandDetectLayer/global.h \
    AIandDetectLayer/kernels.h \
    ConnectLayer/ConstDefines.h \
    ConnectLayer/GlobalTypes.h \
    ConnectLayer/StringDefines.h \
    UserControlLayer/AppTrainer/photosurface.h \
    UserControlLayer/MouseController.h \
    UserControlLayer/PeopleDetectManager.h \
    ConnectLayer/VTIUtility.h \
    ConnectLayer/appengine.h \

win32{
#include path for dlib c++
INCLUDEPATH += $$PWD/AIandDetectLayer
INCLUDEPATH += $$PWD/dlib
LIBS+= -lgdi32 -lcomctl32 -luser32 -lwinmm -lws2_32
LIBS += -luser32 -lws2_32 -lgdi32 -lcomctl32 -limm32 -lwinmm
DEPENDPATH += "$$PWD/dlib"

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

linux-g++-64{

}
