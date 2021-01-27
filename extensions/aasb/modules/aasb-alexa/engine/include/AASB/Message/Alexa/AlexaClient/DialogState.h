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

#ifndef ALEXACLIENT_DIALOGSTATE_H
#define ALEXACLIENT_DIALOGSTATE_H

#include <string>
#include <vector>

#include <unordered_map>
#include <AACE/Engine/Utils/UUID/UUID.h>
#include <nlohmann/json.hpp>

namespace aasb {
namespace message {
namespace alexa {

//Enum Definition
enum class DialogState {
    IDLE,
    LISTENING,
    EXPECTING,
    THINKING,
    SPEAKING,
};

inline std::string toString(DialogState enumValue) {
    switch (enumValue) {
        case (DialogState::IDLE):
            return "IDLE";
        case (DialogState::LISTENING):
            return "LISTENING";
        case (DialogState::EXPECTING):
            return "EXPECTING";
        case (DialogState::THINKING):
            return "THINKING";
        case (DialogState::SPEAKING):
            return "SPEAKING";
    }
    throw std::runtime_error("invalidDialogStateType");
}

inline DialogState toDialogState(const std::string& stringValue) {
    static std::unordered_map<std::string, DialogState> map = {
        {"IDLE", DialogState::IDLE},
        {"LISTENING", DialogState::LISTENING},
        {"EXPECTING", DialogState::EXPECTING},
        {"THINKING", DialogState::THINKING},
        {"SPEAKING", DialogState::SPEAKING},
    };

    auto search = map.find(stringValue);
    if (search != map.end()) {
        return search->second;
    }
    throw std::runtime_error("invalidDialogStateType");
}

inline void to_json(nlohmann::json& j, const DialogState& c) {
    j = toString(c);
}

inline void from_json(const nlohmann::json& j, DialogState& c) {
    c = toDialogState(j);
}

}  // namespace alexa
}  // namespace message
}  // namespace aasb

#endif  // ALEXACLIENT_DIALOGSTATE_H
