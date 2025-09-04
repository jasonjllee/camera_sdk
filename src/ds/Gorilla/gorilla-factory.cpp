// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#include "ds/Gorilla/gorilla-info.h"
#include "ds/Gorilla/gorilla-private.h"
#include "ds/Gorilla/gorilla-device.h"
#include "context.h"
#include "platform/platform-utils.h"
#include <rsutils/string/from.h>

namespace librealsense
{
    std::shared_ptr< device_interface > gorilla_info::create_device()
    {
        using namespace ds;

        if( _group.uvc_devices.empty() )
            throw std::runtime_error("Depth Camera not found!");

        auto const dev_info = std::dynamic_pointer_cast< const gorilla_info >( shared_from_this() );
        bool const register_device_notifications = true;

        auto pid = _group.uvc_devices.front().pid;

        switch(pid)
        {
        case GORILLA_S01_PID:
            return std::make_shared< gorilla_s01_device >( dev_info );
        default:
            throw std::runtime_error( rsutils::string::from() << "Unsupported GORILLA model! 0x" << std::hex
                                                              << std::setw( 4 ) << std::setfill( '0' ) << (int)pid );
        }
    }

    std::vector<std::shared_ptr<gorilla_info>> gorilla_info::pick_gorilla_devices(
        std::shared_ptr<context> ctx,
        platform::backend_device_group& group)
    {
        std::vector<platform::uvc_device_info> chosen;
        std::vector<std::shared_ptr<gorilla_info>> results;

        auto valid_pid = filter_by_product(group.uvc_devices, ds::gorilla_sku_pid);
        auto group_devices = group_devices_by_unique_id(valid_pid);

        for (auto& g : group_devices)
        {
            // For now, we assume one device per group
            if (!g.empty())
            {
                auto info = std::make_shared<gorilla_info>( ctx, std::move(g) );
                chosen.insert(chosen.end(), g.begin(), g.end());
                results.push_back(info);
            }
        }

        trim_device_list(group.uvc_devices, chosen);

        return results;
    }
}
