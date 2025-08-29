// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#pragma once

#include "src/device-info.h"
#include "src/platform/uvc-device-info.h"
#include "src/platform/backend-device-group.h"
#include <vector>
#include <string>
#include <memory>

namespace librealsense
{
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
                     platform::backend_device_group group)
            : device_info(ctx, std::move(group)) {}

        static std::vector<std::shared_ptr<device_info>> pick_goriila_devices(
            std::shared_ptr<context> ctx,
            platform::backend_device_group& group);
    };
}
