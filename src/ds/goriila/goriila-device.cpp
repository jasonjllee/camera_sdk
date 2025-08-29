// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#include "goriila-device.h"
#include "goriila-info.h"
#include "src/core/matcher-factory.h"
#include "src/uvc-sensor.h"

namespace librealsense
{
    goriila_s01_device::goriila_s01_device(std::shared_ptr<const goriila_info> const & dev_info, bool register_device_notifications)
        : device(dev_info, register_device_notifications),
          backend_device(dev_info, register_device_notifications)
    {
        create_color_sensor();
    }

    void goriila_s01_device::create_color_sensor()
    {
        auto uvc_dev = get_uvc_device();
        auto color_ep = std::make_shared<uvc_sensor>("Color Sensor", std::make_shared<platform::command_transfer_over_xu>(*uvc_dev, 0), this);

        color_ep->register_option(RS2_OPTION_BRIGHTNESS, std::make_shared<uvc_pu_option>(*color_ep, RS2_OPTION_BRIGHTNESS));
        color_ep->register_option(RS2_OPTION_CONTRAST, std::make_shared<uvc_pu_option>(*color_ep, RS2_OPTION_CONTRAST));
        color_ep->register_option(RS2_OPTION_SATURATION, std::make_shared<uvc_pu_option>(*color_ep, RS2_OPTION_SATURATION));
        color_ep->register_option(RS2_OPTION_GAMMA, std::make_shared<uvc_pu_option>(*color_ep, RS2_OPTION_GAMMA));
        color_ep->register_option(RS2_OPTION_SHARPNESS, std::make_shared<uvc_pu_option>(*color_ep, RS2_OPTION_SHARPNESS));
        color_ep->register_option(RS2_OPTION_BACKLIGHT_COMPENSATION, std::make_shared<uvc_pu_option>(*color_ep, RS2_OPTION_BACKLIGHT_COMPENSATION));

        auto gain_option = std::make_shared<uvc_pu_option>(*color_ep, RS2_OPTION_GAIN);
        color_ep->register_option(RS2_OPTION_GAIN, gain_option);

        auto white_balance_option = std::make_shared<uvc_pu_option>(*color_ep, RS2_OPTION_WHITE_BALANCE);
        auto auto_white_balance_option = std::make_shared<uvc_pu_option>(*color_ep, RS2_OPTION_ENABLE_AUTO_WHITE_BALANCE);

        color_ep->register_option(RS2_OPTION_WHITE_BALANCE, white_balance_option);
        color_ep->register_option(RS2_OPTION_ENABLE_AUTO_WHITE_BALANCE, auto_white_balance_option);

        color_ep->register_option_supported(RS2_OPTION_WHITE_BALANCE, is_option_supported(RS2_OPTION_WHITE_BALANCE));
        color_ep->register_option_supported(RS2_OPTION_ENABLE_AUTO_WHITE_BALANCE, is_option_supported(RS2_OPTION_ENABLE_AUTO_WHITE_BALANCE));

        auto exposure_option = std::make_shared<uvc_pu_option>(*color_ep, RS2_OPTION_EXPOSURE);
        auto auto_exposure_option = std::make_shared<uvc_pu_option>(*color_ep, RS2_OPTION_ENABLE_AUTO_EXPOSURE);

        color_ep->register_option(RS2_OPTION_EXPOSURE, exposure_option);
        color_ep->register_option(RS2_OPTION_ENABLE_AUTO_EXPOSURE, auto_exposure_option);

        add_sensor(color_ep);
        _color_stream = color_ep->get_stream(RS2_STREAM_COLOR);
    }

    std::vector<tagged_profile> goriila_s01_device::get_profiles_tags() const
    {
        std::vector<tagged_profile> tags;
        tags.push_back({ RS2_STREAM_COLOR, -1, 640, 480, RS2_FORMAT_RGB8, 30, profile_tag::PROFILE_TAG_SUPERSET | profile_tag::PROFILE_TAG_DEFAULT });
        return tags;
    }

    std::shared_ptr<matcher> goriila_s01_device::create_matcher(const frame_holder& frame) const
    {
        std::vector<stream_interface*> streams = { _color_stream.get() };
        return matcher_factory::create(RS2_MATCHER_DEFAULT, streams);
    }
}
