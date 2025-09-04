# License: Apache 2.0. See LICENSE file in root directory.
# Copyright(c) 2024 Intel Corporation. All Rights Reserved.
target_sources(${LRS_TARGET}
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/gorilla-device.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/gorilla-color.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/gorilla-s01-device.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/gorilla-factory.cpp"
)
