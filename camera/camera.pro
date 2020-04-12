TEMPLATE = app
TARGET = camera

QT += multimedia multimediawidgets

HEADERS = \
    camera.h \

SOURCES = \
    main.cpp \
    camera.cpp \

FORMS += \
    camera.ui \

RESOURCES += camera.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/multimediawidgets/camera
INSTALLS += target

QT+=widgets
include(../../multimedia/shared/shared.pri)
