// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2024 Intel Corporation. All Rights Reserved.

#include "gorilla-device.h"
#include "core/matcher-factory.h"

namespace librealsense
{
    gorilla_s01_device::gorilla_s01_device(std::shared_ptr<const gorilla_info> const& dev_info)
        : device(dev_info, true), backend_device(dev_info)
    {
        // ... constructor logic ...
    }

    std::vector<tagged_profile> gorilla_s01_device::get_profiles_tags() const
    {
        std::vector<tagged_profile> tags;
        // The user mentioned RGB MJPG, IR, and Depth. I'll add some placeholder profiles.
        tags.push_back({ RS2_STREAM_DEPTH, -1, 640, 480, RS2_FORMAT_Z16, 30, profile_tag::PROFILE_TAG_DEFAULT });
        tags.push_back({ RS2_STREAM_INFRARED, 1, 640, 480, RS2_FORMAT_Y8, 30, profile_tag::PROFILE_TAG_DEFAULT });
        tags.push_back({ RS2_STREAM_COLOR, -1, 640, 480, RS2_FORMAT_MJPEG, 30, profile_tag::PROFILE_TAG_DEFAULT });
        return tags;
    }

    std::shared_ptr<matcher> gorilla_s01_device::create_matcher(const frame_holder& frame) const
    {
        // For now, returning a default matcher.
        // This will need to be updated with the actual streams.
        std::vector<stream_interface*> streams;
        return matcher_factory::create(RS2_MATCHER_DEFAULT, streams);
    }
}
