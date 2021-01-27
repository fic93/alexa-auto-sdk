/*
 * Copyright 2017-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/*********************************************************
**********************************************************
**********************************************************

THIS FILE IS AUTOGENERATED. DO NOT EDIT

**********************************************************
**********************************************************
*********************************************************/

#ifndef EXTERNALMEDIAADAPTER_SUPPORTEDPLAYBACKOPERATION_H
#define EXTERNALMEDIAADAPTER_SUPPORTEDPLAYBACKOPERATION_H

#include <string>
#include <vector>

#include <unordered_map>
#include <AACE/Engine/Utils/UUID/UUID.h>
#include <nlohmann/json.hpp>

namespace aasb {
namespace message {
namespace alexa {

//Enum Definition
enum class SupportedPlaybackOperation {
    PLAY,
    PAUSE,
    STOP,
    NEXT,
    PREVIOUS,
    START_OVER,
    FAST_FORWARD,
    REWIND,
    ENABLE_REPEAT,
    ENABLE_REPEAT_ONE,
    DISABLE_REPEAT,
    ENABLE_SHUFFLE,
    DISABLE_SHUFFLE,
    FAVORITE,
    UNFAVORITE,
    SEEK,
    ADJUST_SEEK,
};

inline std::string toString(SupportedPlaybackOperation enumValue) {
    switch (enumValue) {
        case (SupportedPlaybackOperation::PLAY):
            return "PLAY";
        case (SupportedPlaybackOperation::PAUSE):
            return "PAUSE";
        case (SupportedPlaybackOperation::STOP):
            return "STOP";
        case (SupportedPlaybackOperation::NEXT):
            return "NEXT";
        case (SupportedPlaybackOperation::PREVIOUS):
            return "PREVIOUS";
        case (SupportedPlaybackOperation::START_OVER):
            return "START_OVER";
        case (SupportedPlaybackOperation::FAST_FORWARD):
            return "FAST_FORWARD";
        case (SupportedPlaybackOperation::REWIND):
            return "REWIND";
        case (SupportedPlaybackOperation::ENABLE_REPEAT):
            return "ENABLE_REPEAT";
        case (SupportedPlaybackOperation::ENABLE_REPEAT_ONE):
            return "ENABLE_REPEAT_ONE";
        case (SupportedPlaybackOperation::DISABLE_REPEAT):
            return "DISABLE_REPEAT";
        case (SupportedPlaybackOperation::ENABLE_SHUFFLE):
            return "ENABLE_SHUFFLE";
        case (SupportedPlaybackOperation::DISABLE_SHUFFLE):
            return "DISABLE_SHUFFLE";
        case (SupportedPlaybackOperation::FAVORITE):
            return "FAVORITE";
        case (SupportedPlaybackOperation::UNFAVORITE):
            return "UNFAVORITE";
        case (SupportedPlaybackOperation::SEEK):
            return "SEEK";
        case (SupportedPlaybackOperation::ADJUST_SEEK):
            return "ADJUST_SEEK";
    }
    throw std::runtime_error("invalidSupportedPlaybackOperationType");
}

inline SupportedPlaybackOperation toSupportedPlaybackOperation(const std::string& stringValue) {
    static std::unordered_map<std::string, SupportedPlaybackOperation> map = {
        {"PLAY", SupportedPlaybackOperation::PLAY},
        {"PAUSE", SupportedPlaybackOperation::PAUSE},
        {"STOP", SupportedPlaybackOperation::STOP},
        {"NEXT", SupportedPlaybackOperation::NEXT},
        {"PREVIOUS", SupportedPlaybackOperation::PREVIOUS},
        {"START_OVER", SupportedPlaybackOperation::START_OVER},
        {"FAST_FORWARD", SupportedPlaybackOperation::FAST_FORWARD},
        {"REWIND", SupportedPlaybackOperation::REWIND},
        {"ENABLE_REPEAT", SupportedPlaybackOperation::ENABLE_REPEAT},
        {"ENABLE_REPEAT_ONE", SupportedPlaybackOperation::ENABLE_REPEAT_ONE},
        {"DISABLE_REPEAT", SupportedPlaybackOperation::DISABLE_REPEAT},
        {"ENABLE_SHUFFLE", SupportedPlaybackOperation::ENABLE_SHUFFLE},
        {"DISABLE_SHUFFLE", SupportedPlaybackOperation::DISABLE_SHUFFLE},
        {"FAVORITE", SupportedPlaybackOperation::FAVORITE},
        {"UNFAVORITE", SupportedPlaybackOperation::UNFAVORITE},
        {"SEEK", SupportedPlaybackOperation::SEEK},
        {"ADJUST_SEEK", SupportedPlaybackOperation::ADJUST_SEEK},
    };

    auto search = map.find(stringValue);
    if (search != map.end()) {
        return search->second;
    }
    throw std::runtime_error("invalidSupportedPlaybackOperationType");
}

inline void to_json(nlohmann::json& j, const SupportedPlaybackOperation& c) {
    j = toString(c);
}

inline void from_json(const nlohmann::json& j, SupportedPlaybackOperation& c) {
    c = toSupportedPlaybackOperation(j);
}

}  // namespace alexa
}  // namespace message
}  // namespace aasb

#endif  // EXTERNALMEDIAADAPTER_SUPPORTEDPLAYBACKOPERATION_H
