// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#include "gorilla-color.h"
#include "gorilla-info.h"
#include <src/backend.h>
#include <src/ds/ds-timestamp.h>
#include <src/platform/platform-utils.h>
#include <rsutils/string/from.h>
#include <rsutils/type/fourcc.h>
using rs_fourcc = rsutils::type::fourcc;

namespace librealsense
{
    std::map<rs_fourcc::value_type, rs2_format> gorilla_color_fourcc_to_rs2_format = {
        {rs_fourcc('M','J','P','G'), RS2_FORMAT_MJPEG},
        {rs_fourcc('Y','U','Y','V'), RS2_FORMAT_YUYV},
    };
    std::map<rs_fourcc::value_type, rs2_stream> gorilla_color_fourcc_to_rs2_stream = {
        {rs_fourcc('M','J','P','G'), RS2_STREAM_COLOR},
        {rs_fourcc('Y','U','Y','V'), RS2_STREAM_COLOR},
    };

    gorilla_color::gorilla_color(std::shared_ptr<const gorilla_info> const & dev_info)
        : _color_stream(new stream(RS2_STREAM_COLOR))
    {
        create_color_device(dev_info->get_context(), dev_info->get_group());
    }

    void gorilla_color::create_color_device(std::shared_ptr<context> ctx, const platform::backend_device_group& group)
    {
        auto color_devs_info = filter_by_mi(group.uvc_devices, 2); // Assuming color is on MI=2
        if (color_devs_info.empty())
        {
            LOG_WARNING("Gorilla: No color sensor found!");
            return;
        }

        auto raw_color_ep = std::make_shared<uvc_sensor>("Raw RGB Camera",
            get_backend()->create_uvc_device(color_devs_info.front()),
            std::unique_ptr<frame_timestamp_reader>(new ds_timestamp_reader()), this);

        auto color_ep = std::make_shared<gorilla_color_sensor>(this,
            raw_color_ep,
            gorilla_color_fourcc_to_rs2_format,
            gorilla_color_fourcc_to_rs2_stream);

        color_ep->register_info(RS2_CAMERA_INFO_PHYSICAL_PORT, color_devs_info.front().device_path);
        _color_device_idx = add_sensor(color_ep);
    }

    synthetic_sensor& gorilla_color::get_color_sensor()
    {
        return dynamic_cast<synthetic_sensor&>(get_sensor(_color_device_idx));
    }

    std::shared_ptr<uvc_sensor> gorilla_color::get_raw_color_sensor()
    {
        synthetic_sensor& color_sensor = get_color_sensor();
        return std::dynamic_pointer_cast<uvc_sensor>(color_sensor.get_raw_sensor());
    }

    gorilla_color_sensor::gorilla_color_sensor(gorilla_color* owner,
        std::shared_ptr<uvc_sensor> uvc_sensor,
        std::map<uint32_t, rs2_format> fourcc_to_rs2_format,
        std::map<uint32_t, rs2_stream> fourcc_to_rs2_stream)
        : synthetic_sensor("RGB Camera", uvc_sensor, owner, fourcc_to_rs2_format, fourcc_to_rs2_stream),
          _owner(owner)
    {}

    stream_profiles gorilla_color_sensor::init_stream_profiles()
    {
        auto lock = environment::get_instance().get_extrinsics_graph().lock();
        auto&& results = synthetic_sensor::init_stream_profiles();

        for (auto&& p : results)
        {
            if (p->get_stream_type() == RS2_STREAM_COLOR)
            {
                assign_stream(_owner->_color_stream, p);
            }
        }
        return results;
    }
}
