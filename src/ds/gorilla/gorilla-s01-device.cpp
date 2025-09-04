// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#include "gorilla-s01-device.h"

namespace librealsense
{
    gorilla_s01_device::gorilla_s01_device(std::shared_ptr<const gorilla_info> const& dev_info)
        : device(dev_info, true),
          backend_device(dev_info),
          gorilla_base_device(dev_info),
          gorilla_color(dev_info)
    {
    }
}
