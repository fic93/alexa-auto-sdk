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

#ifndef AACE_VEHICLE_CONFIG_VEHICLE_CONFIGURATION_H
#define AACE_VEHICLE_CONFIG_VEHICLE_CONFIGURATION_H

#include <utility>

#include "AACE/Core/EngineConfiguration.h"

/** @file */

namespace aace {
namespace vehicle {
namespace config {

/**
 * The @c VehicleConfiguration class is a factory interface for creating "aace.vehicle" configuration objects.
 */
class VehicleConfiguration {
public:
    /**
     * Specifies the vehicle properties required in configuration
     */
    enum class VehiclePropertyType {

        /**
         * The make of the vehicle.
         * @note This property is required.
         */
        MAKE,

        /**
         * The model of the vehicle.
         * @note This property is required.
         */
        MODEL,

        /**
         * The model year of the vehicle.
         * A value of this property type must be an integer in the range 1900-2100.
         * Example value: "2019"
         * @note This property is required.
         */
        YEAR,

        /**
         * The trim level of the vehicle, identifying the vehicle's level of equipment or special features.
         * Example values: "Standard", "Sport", "Limited"
         */
        TRIM,

        /**
         * The current location (country/region/state/etc.) of the vehicle. 
         * Example values: "US", "US-North", "WA"
         */
        GEOGRAPHY,

        /**
         * The client software version.
         * Example value: "2.2.1X"
         */
        VERSION,

        /**
         * The operating system used by the vehicle's infotainment system.
         * Example value: "AndroidOreo_8.1"
         */
        OPERATING_SYSTEM,

        /**
         * The hardware architecture used by the vehicle.
         * Example value: "x86_64"
         */
        HARDWARE_ARCH,

        /**
         * The language or locale selected for Alexa by the vehicle owner.
         * Example values: "en-US", "fr-CA"
         */
        LANGUAGE,

        /**
         * The type and arrangement of microphone used by the vehicle.
         * Example value: "7 mic array, centrally mounted"
         */
        MICROPHONE,

        /**
         * The automaker's identifier for the vehicle.
         */
        VEHICLE_IDENTIFIER
    };

    /**
     * Identifies a vehicle property with a type and value pair
     */
    using VehicleProperty = std::pair<VehiclePropertyType, std::string>;

    /**
     * Factory method used to programmatically generate "aace.vehicle" vehicle info configuration data.
     * The data generated by this method is equivalent to providing the following JSON
     * values in a configuration file:
     *
     * @code{.json}
     * {
     *   "aace.vehicle":
     *   {
     *      "info": {
     *          "make": "<MAKE>",
     *          "model": "<MODEL>",
     *          "year": "<YEAR>",
     *          "trim": "<TRIM>",
     *          "geography": "<GEOGRAPHY>",
     *          "version": "<SOFTWARE_VERSION>",
     *          "os": "<OPERATING_SYSTEM>",
     *          "arch": "<HARDWARE_ARCH>",
     *          "language": "<LANGUAGE>",
     *          "microphone": "<MICROPHONE>",
     *          "vehicleIdentifier": "<VEHICLE_IDENTIFIER>"
     *      }
     *   }
     * }
     * @endcode
     *
     * @param [in] propertyList A list of @c VehicleProperty type and value pairs
     */
    static std::shared_ptr<aace::core::config::EngineConfiguration> createVehicleInfoConfig(
        const std::vector<VehicleProperty>& propertyList);

    /**
     * Factory method used to programmatically generate vehicle operating country configuration data.
     * The data generated by this method is equivalent to providing the following JSON
     * values in a configuration file:
     *
     * @code{.json}
     * {
     *   "aace.vehicle": {
     *      "operatingCountry": "<COUNTRY>"
     *   }
     * }
     * @endcode
     *
     * @param [in] operatingCountry A 2-letter ISO country code
     */
    static std::shared_ptr<aace::core::config::EngineConfiguration> createOperatingCountryConfig(
        const std::string& operatingCountry);
};

inline std::ostream& operator<<(std::ostream& stream, const VehicleConfiguration::VehiclePropertyType& state) {
    switch (state) {
        case VehicleConfiguration::VehiclePropertyType::MAKE:
            stream << "MAKE";
            break;
        case VehicleConfiguration::VehiclePropertyType::MODEL:
            stream << "MODEL";
            break;
        case VehicleConfiguration::VehiclePropertyType::YEAR:
            stream << "YEAR";
            break;
        case VehicleConfiguration::VehiclePropertyType::TRIM:
            stream << "TRIM";
            break;
        case VehicleConfiguration::VehiclePropertyType::GEOGRAPHY:
            stream << "GEOGRAPHY";
            break;
        case VehicleConfiguration::VehiclePropertyType::VERSION:
            stream << "VERSION";
            break;
        case VehicleConfiguration::VehiclePropertyType::OPERATING_SYSTEM:
            stream << "OPERATING_SYSTEM";
            break;
        case VehicleConfiguration::VehiclePropertyType::HARDWARE_ARCH:
            stream << "HARDWARE_ARCH";
            break;
        case VehicleConfiguration::VehiclePropertyType::LANGUAGE:
            stream << "LANGUAGE";
            break;
        case VehicleConfiguration::VehiclePropertyType::MICROPHONE:
            stream << "MICROPHONE";
            break;
        case VehicleConfiguration::VehiclePropertyType::VEHICLE_IDENTIFIER:
            stream << "VEHICLE_IDENTIFIER";
            break;
    }
    return stream;
}

}  // namespace config
}  // namespace vehicle
}  // namespace aace

#endif  // AACE_VEHICLE_CONFIG_VEHICLE_CONFIGURATION_H