// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#pragma once

#include "gorilla-device.h"
#include <src/color-sensor.h>
#include "stream.h"
#include <map>

namespace librealsense
{
    class gorilla_color : public virtual gorilla_device
    {
    public:
        gorilla_color(std::shared_ptr<const gorilla_info> const &);

        synthetic_sensor& get_color_sensor();
        std::shared_ptr<uvc_sensor> get_raw_color_sensor();

    protected:
        std::shared_ptr<stream_interface> _color_stream;

    private:
        void create_color_device(std::shared_ptr<context> ctx, const platform::backend_device_group& group);
        uint8_t _color_device_idx = -1;

    friend class gorilla_color_sensor;
        friend class d400_color_sensor;
        friend class ds_color_common;
    };

    class gorilla_color_sensor : public synthetic_sensor,
                                 public color_sensor
    {
    public:
        explicit gorilla_color_sensor(gorilla_color* owner,
            std::shared_ptr<uvc_sensor> uvc_sensor,
            std::map<uint32_t, rs2_format> fourcc_to_rs2_format,
            std::map<uint32_t, rs2_stream> fourcc_to_rs2_stream)
            : synthetic_sensor("RGB Camera", uvc_sensor, owner, fourcc_to_rs2_format, fourcc_to_rs2_stream)
            , _owner(owner)
        {}

        stream_profiles init_stream_profiles() override;

    protected:
        const gorilla_color* _owner;
    };
}
