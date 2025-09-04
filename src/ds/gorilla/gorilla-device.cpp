// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#include "gorilla-device.h"
#include "core/matcher-factory.h"

namespace librealsense
{
    gorilla_device::gorilla_device(std::shared_ptr<const gorilla_info> const& dev_info)
        : backend_device(dev_info), _gorilla_info(dev_info)
    {
        init(dev_info->get_context(), dev_info->get_group());
    }

    void gorilla_device::init(std::shared_ptr<context> ctx, const platform::backend_device_group& group)
    {
        _pid = group.uvc_devices.front().pid;

        std::string device_name = (ds::gorilla_sku_names.end() != ds::gorilla_sku_names.find(_pid)) ? ds::gorilla_sku_names.at(_pid) : "GORILLA";

        register_info(RS2_CAMERA_INFO_NAME, device_name);
        register_info(RS2_CAMERA_INFO_SERIAL_NUMBER, "000000000001");
        register_info(RS2_CAMERA_INFO_FIRMWARE_VERSION, "1.0.0.0");
        register_info(RS2_CAMERA_INFO_PRODUCT_ID, std::to_string(_pid));
        register_info(RS2_CAMERA_INFO_PRODUCT_LINE, "gorilla");

    }

    std::vector<tagged_profile> gorilla_device::get_profiles_tags() const
    {
        std::vector<tagged_profile> tags;
        // The user mentioned RGB MJPG, IR, and Depth. I'll add some placeholder profiles.
        tags.push_back({ RS2_STREAM_DEPTH, -1, 640, 480, RS2_FORMAT_Z16, 30, profile_tag::PROFILE_TAG_DEFAULT });
        tags.push_back({ RS2_STREAM_INFRARED, 1, 640, 480, RS2_FORMAT_Y8, 30, profile_tag::PROFILE_TAG_DEFAULT });
        tags.push_back({ RS2_STREAM_COLOR, -1, 1920, 1080, RS2_FORMAT_MJPEG, 30, profile_tag::PROFILE_TAG_DEFAULT });
        return tags;
    }

    std::shared_ptr<matcher> gorilla_device::create_matcher(const frame_holder& frame) const
    {
        // For now, returning a default matcher.
        // This will need to be updated with the actual streams.
        std::vector<stream_interface*> streams;
        return matcher_factory::create(RS2_MATCHER_DEFAULT, streams);
    }
}
