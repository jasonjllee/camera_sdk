// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#pragma once

#include "ds/ds-private.h"
#include <src/platform/backend-device-group.h>
#include <src/core/notification.h>

namespace librealsense
{
    class gorilla_info;

    namespace ds
    {
        const uint16_t GORILLA_S01_PID = 0x0c01;

        // Gorilla Devices supported by the current version
        static const std::set<std::uint16_t> gorilla_sku_pid = {
            ds::GORILLA_S01_PID,
        };

        static const std::set<std::uint16_t> gorilla_multi_sensors_pid = {
            ds::GORILLA_S01_PID,
        };

        static const std::set<std::uint16_t> gorilla_hid_sensors_pid = {
        };

        static const std::map<std::uint16_t, std::string> gorilla_sku_names = {
            { GORILLA_S01_PID, "GORILLA S01"},
        };

        static std::map<uint16_t, std::string> gorilla_device_to_fw_min_version = {
            {GORILLA_S01_PID, "1.0.0.0"},
        };
    }
}
