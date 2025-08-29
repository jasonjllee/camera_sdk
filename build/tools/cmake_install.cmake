# Install script for directory: D:/3D_SDK/camera_sdk/tools

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/3D_SDK/camera_sdk/build/release")
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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/3D_SDK/camera_sdk/build/tools/convert/cmake_install.cmake")
  include("D:/3D_SDK/camera_sdk/build/tools/enumerate-devices/cmake_install.cmake")
  include("D:/3D_SDK/camera_sdk/build/tools/fw-logger/cmake_install.cmake")
  include("D:/3D_SDK/camera_sdk/build/tools/terminal/cmake_install.cmake")
  include("D:/3D_SDK/camera_sdk/build/tools/recorder/cmake_install.cmake")
  include("D:/3D_SDK/camera_sdk/build/tools/fw-update/cmake_install.cmake")
  include("D:/3D_SDK/camera_sdk/build/tools/embed/cmake_install.cmake")
  include("D:/3D_SDK/camera_sdk/build/tools/data-collect/cmake_install.cmake")
  include("D:/3D_SDK/camera_sdk/build/tools/realsense-viewer/cmake_install.cmake")
  include("D:/3D_SDK/camera_sdk/build/tools/depth-quality/cmake_install.cmake")
  include("D:/3D_SDK/camera_sdk/build/tools/rosbag-inspector/cmake_install.cmake")
  include("D:/3D_SDK/camera_sdk/build/tools/benchmark/cmake_install.cmake")

endif()

