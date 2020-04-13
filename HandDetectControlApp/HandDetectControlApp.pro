QT += core qml widgets gui quick multimedia websockets concurrent network multimediawidgets

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
        AIandDetectLayer/CameraManager/cameramanager.cpp \
        AIandDetectLayer/trainingobjectdetect.cpp \
        AIandDetectLayer/video_tracking.cpp \
        UserControlLayer/AppTrainer/photosurface.cpp \
        UserControlLayer/MouseController.cpp \
        UserControlLayer/PeopleDetectManager.cpp \
        VTIUtility.cpp \
        appengine.cpp \
        dlib/dlib/all/source.cpp \
        main.cpp

RESOURCES += qml.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
HEADERS += \
    AIandDetectLayer/CameraManager/cameramanager.h \
    AIandDetectLayer/trainingobjectdetect.h \
    AIandDetectLayer/video_tracking.h \
    ConstDefines.h \
    GlobalTypes.h \
    StringDefines.h \
    UserControlLayer/AppTrainer/photosurface.h \
    UserControlLayer/MouseController.h \
    UserControlLayer/PeopleDetectManager.h \
    VTIUtility.h \
    appengine.h \
#QMAKE_CXXFLAGS_RELEASE += -mavx

win32{
INCLUDEPATH += $$PWD/dlib
LIBS+= -lgdi32 -lcomctl32 -luser32 -lwinmm -lws2_32
LIBS += -luser32 -lws2_32 -lgdi32 -lcomctl32 -limm32 -lwinmm
DEPENDPATH += "$$PWD/dlib"
}

linux-g++-64{
   LIBS +=-L /usr/bin/openssl #-llibssl
   INCLUDEPATH +=  /usr/bin/openssl
   PKGCONFIG += openssl
}
