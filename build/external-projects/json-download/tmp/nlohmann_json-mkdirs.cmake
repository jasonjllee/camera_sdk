# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/3D_SDK/camera_sdk/build/external-projects/json-download/src/nlohmann_json"
  "D:/3D_SDK/camera_sdk/build/external-projects/json-download/src/nlohmann_json-build"
  "D:/3D_SDK/camera_sdk/build/external-projects/json-download"
  "D:/3D_SDK/camera_sdk/build/external-projects/json-download/tmp"
  "D:/3D_SDK/camera_sdk/build/external-projects/json-download/src/nlohmann_json-stamp"
  "D:/3D_SDK/camera_sdk/build/third-party"
  "D:/3D_SDK/camera_sdk/build/external-projects/json-download/src/nlohmann_json-stamp"
)

set(configSubDirs Debug;Release;MinSizeRel;RelWithDebInfo)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/3D_SDK/camera_sdk/build/external-projects/json-download/src/nlohmann_json-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/3D_SDK/camera_sdk/build/external-projects/json-download/src/nlohmann_json-stamp${cfgdir}") # cfgdir has leading slash
endif()
