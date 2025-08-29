// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#pragma once

#include "src/device.h"
#include "src/backend-device.h"
#include "src/core/video.h"

namespace librealsense
{
    class goriila_info;

    class goriila_s01_device : public device,
                               public backend_device
    {
    public:
        goriila_s01_device(std::shared_ptr<const goriila_info> const & dev_info, bool register_device_notifications);

        std::vector<tagged_profile> get_profiles_tags() const override;

        std::shared_ptr<matcher> create_matcher(const frame_holder& frame) const override;

    private:
        std::shared_ptr<stream_interface> _color_stream;

        void create_color_sensor();
    };
}
