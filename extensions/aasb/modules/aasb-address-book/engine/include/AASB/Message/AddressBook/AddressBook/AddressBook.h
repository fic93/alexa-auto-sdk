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

#ifndef ADDRESSBOOK_ADDRESSBOOK_H
#define ADDRESSBOOK_ADDRESSBOOK_H

#include <string>
#include <vector>

#include <AACE/Engine/Utils/UUID/UUID.h>
#include <nlohmann/json.hpp>
#include "AASB/Message/AddressBook/AddressBook/NavigationName.h"
#include "AASB/Message/AddressBook/AddressBook/ContactName.h"
#include "AASB/Message/AddressBook/AddressBook/PhoneData.h"
#include "AASB/Message/AddressBook/AddressBook/PostalAddress.h"

namespace aasb {
namespace message {
namespace addressBook {
namespace addressBook {

//Class Definition
struct AddressBook {
    std::string toString() const;
    std::vector<NavigationName> navigationNames;
    std::vector<ContactName> contactNames;
    std::vector<PhoneData> phoneData;
    std::vector<PostalAddress> postalAddresses;
};

//JSON Serialization
inline void to_json(nlohmann::json& j, const AddressBook& c) {
    j = nlohmann::json{
        {"navigationNames", c.navigationNames},
        {"contactNames", c.contactNames},
        {"phoneData", c.phoneData},
        {"postalAddresses", c.postalAddresses},
    };
}
inline void from_json(const nlohmann::json& j, AddressBook& c) {
    j.at("navigationNames").get_to(c.navigationNames);
    j.at("contactNames").get_to(c.contactNames);
    j.at("phoneData").get_to(c.phoneData);
    j.at("postalAddresses").get_to(c.postalAddresses);
}

inline std::string AddressBook::toString() const {
    nlohmann::json j = *this;
    return j.dump(3);
}

}  // namespace addressBook
}  // namespace addressBook
}  // namespace message
}  // namespace aasb

#endif  // ADDRESSBOOK_ADDRESSBOOK_H
