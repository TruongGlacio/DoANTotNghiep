QT += quick

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
        ../Driving/DriverMonitor/DriverMonitor.cpp \
        ../Driving/DrivingDetect/main.cpp \
        ../Driving/forwarder/ExecuteForwarder.cpp \
        ../Driving/forwarder/ExecuteResultProcessor.cpp \
        ../Driving/forwarder/ExecuteSensorDataServer.cpp \
        ../Driving/forwarder/Forwarder.cpp \
        ../Driving/forwarder/ResultProcessor.cpp \
        ../Driving/forwarder/SensorDataServer.cpp \
        ../Driving/forwarder/TestResultProcessor.cpp \
        ../Driving/src/3000fps/LBFRegressor.cpp \
        ../Driving/src/3000fps/RandomForest.cpp \
        ../Driving/src/3000fps/Tree.cpp \
        ../Driving/src/3000fps/Utils.cpp \
        ../Driving/src/3000fps/build/CMakeFiles/2.8.12.2/CompilerIdC/CMakeCCompilerId.c \
        ../Driving/src/3000fps/build/CMakeFiles/2.8.12.2/CompilerIdCXX/CMakeCXXCompilerId.cpp \
        ../Driving/src/3000fps/liblinear/blas/daxpy.c \
        ../Driving/src/3000fps/liblinear/blas/ddot.c \
        ../Driving/src/3000fps/liblinear/blas/dnrm2.c \
        ../Driving/src/3000fps/liblinear/blas/dscal.c \
        ../Driving/src/3000fps/liblinear/linear.cpp \
        ../Driving/src/3000fps/liblinear/tron.cpp \
        ../Driving/src/CaffeClassifier/CaffeClassifier.cpp \
        ../Driving/src/dm/dm_global.cpp \
        ../Driving/src/fdd_lib/Camera.cpp \
        ../Driving/src/fdd_lib/FDDGlobal.cpp \
        ../Driving/src/fdd_lib/Face.cpp \
        ../Driving/src/fdd_lib/FaceAnalysisModel.cpp \
        ../Driving/src/fdd_lib/FaceComponent.cpp \
        ../Driving/src/fdd_lib/FatigueDetectionFrameSequenceProcessor.cpp \
        ../Driving/src/fdd_lib/Frame.cpp \
        ../Driving/src/fdd_lib/FrameSequenceProcessor.cpp \
        ../Driving/src/fdd_lib/LeftEye.cpp \
        ../Driving/src/fdd_lib/Mouth.cpp \
        ../Driving/src/fdd_lib/ResourceManagers.cpp \
        ../Driving/src/fdd_lib/RightEye.cpp \
        ../Driving/src/forwarder_lib/Exception.cpp \
        ../Driving/src/forwarder_lib/MessageQueue.cpp \
        ../Driving/src/forwarder_lib/Socket.cpp \
        ../Driving/src/forwarder_lib/TCPSocket.cpp \
        ../Driving/src/forwarder_lib/build/CMakeFiles/2.8.12.2/CompilerIdC/CMakeCCompilerId.c \
        ../Driving/src/forwarder_lib/build/CMakeFiles/2.8.12.2/CompilerIdCXX/CMakeCXXCompilerId.cpp \
        ../Driving/tools/CutOutFaceComponents/CutOutFaceComponents.cpp \
        ../Driving/tools/DrawRects/DrawRects.cpp \
        ../Driving/tools/GenerateGrayImages/GenerateGrayImages.cpp \
        ../Driving/tools/LBF_demo/Facedetect.cpp \
        ../Driving/tools/LBF_demo/LBF_demo.cpp \
        ../Driving/tools/LBF_demo/TestModel.cpp \
        ../Driving/tools/LBF_demo/TrainModel.cpp \
        ../Driving/tools/MakeHeadposeDataset/MakeHeadposeDataset.cpp \
        ../Driving/tools/SplitImage/SplitImage.cpp \
        ../Driving/tools/TestFunc/TestFunc.cpp \
        ../Driving/tools/TestHeadposeModel/CaffeClassifier.cpp \
        ../Driving/tools/TestHeadposeModel/TestHeadposeModel.cpp \
        main.cpp

