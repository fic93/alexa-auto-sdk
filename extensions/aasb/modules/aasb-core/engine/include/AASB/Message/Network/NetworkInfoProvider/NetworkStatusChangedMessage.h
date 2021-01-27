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

#ifndef NETWORKINFOPROVIDER_NETWORKSTATUSCHANGEDMESSAGE_H
#define NETWORKINFOPROVIDER_NETWORKSTATUSCHANGEDMESSAGE_H

#include <string>
#include <vector>

#include <AACE/Engine/Utils/UUID/UUID.h>
#include <nlohmann/json.hpp>
#include "AASB/Message/Network/NetworkInfoProvider/NetworkStatus.h"

namespace aasb {
namespace message {
namespace network {
namespace networkInfoProvider {

//Class Definition
struct NetworkStatusChangedMessage {
    struct Header {
        struct MessageDescription {
            static const std::string& topic() {
                static std::string topic = "NetworkInfoProvider";
                return topic;
            }
            static const std::string& action() {
                static std::string action = "NetworkStatusChanged";
                return action;
            }
        };
        static const std::string& version() {
            static std::string version = "3.1";
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
        using NetworkStatus = ::aasb::message::network::NetworkStatus;

        NetworkStatus status;
        int wifiSignalStrength;
    };
    static const std::string& topic() {
        static std::string topic = "NetworkInfoProvider";
        return topic;
    }
    static const std::string& action() {
        static std::string action = "NetworkStatusChanged";
        return action;
    }
    static const std::string& version() {
        static std::string version = "3.1";
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
inline void to_json(nlohmann::json& j, const NetworkStatusChangedMessage::Payload& c) {
    j = nlohmann::json{
        {"status", c.status},
        {"wifiSignalStrength", c.wifiSignalStrength},
    };
}
inline void from_json(const nlohmann::json& j, NetworkStatusChangedMessage::Payload& c) {
    j.at("status").get_to(c.status);
    j.at("wifiSignalStrength").get_to(c.wifiSignalStrength);
}

inline void to_json(nlohmann::json& j, const NetworkStatusChangedMessage::Header::MessageDescription& c) {
    j = nlohmann::json{
        {"topic", c.topic()},
        {"action", c.action()},
    };
}
inline void from_json(const nlohmann::json& j, NetworkStatusChangedMessage::Header::MessageDescription& c) {
}

inline void to_json(nlohmann::json& j, const NetworkStatusChangedMessage::Header& c) {
    j = nlohmann::json{
        {"version", c.version()},
        {"messageType", c.messageType()},
        {"id", c.id},
        {"messageDescription", c.messageDescription},
    };
}
inline void from_json(const nlohmann::json& j, NetworkStatusChangedMessage::Header& c) {
    j.at("id").get_to(c.id);
    j.at("messageDescription").get_to(c.messageDescription);
}

inline void to_json(nlohmann::json& j, const NetworkStatusChangedMessage& c) {
    j = nlohmann::json{
        {"header", c.header},
        {"payload", c.payload},
    };
}
inline void from_json(const nlohmann::json& j, NetworkStatusChangedMessage& c) {
    j.at("header").get_to(c.header);
    j.at("payload").get_to(c.payload);
}

inline std::string NetworkStatusChangedMessage::toString() const {
    nlohmann::json j = *this;
    return j.dump(3);
}

}  // namespace networkInfoProvider
}  // namespace network
}  // namespace message
}  // namespace aasb

#endif  // NETWORKINFOPROVIDER_NETWORKSTATUSCHANGEDMESSAGE_H
