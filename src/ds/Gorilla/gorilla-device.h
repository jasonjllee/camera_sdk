// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.
#pragma once

#include "src/device.h"
#include "src/backend-device.h"
#include "ds/Gorilla/gorilla-info.h"
#include "ds/Gorilla/gorilla-private.h"
#include <vector>

namespace librealsense
{
    class gorilla_s01_device : public virtual device,
                               public virtual backend_device
    {
    public:
        gorilla_s01_device(std::shared_ptr<const gorilla_info> const& dev_info);

        std::vector<tagged_profile> get_profiles_tags() const override;

        std::shared_ptr<matcher> create_matcher(const frame_holder& frame) const override;

    private:
        void init();

        uint16_t _pid;
        std::shared_ptr<const gorilla_info> _gorilla_info;
    };
}
