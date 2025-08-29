// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#pragma once

#include "src/device-info.h"
#include <vector>
#include <string>
#include <memory>

namespace librealsense
{
    namespace platform {
        struct backend_device_group;
    }
    class context;

    namespace ds
    {
        const uint16_t GORIILA_S01_PID = 0xa100;
        const uint16_t GORIILA_VID = 0x30c9;

        const std::vector<uint16_t> goriila_sku_pid = { GORIILA_S01_PID };
    }

    class goriila_info : public device_info
    {
    public:
        std::shared_ptr<device_interface> create_device() override;

        goriila_info(std::shared_ptr<context> ctx,
                      std::vector<platform::uvc_device_info> uvc_devices)
            : device_info(ctx, std::move(uvc_devices), {}, {}) {}

        static std::vector<std::shared_ptr<goriila_info>> pick_goriila_devices(
            std::shared_ptr<context> ctx,
            platform::backend_device_group& group);
    };
}
