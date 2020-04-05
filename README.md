# DoANTotNghiep
Do an tot nghiep 20192_ Bui Xuan Truong
Steps for build project with dlib
1. add file source.cpp from dlib/dlib/all/source.cpp of dlib to project
2. add to .pro file : 
win32{
INCLUDEPATH += $$PWD/dlib
LIBS+= -lgdi32 -lcomctl32 -luser32 -lwinmm -lws2_32
LIBS += -luser32 -lws2_32 -lgdi32 -lcomctl32 -limm32 -lwinmm
DEPENDPATH += "$$PWD/dlib"
}
3. build project and start using dlib