# Install script for directory: E:/GitProiects/DoANTotNghiep/opencv/sources

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlicensesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/etc/licenses" TYPE FILE RENAME "opencl-headers-LICENSE.txt" FILES "E:/GitProiects/DoANTotNghiep/opencv/sources/3rdparty/include/opencl/LICENSE.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2" TYPE FILE FILES "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/cvconfig.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2" TYPE FILE FILES "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/opencv2/opencv_modules.hpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/x64/mingw/lib/OpenCVModules.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/x64/mingw/lib/OpenCVModules.cmake"
         "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/CMakeFiles/Export/x64/mingw/lib/OpenCVModules.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/x64/mingw/lib/OpenCVModules-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/x64/mingw/lib/OpenCVModules.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x64/mingw/lib" TYPE FILE FILES "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/CMakeFiles/Export/x64/mingw/lib/OpenCVModules.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x64/mingw/lib" TYPE FILE FILES "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/CMakeFiles/Export/x64/mingw/lib/OpenCVModules-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x64/mingw/lib" TYPE FILE FILES
    "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/win-install/OpenCVConfig-version.cmake"
    "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/win-install/x64/mingw/lib/OpenCVConfig.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES
    "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/win-install/OpenCVConfig-version.cmake"
    "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/win-install/OpenCVConfig.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibsx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES "E:/GitProiects/DoANTotNghiep/opencv/sources/LICENSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xscriptsx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/CMakeFiles/install/setup_vars_opencv4.cmd")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/3rdparty/zlib/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/3rdparty/libjpeg-turbo/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/3rdparty/libtiff/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/3rdparty/libwebp/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/3rdparty/libjasper/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/3rdparty/libpng/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/3rdparty/openexr/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/3rdparty/protobuf/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/3rdparty/quirc/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/include/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/modules/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/doc/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/data/cmake_install.cmake")
  include("E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/apps/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "E:/GitProiects/DoANTotNghiep/opencv/build_Mingw32/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
