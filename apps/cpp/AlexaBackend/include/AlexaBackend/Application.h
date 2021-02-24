/*
 * Copyright 2018-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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

#ifndef SAMPLEAPP_APPLICATION_H
#define SAMPLEAPP_APPLICATION_H

// Sample Application
#include "AlexaBackend/Activity.h"
#include "AlexaBackend/ApplicationContext.h"
#include "AlexaBackend/Event.h"
#include "AlexaBackend/Executor.h"
#include "AlexaBackend/Status.h"
#include "AlexaBackend/Subject.h"
#include "AlexaBackend/Views.h"

// Sample Alexa Platform Interfaces
#include "AlexaBackend/Alexa/AlertsHandler.h"
#include "AlexaBackend/Alexa/AlexaClientHandler.h"
#include "AlexaBackend/Alexa/AudioPlayerHandler.h"
#include "AlexaBackend/Alexa/EqualizerControllerHandler.h"
#include "AlexaBackend/Alexa/LocalMediaSourceHandler.h"
#include "AlexaBackend/Alexa/NotificationsHandler.h"
#include "AlexaBackend/Alexa/PlaybackControllerHandler.h"
#include "AlexaBackend/Alexa/SpeechRecognizerHandler.h"
#include "AlexaBackend/Alexa/SpeechSynthesizerHandler.h"
#include "AlexaBackend/Alexa/TemplateRuntimeHandler.h"
#include "AlexaBackend/Alexa/AlexaSpeakerHandler.h"
#include "AlexaBackend/Alexa/GlobalPresetHandler.h"
#include "AlexaBackend/Alexa/DoNotDisturbHandler.h"

// Default Audio Interfaces (File based audio support)
#include "AlexaBackend/Audio/AudioInputProviderHandler.h"
#include "AlexaBackend/Audio/AudioOutputProviderHandler.h"

// Sample Authorization Interfaces
#include "AlexaBackend/Authorization/AuthorizationHandler.h"

// Sample Communications Platform Interfaces
#ifdef ALEXACOMMS
#include "AlexaBackend/Communication/CommunicationHandler.h"
#endif  // ALEXACOMMS

// Sample AlexaConnectivity Platform Interfaces
#ifdef CONNECTIVITY
#include "AlexaBackend/Connectivity/AlexaConnectivityHandler.h"
#endif  // CONNECTIVITY

// Sample Local Search Provider Platform Interface
#ifdef LOCALVOICECONTROL
#include "AlexaBackend/LocalNavigation/LocalSearchProviderHandler.h"
#endif  // LOCALVOICECONTROL

// Sample Location Platform Interfaces
#include "AlexaBackend/Location/LocationProviderHandler.h"

// Sample Logger Platform Interfaces
#include "AlexaBackend/Logger/LoggerHandler.h"

// Sample Messaging Platform Interfaces
#include "AlexaBackend/Messaging/MessagingHandler.h"

// Sample Navigation Platform Interfaces
#include "AlexaBackend/Navigation/NavigationHandler.h"

// Sample Network Platform Interfaces
#include "AlexaBackend/Network/NetworkInfoProviderHandler.h"

// Sample PhoneControl Platform Interfaces
#include "AlexaBackend/PhoneControl/PhoneControlHandler.h"

// Sample Property Manager Platform Interfaces
#include "AlexaBackend/PropertyManager/PropertyManagerHandler.h"

// Sample AddressBook Platform Interfaces
#include "AlexaBackend/AddressBook/AddressBookHandler.h"

// Sample CarControl Platform Interfaces
#include "AlexaBackend/CarControl/CarControlHandler.h"
#include "AlexaBackend/CarControl/CarControlDataProvider.h"
#include <AACE/CarControl/CarControlConfiguration.h>

// Alexa Auto Core
#include <AACE/Core/CoreProperties.h>
#include <AACE/Core/Engine.h>
#include <AACE/Core/EngineConfiguration.h>
#include <AACE/Core/PlatformInterface.h>

namespace sampleApp {

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Application
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class Application {
protected:
    Application();

public:
    static std::unique_ptr<Application> create() {
        return std::unique_ptr<Application>(new Application());
    }
    auto printMenu(
        std::shared_ptr<ApplicationContext> applicationContext,
        std::shared_ptr<aace::core::Engine> engine,
        std::shared_ptr<sampleApp::propertyManager::PropertyManagerHandler> propertyManagerHandler,
        std::shared_ptr<View> console,
        const std::string& id) -> void;
    auto printMenuText(
        std::shared_ptr<ApplicationContext> applicationContext,
        std::shared_ptr<View> console,
        const std::string& menuId,
        const std::string& textId,
        std::map<std::string, std::string> variables) -> void;
    auto printStringLine(
        std::shared_ptr<View> console,
        const std::string& string,
        std::map<std::string, std::string> variables) -> void;
    auto run(std::shared_ptr<ApplicationContext> applicationContext) -> Status;
    auto runMenu(
        std::shared_ptr<ApplicationContext> applicationContext,
        std::shared_ptr<aace::core::Engine> engine,
        std::shared_ptr<sampleApp::propertyManager::PropertyManagerHandler> propertyManagerHandler,
        std::shared_ptr<Activity> activity,
        std::shared_ptr<View> console,
        const std::string& id) -> Status;
    auto setupMenu(
        std::shared_ptr<ApplicationContext> applicationContext,
        std::shared_ptr<aace::core::Engine> engine,
        std::shared_ptr<sampleApp::propertyManager::PropertyManagerHandler> propertyManagerHandler,
        std::shared_ptr<View> console) -> void;
    auto testMenuItem(std::shared_ptr<ApplicationContext> applicationContext, const json& item) -> bool;
};

}  // namespace sampleApp

#endif  // SAMPLEAPP_APPLICATION_H
