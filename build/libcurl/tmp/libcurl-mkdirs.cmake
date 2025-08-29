# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/3D_SDK/camera_sdk/build/third-party/libcurl"
  "D:/3D_SDK/camera_sdk/build/libcurl/src/libcurl-build"
  "D:/3D_SDK/camera_sdk/build/libcurl"
  "D:/3D_SDK/camera_sdk/build/libcurl/tmp"
  "D:/3D_SDK/camera_sdk/build/libcurl/src/libcurl-stamp"
  "D:/3D_SDK/camera_sdk/build/libcurl/src"
  "D:/3D_SDK/camera_sdk/build/libcurl/src/libcurl-stamp"
)

set(configSubDirs Debug;Release;MinSizeRel;RelWithDebInfo)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/3D_SDK/camera_sdk/build/libcurl/src/libcurl-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/3D_SDK/camera_sdk/build/libcurl/src/libcurl-stamp${cfgdir}") # cfgdir has leading slash
endif()
