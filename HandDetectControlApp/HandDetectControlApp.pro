QT += core widgets gui quick multimedia websockets concurrent network

CONFIG += c++11
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        MouseController.cpp \
        PeopleDetectManager.cpp \
        VTIUtility.cpp \
        appengine.cpp \
        trainingobjectdetect.cpp \
        #video_tracking.cpp
        main.cpp

RESOURCES += qml.qrc

#PKGCONFIG += dlib-1
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ConstDefines.h \
    GlobalTypes.h \
    MouseController.h \
    PeopleDetectManager.h \
    StringDefines.h \
    VTIUtility.h \
    appengine.h \
    trainingobjectdetect.h \
    #video_tracking.h

#QMAKE_CXXFLAGS_RELEASE += -mavx
INCLUDEPATH+=D:/Projects/GitProjects/DoAnTotNghiep/DoANTotNghiep/HandDetectControlApp/dlib/include
#INCLUDEPATH+=D:\Projects\GitProjects\DoAnTotNghiep\DoANTotNghiep\HandDetectControlApp\dlib\lib
#INCLUDEPATH+=D:\Projects\GitProjects\DoAnTotNghiep\DoANTotNghiep\HandDetectControlApp\dlib\lib\Release
#INCLUDEPATH+= C:/Program Files (x86)/GnuWin32/src/giflib
#LIBS +=-L"D:\Projects\GitProjects\DoAnTotNghiep\DoANTotNghiep\HandDetectControlApp\dlib\lib\Release"
LIBS+=-L"D:\Projects\GitProjects\DoAnTotNghiep\DoANTotNghiep\HandDetectControlApp\dlib\lib"
LIBS+=-llibdlib
LIBS += -lmingw32
#LIBS+=-lOle32
#LIBS+=-lOleaut32
#LIBS+=-lm
#LIBS+= -ldinput8
#LIBS+=-lcomctl32

#LIBS+=-ldxguid
#LIBS+= -ldxerr8
#LIBS+=-luser32
#LIBS+=-lgdi32
#LIBS+=-lwinmm
#LIBS+= -limm32
#LIBS+= -lole32
#LIBS+=-loleaut32
#LIBS+=-lshell32
#LIBS+= -lversion
#LIBS+= -luuid

#LIBS+=-lglut32
#LIBS+=-lopengl32
#LIBS+=-lglu32
#LIBS+=-lgdi32
#LIBS+=-lwinmm
#LIBS += -lws2_32
