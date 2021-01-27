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

#ifndef LOCALMEDIASOURCE_MUTEDSTATECHANGEDMESSAGE_H
#define LOCALMEDIASOURCE_MUTEDSTATECHANGEDMESSAGE_H

#include <string>
#include <vector>

#include <AACE/Engine/Utils/UUID/UUID.h>
#include <nlohmann/json.hpp>
#include "AASB/Message/Alexa/LocalMediaSource/Source.h"
#include "AASB/Message/Alexa/ExternalMediaAdapter/MutedState.h"

namespace aasb {
namespace message {
namespace alexa {
namespace localMediaSource {

//Class Definition
struct MutedStateChangedMessage {
    struct Header {
        struct MessageDescription {
            static const std::string& topic() {
                static std::string topic = "LocalMediaSource";
                return topic;
            }
            static const std::string& action() {
                static std::string action = "MutedStateChanged";
                return action;
            }
        };
        static const std::string& version() {
            static std::string version = "3.0";
            return version;
        }
        static const std::string& messageType() {
            static std::string messageType = "Publish";
            return messageType;
        }
        std::string id = aace::engine::utils::uuid::generateUUID();
        MessageDescription messageDescription;
    };
    struct Payload {
        using Source = ::aasb::message::alexa::localMediaSource::Source;
        using MutedState = ::aasb::message::alexa::MutedState;

        Source source;
        MutedState state;
    };
    static const std::string& topic() {
        static std::string topic = "LocalMediaSource";
        return topic;
    }
    static const std::string& action() {
        static std::string action = "MutedStateChanged";
        return action;
    }
    static const std::string& version() {
        static std::string version = "3.0";
        return version;
    }
    static const std::string& messageType() {
        static std::string messageType = "Publish";
        return messageType;
    }
    std::string toString() const;
    Header header;
    Payload payload;
};

//JSON Serialization
inline void to_json(nlohmann::json& j, const MutedStateChangedMessage::Payload& c) {
    j = nlohmann::json{
        {"source", c.source},
        {"state", c.state},
    };
}
inline void from_json(const nlohmann::json& j, MutedStateChangedMessage::Payload& c) {
    j.at("source").get_to(c.source);
    j.at("state").get_to(c.state);
}

inline void to_json(nlohmann::json& j, const MutedStateChangedMessage::Header::MessageDescription& c) {
    j = nlohmann::json{
        {"topic", c.topic()},
        {"action", c.action()},
    };
}
inline void from_json(const nlohmann::json& j, MutedStateChangedMessage::Header::MessageDescription& c) {
}

inline void to_json(nlohmann::json& j, const MutedStateChangedMessage::Header& c) {
    j = nlohmann::json{
        {"version", c.version()},
        {"messageType", c.messageType()},
        {"id", c.id},
        {"messageDescription", c.messageDescription},
    };
}
inline void from_json(const nlohmann::json& j, MutedStateChangedMessage::Header& c) {
    j.at("id").get_to(c.id);
    j.at("messageDescription").get_to(c.messageDescription);
}

inline void to_json(nlohmann::json& j, const MutedStateChangedMessage& c) {
    j = nlohmann::json{
        {"header", c.header},
        {"payload", c.payload},
    };
}
inline void from_json(const nlohmann::json& j, MutedStateChangedMessage& c) {
    j.at("header").get_to(c.header);
    j.at("payload").get_to(c.payload);
}

inline std::string MutedStateChangedMessage::toString() const {
    nlohmann::json j = *this;
    return j.dump(3);
}

}  // namespace localMediaSource
}  // namespace alexa
}  // namespace message
}  // namespace aasb

#endif  // LOCALMEDIASOURCE_MUTEDSTATECHANGEDMESSAGE_H
