// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#pragma once

#include "gorilla-color.h"

namespace librealsense
{
    class gorilla_s01_device : public gorilla_color
    {
    public:
        gorilla_s01_device(std::shared_ptr<const gorilla_info> const& dev_info);
    };
}
