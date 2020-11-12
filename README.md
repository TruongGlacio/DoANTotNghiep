# DoANTotNghiep
I. Steps for build project with dlib
1. add file source.cpp from dlib/dlib/all/source.cpp of dlib to project
2. add to .pro file : 
win32{
INCLUDEPATH += $$PWD/dlib
LIBS+= -lgdi32 -lcomctl32 -luser32 -lwinmm -lws2_32
LIBS += -luser32 -lws2_32 -lgdi32 -lcomctl32 -limm32 -lwinmm
DEPENDPATH += "$$PWD/dlib"
}
3. build project and start using dlib



II. Install package on linux
sudo apt-get install mingw-w64 gcc-mingw-w64

Download and install qt5.14 less than, Cmake Gui for build opencv...
 

III. Readme for build and install opencv lib:

1. unzip opencv zip file: 

-In Zip 3.0 version the following commands: 
Put all your zip files in the same directory: zip_file.z01, zip_file.z02, zip_file.z03, ..., zip_file.zip

-run command:
$ zip -s- opencv.zip -O zip_file_full.zip
$ unzip zip_file_full.zip

2. build opencv with commands: 
cd opencv
mkdir build
cd build 
cmake -G "Unix makefile" ../source
cmake --build . --target install --config Release
sudo make install
copy folder opencv4 from /usr/local/opencv4 to fle opencv/build_Linux if it not exit


