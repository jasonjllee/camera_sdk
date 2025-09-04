// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.
#pragma once

#include <src/platform/platform-device-info.h>

namespace librealsense
{
    class gorilla_info : public platform::platform_device_info
    {
    public:
        std::shared_ptr< device_interface > create_device() override;

        gorilla_info( std::shared_ptr< context > const & ctx,
                   std::vector< platform::uvc_device_info > && devices )
            : platform_device_info( ctx, { std::move( devices ), {}, {} } )
        {
        }

        static std::vector<std::shared_ptr<gorilla_info>> pick_gorilla_devices(
                std::shared_ptr<context> ctx,
                platform::backend_device_group& group);
    };
}