RESOURCES += qml.qrc \
    ../Driving/DrivingDetect/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../Driving/CMakeLists.txt \
    ../Driving/DriverMonitor/CMakeLists.txt \
    ../Driving/DrivingDetect/.gitignore \
    ../Driving/DrivingDetect/main.qml \
    ../Driving/LICENSE \
    ../Driving/README.md \
    ../Driving/VERSION \
    ../Driving/configures/DriverMonitorGlobalVariables.cfg \
    ../Driving/forwarder/CMakeLists.txt \
    ../Driving/model/G_left_eye_20171109_snapshot_iter_20000.caffemodel \
    ../Driving/model/G_left_eye_20171219_mean.binaryproto \
    ../Driving/model/G_left_eye_20171219_quick.prototxt \
    ../Driving/model/G_left_eye_20171219_snapshot_iter_350000.caffemodel \
    ../Driving/model/G_left_eye_20171219_snapshot_iter_550000.caffemodel \
    ../Driving/model/G_left_eye_mean_20171109.binaryproto \
    ../Driving/model/G_left_eye_quick.prototxt \
    ../Driving/model/G_mouth_20171109_snapshot_iter_20000.caffemodel \
    ../Driving/model/G_mouth_20171219_mean.binaryproto \
    ../Driving/model/G_mouth_20171219_quick.prototxt \
    ../Driving/model/G_mouth_20171219_snapshot_iter_350000.caffemodel \
    ../Driving/model/G_mouth_20171219_snapshot_iter_550000.caffemodel \
    ../Driving/model/G_mouth_mean_20171109.binaryproto \
    ../Driving/model/G_mouth_quick.prototxt \
    ../Driving/model/G_right_eye_20171109_snapshot_iter_20000.caffemodel \
    ../Driving/model/G_right_eye_20171219_mean.binaryproto \
    ../Driving/model/G_right_eye_20171219_quick.prototxt \
    ../Driving/model/G_right_eye_20171219_snapshot_iter_350000.caffemodel \
    ../Driving/model/G_right_eye_20171219_snapshot_iter_550000.caffemodel \
    ../Driving/model/G_right_eye_mean_20171109.binaryproto \
    ../Driving/model/G_right_eye_quick.prototxt \
    ../Driving/model/LBF.model \
    ../Driving/model/Regressor.model \
    ../Driving/model/faceComponentLabels.txt \
    ../Driving/model/haarcascade_frontalface_alt.xml \
    ../Driving/model/haarcascade_profileface.xml \
    ../Driving/model/headposeLabels.txt \
    ../Driving/model/headpose_20171124_snapshot_iter_20000.caffemodel \
    ../Driving/model/headpose_20171124_snapshot_iter_6000.caffemodel \
    ../Driving/model/headpose_mean.binaryproto \
    ../Driving/model/headpose_quick.prototxt \
    ../Driving/model/headpose_snapshot_iter_6000.caffemodel \
    ../Driving/model/left_eye_20171109_snapshot_iter_20000.caffemodel \
    ../Driving/model/left_eye_mean.binaryproto \
    ../Driving/model/left_eye_mean_20171109.binaryproto \
    ../Driving/model/left_eye_quick.prototxt \
    ../Driving/model/left_eye_snapshot_iter_4000.caffemodel \
    ../Driving/model/left_eye_snapshot_iter_6000.caffemodel \
    ../Driving/model/mouth_20171109_snapshot_iter_20000.caffemodel \
    ../Driving/model/mouth_mean.binaryproto \
    ../Driving/model/mouth_mean_20171109.binaryproto \
    ../Driving/model/mouth_quick.prototxt \
    ../Driving/model/mouth_snapshot_iter_4000.caffemodel \
    ../Driving/model/right_eye_20171109_snapshot_iter_20000.caffemodel \
    ../Driving/model/right_eye_mean_20171109.binaryproto \
    ../Driving/model/right_eye_quick.prototxt \
    ../Driving/scripts/getImgPath.sh \
    ../Driving/scripts/getImgPathWithLabel.sh \
    ../Driving/src/3000fps/3000fpsConfig.cmake \
    ../Driving/src/3000fps/CMakeLists.txt \
    ../Driving/src/3000fps/build/CMakeCache.txt \
    ../Driving/src/3000fps/build/CMakeFiles/2.8.12.2/CMakeCCompiler.cmake \
    ../Driving/src/3000fps/build/CMakeFiles/2.8.12.2/CMakeCXXCompiler.cmake \
    ../Driving/src/3000fps/build/CMakeFiles/2.8.12.2/CMakeDetermineCompilerABI_C.bin \
    ../Driving/src/3000fps/build/CMakeFiles/2.8.12.2/CMakeDetermineCompilerABI_CXX.bin \
    ../Driving/src/3000fps/build/CMakeFiles/2.8.12.2/CMakeSystem.cmake \
    ../Driving/src/3000fps/build/CMakeFiles/2.8.12.2/CompilerIdC/a.out \
    ../Driving/src/3000fps/build/CMakeFiles/2.8.12.2/CompilerIdCXX/a.out \
    ../Driving/src/3000fps/build/CMakeFiles/3000fps.dir/CXX.includecache \
    ../Driving/src/3000fps/build/CMakeFiles/3000fps.dir/DependInfo.cmake \
    ../Driving/src/3000fps/build/CMakeFiles/3000fps.dir/build.make \
    ../Driving/src/3000fps/build/CMakeFiles/3000fps.dir/cmake_clean.cmake \
    ../Driving/src/3000fps/build/CMakeFiles/3000fps.dir/cmake_clean_target.cmake \
    ../Driving/src/3000fps/build/CMakeFiles/3000fps.dir/depend.internal \
    ../Driving/src/3000fps/build/CMakeFiles/3000fps.dir/depend.make \
    ../Driving/src/3000fps/build/CMakeFiles/3000fps.dir/flags.make \
    ../Driving/src/3000fps/build/CMakeFiles/3000fps.dir/link.txt \
    ../Driving/src/3000fps/build/CMakeFiles/3000fps.dir/progress.make \
    ../Driving/src/3000fps/build/CMakeFiles/CMakeDirectoryInformation.cmake \
    ../Driving/src/3000fps/build/CMakeFiles/CMakeOutput.log \
    ../Driving/src/3000fps/build/CMakeFiles/Export/share/3000fps-noconfig.cmake \
    ../Driving/src/3000fps/build/CMakeFiles/Export/share/3000fps.cmake \
    ../Driving/src/3000fps/build/CMakeFiles/TargetDirectories.txt \
    ../Driving/src/3000fps/build/CMakeFiles/cmake.check_cache \
    ../Driving/src/3000fps/build/CMakeFiles/progress.marks \
    ../Driving/src/3000fps/build/cmake_install.cmake \
    ../Driving/src/3000fps/build/install_manifest.txt \
    ../Driving/src/3000fps/build/lib3000fps.a \
    ../Driving/src/3000fps/build/liblinear/CMakeFiles/CMakeDirectoryInformation.cmake \
    ../Driving/src/3000fps/build/liblinear/CMakeFiles/liblinear.dir/CXX.includecache \
    ../Driving/src/3000fps/build/liblinear/CMakeFiles/liblinear.dir/DependInfo.cmake \
    ../Driving/src/3000fps/build/liblinear/CMakeFiles/liblinear.dir/build.make \
    ../Driving/src/3000fps/build/liblinear/CMakeFiles/liblinear.dir/cmake_clean.cmake \
    ../Driving/src/3000fps/build/liblinear/CMakeFiles/liblinear.dir/cmake_clean_target.cmake \
    ../Driving/src/3000fps/build/liblinear/CMakeFiles/liblinear.dir/depend.internal \
    ../Driving/src/3000fps/build/liblinear/CMakeFiles/liblinear.dir/depend.make \
    ../Driving/src/3000fps/build/liblinear/CMakeFiles/liblinear.dir/flags.make \
    ../Driving/src/3000fps/build/liblinear/CMakeFiles/liblinear.dir/link.txt \
    ../Driving/src/3000fps/build/liblinear/CMakeFiles/liblinear.dir/progress.make \
    ../Driving/src/3000fps/build/liblinear/CMakeFiles/progress.marks \
    ../Driving/src/3000fps/build/liblinear/blas/CMakeFiles/CMakeDirectoryInformation.cmake \
    ../Driving/src/3000fps/build/liblinear/blas/CMakeFiles/blas.dir/C.includecache \
    ../Driving/src/3000fps/build/liblinear/blas/CMakeFiles/blas.dir/DependInfo.cmake \
    ../Driving/src/3000fps/build/liblinear/blas/CMakeFiles/blas.dir/build.make \
    ../Driving/src/3000fps/build/liblinear/blas/CMakeFiles/blas.dir/cmake_clean.cmake \
    ../Driving/src/3000fps/build/liblinear/blas/CMakeFiles/blas.dir/cmake_clean_target.cmake \
    ../Driving/src/3000fps/build/liblinear/blas/CMakeFiles/blas.dir/depend.internal \
    ../Driving/src/3000fps/build/liblinear/blas/CMakeFiles/blas.dir/depend.make \
    ../Driving/src/3000fps/build/liblinear/blas/CMakeFiles/blas.dir/flags.make \
    ../Driving/src/3000fps/build/liblinear/blas/CMakeFiles/blas.dir/link.txt \
    ../Driving/src/3000fps/build/liblinear/blas/CMakeFiles/blas.dir/progress.make \
    ../Driving/src/3000fps/build/liblinear/blas/CMakeFiles/progress.marks \
    ../Driving/src/3000fps/build/liblinear/blas/cmake_install.cmake \
    ../Driving/src/3000fps/build/liblinear/blas/libblas.a \
    ../Driving/src/3000fps/build/liblinear/cmake_install.cmake \
    ../Driving/src/3000fps/build/liblinear/libliblinear.a \
    ../Driving/src/3000fps/liblinear/CMakeLists.txt \
    ../Driving/src/3000fps/liblinear/blas/CMakeLists.txt \
    ../Driving/src/CaffeClassifier/CMakeLists.txt \
    ../Driving/src/dm/CMakeLists.txt \
    ../Driving/src/fdd_lib/CMakeLists.txt \
    ../Driving/src/forwarder_lib/CMakeLists.txt \
    ../Driving/src/forwarder_lib/build/CMakeCache.txt \
    ../Driving/src/forwarder_lib/build/CMakeFiles/2.8.12.2/CMakeCCompiler.cmake \
    ../Driving/src/forwarder_lib/build/CMakeFiles/2.8.12.2/CMakeCXXCompiler.cmake \
    ../Driving/src/forwarder_lib/build/CMakeFiles/2.8.12.2/CMakeDetermineCompilerABI_C.bin \
    ../Driving/src/forwarder_lib/build/CMakeFiles/2.8.12.2/CMakeDetermineCompilerABI_CXX.bin \
    ../Driving/src/forwarder_lib/build/CMakeFiles/2.8.12.2/CMakeSystem.cmake \
    ../Driving/src/forwarder_lib/build/CMakeFiles/2.8.12.2/CompilerIdC/a.out \
    ../Driving/src/forwarder_lib/build/CMakeFiles/2.8.12.2/CompilerIdCXX/a.out \
    ../Driving/src/forwarder_lib/build/CMakeFiles/CMakeDirectoryInformation.cmake \
    ../Driving/src/forwarder_lib/build/CMakeFiles/CMakeOutput.log \
    ../Driving/src/forwarder_lib/build/CMakeFiles/MessageQueue.dir/CXX.includecache \
    ../Driving/src/forwarder_lib/build/CMakeFiles/MessageQueue.dir/DependInfo.cmake \
    ../Driving/src/forwarder_lib/build/CMakeFiles/MessageQueue.dir/build.make \
    ../Driving/src/forwarder_lib/build/CMakeFiles/MessageQueue.dir/cmake_clean.cmake \
    ../Driving/src/forwarder_lib/build/CMakeFiles/MessageQueue.dir/cmake_clean_target.cmake \
    ../Driving/src/forwarder_lib/build/CMakeFiles/MessageQueue.dir/depend.internal \
    ../Driving/src/forwarder_lib/build/CMakeFiles/MessageQueue.dir/depend.make \
    ../Driving/src/forwarder_lib/build/CMakeFiles/MessageQueue.dir/flags.make \
    ../Driving/src/forwarder_lib/build/CMakeFiles/MessageQueue.dir/link.txt \
    ../Driving/src/forwarder_lib/build/CMakeFiles/MessageQueue.dir/progress.make \
    ../Driving/src/forwarder_lib/build/CMakeFiles/TargetDirectories.txt \
    ../Driving/src/forwarder_lib/build/CMakeFiles/cmake.check_cache \
    ../Driving/src/forwarder_lib/build/CMakeFiles/progress.marks \
    ../Driving/src/forwarder_lib/build/cmake_install.cmake \
    ../Driving/src/forwarder_lib/build/install_manifest.txt \
    ../Driving/src/forwarder_lib/build/libMessageQueue.a \
    ../Driving/tools/CutOutFaceComponents/CMakeLists.txt \
    ../Driving/tools/DrawRects/20171215172144.png \
    ../Driving/tools/DrawRects/20171215172158.jpg \
    ../Driving/tools/DrawRects/20171215172209.jpg \
    ../Driving/tools/DrawRects/20171215172218.jpg \
    ../Driving/tools/DrawRects/CMakeLists.txt \
    ../Driving/tools/DrawRects/r_20171215172158.jpg \
    ../Driving/tools/GenerateGrayImages/CMakeLists.txt \
    ../Driving/tools/LBF_demo/CMakeLists.txt \
    ../Driving/tools/MakeHeadposeDataset/CMakeLists.txt \
    ../Driving/tools/MakeHeadposeDataset/getImgPathWithLabel.sh \
    ../Driving/tools/MakeHeadposeDataset/imgPaths.txt \
    ../Driving/tools/MakeHeadposeDataset/imgPathsWithLabel.txt \
    ../Driving/tools/MakeHeadposeDataset/run.sh \
    ../Driving/tools/MakeHeadposeDataset/test.txt \
    ../Driving/tools/MakeHeadposeDataset/tree.txt \
    ../Driving/tools/SplitImage/CMakeLists.txt \
    ../Driving/tools/SplitImage/closed_eye_0003.jpg_face_2.jpg \
    ../Driving/tools/SplitImage/closed_eye_0014.jpg_face_2.jpg \
    ../Driving/tools/SplitImage/lenna.jpeg \
    ../Driving/tools/TestFunc/CMakeLists.txt \
    ../Driving/tools/TestHeadposeModel/CMakeLists.txt \
    ../Driving/tools/TestHeadposeModel/getImgPath.sh \
    ../Driving/tools/TestHeadposeModel/imgPaths.txt \
    ../Driving/tools/TestHeadposeModel/test.txt \
    ../Driving/wav/distraction.wav \
    ../Driving/wav/frequentyawn.wav \
    ../Driving/wav/sleepy.wav \
    ../Driving/wav/yawn.wav

