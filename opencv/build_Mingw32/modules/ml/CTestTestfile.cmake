# CMake generated Testfile for 
# Source directory: E:/GitProiects/DoANTotNghiep/opencv/sources/modules/ml
# Build directory: E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/modules/ml
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_ml "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/bin/opencv_test_ml.exe" "--gtest_output=xml:opencv_test_ml.xml")
set_tests_properties(opencv_test_ml PROPERTIES  LABELS "Main;opencv_ml;Accuracy" WORKING_DIRECTORY "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/test-reports/accuracy" _BACKTRACE_TRIPLES "E:/GitProiects/DoANTotNghiep/opencv/sources/cmake/OpenCVUtils.cmake;1640;add_test;E:/GitProiects/DoANTotNghiep/opencv/sources/cmake/OpenCVModule.cmake;1309;ocv_add_test_from_target;E:/GitProiects/DoANTotNghiep/opencv/sources/cmake/OpenCVModule.cmake;1073;ocv_add_accuracy_tests;E:/GitProiects/DoANTotNghiep/opencv/sources/modules/ml/CMakeLists.txt;2;ocv_define_module;E:/GitProiects/DoANTotNghiep/opencv/sources/modules/ml/CMakeLists.txt;0;")
