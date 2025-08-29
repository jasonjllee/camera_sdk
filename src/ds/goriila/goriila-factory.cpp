// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#include "goriila-info.h"
#include "goriila-device.h"
#include "src/context.h"
#include "src/platform/platform-utils.h"

#include <rsutils/string/from.h>

namespace librealsense
{
    std::shared_ptr<device_interface> goriila_info::create_device()
    {
        auto const dev_info = std::dynamic_pointer_cast<const goriila_info>(shared_from_this());
        return std::make_shared<goriila_s01_device>(dev_info, true);
    }

    std::vector<std::shared_ptr<device_info>> goriila_info::pick_goriila_devices(
        std::shared_ptr<context> ctx,
        platform::backend_device_group& group)
    {
        std::vector<platform::uvc_device_info> chosen;
        std::vector<std::shared_ptr<device_info>> results;

        std::vector<platform::uvc_device_info> goriila_devices;
        for (const auto& uvc_info : group.uvc_devices)
        {
            if (uvc_info.vid == ds::GORIILA_VID)
            {
                 if (std::find(ds::goriila_sku_pid.begin(), ds::goriila_sku_pid.end(), uvc_info.pid) != ds::goriila_sku_pid.end())
                 {
                    goriila_devices.push_back(uvc_info);
                 }
            }
        }

        auto grouped_devices = platform::group_devices_by_unique_id(goriila_devices);

        for (auto& g : grouped_devices)
        {
            if (!g.empty())
            {
                results.push_back(std::make_shared<goriila_info>(ctx, std::move(g)));
                chosen.insert(chosen.end(), g.begin(), g.end());
            }
        }

        platform::trim_device_list(group.uvc_devices, chosen);

        return results;
    }
}