SUBDIRS += \
    ../Driving/DrivingDetect/DrivingDetect.pro

HEADERS += \
    ../Driving/forwarder/Forwarder.h \
    ../Driving/forwarder/ResultProcessor.h \
    ../Driving/forwarder/SensorDataServer.h \
    ../Driving/include/3000fps/LBF.h \
    ../Driving/include/3000fps/LBFRegressor.h \
    ../Driving/include/3000fps/RandomForest.h \
    ../Driving/include/3000fps/Tree.h \
    ../Driving/include/3000fps/liblinear/blas/blas.h \
    ../Driving/include/3000fps/liblinear/blas/blasp.h \
    ../Driving/include/3000fps/liblinear/linear.h \
    ../Driving/include/3000fps/liblinear/tron.h \
    ../Driving/include/CaffeClassifier/CaffeClassifier.h \
    ../Driving/include/CaffeClassifier/caffe_layers_registry.hpp \
    ../Driving/include/dm/dm_global.h \
    ../Driving/include/fdd_lib/Camera.h \
    ../Driving/include/fdd_lib/FDDGlobal.h \
    ../Driving/include/fdd_lib/Face.h \
    ../Driving/include/fdd_lib/FaceAnalysisModel.h \
    ../Driving/include/fdd_lib/FaceComponent.h \
    ../Driving/include/fdd_lib/FatigueDetectionFrameSequenceProcessor.h \
    ../Driving/include/fdd_lib/Frame.h \
    ../Driving/include/fdd_lib/FrameSequenceProcessor.h \
    ../Driving/include/fdd_lib/LeftEye.h \
    ../Driving/include/fdd_lib/Mouth.h \
    ../Driving/include/fdd_lib/ResourceManagers.h \
    ../Driving/include/fdd_lib/RightEye.h \
    ../Driving/include/forwarder_lib/Exception.h \
    ../Driving/include/forwarder_lib/MessageQueue.h \
    ../Driving/include/forwarder_lib/Socket.h \
    ../Driving/include/forwarder_lib/TCPSocket.h \
    ../Driving/tools/LBF_demo/LBF_demo.h \
    ../Driving/tools/TestHeadposeModel/CaffeClassifier.h \
    ../Driving/tools/TestHeadposeModel/caffe_layers_registry.hpp
