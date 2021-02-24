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

#include "AlexaBackend/Application.h"
#include "AlexaBackend/ApplicationContext.h"
#include "AlexaBackend/Args.h"
#include "AlexaBackend/Status.h"
#include "AlexaBackend/TTY.h"

using Application = sampleApp::Application;
using Status = sampleApp::Status;

// C++ Standard Library
#include <csignal>   // std::signal and SIG_ERR macro
#include <fstream>   // std::ifstream and std::ifstream::in
#include <iostream>  // std::cerr and std::cout
#include <memory>    // std::unique_ptr

// ZMQ lib
#include <zmq.hpp>
#include <string>
#include <unistd.h>

// Guidelines Support Library
#define GSL_THROW_ON_CONTRACT_VIOLATION
#include <gsl/contracts.h>

static sampleApp::TTY tty;

static void cbreakOnExit() {
    tty.reset(fileno(stdin));
}

static void cbreakSigCatch(int signal) {
    tty.reset(fileno(stdin));
    std::_Exit(Status::Success);
}

int main(int argc, const char* argv[]) {
    try {
        auto args = sampleApp::Args(argc, argv);
        auto c1 = [](const std::string& arg, unsigned char chr = '-') { return arg[0] == chr; };
        auto c2 = [](const std::string& arg, unsigned char chr = '-', const std::string& str = "") {
            return ((arg[1] == chr) && (arg[2] == '\0')) ||
                   ((arg[1] == '-') && (arg.compare(2, std::string::npos, str) == 0));
        };
        auto list = args.list();
        auto name = args.name();
        auto size = list.size();
        using Level = sampleApp::logger::LoggerHandler::Level;
        auto applicationContext = sampleApp::ApplicationContext::create(name);
        Ensures(applicationContext != nullptr);
        auto cbreak = false;
        auto options = true;
        for (size_t i = 0; i < size; ++i) {
            auto arg = list[i];
            Ensures(!arg.empty());
            if (options && c1(arg)) {
                if (c2(arg)) {
                    options = false;
                } else if (c2(arg, 'b', "cbreak")) {
                    cbreak = true;
                } else if (c2(arg, 'c', "config")) {
                    if (++i == size) {
                        // missingArgumentExit(name, arg);
                    }
                    arg = list[i];
                    auto input = std::ifstream(std::string(arg), std::ifstream::in);
                    if (!input.good()) {
                        // errorExit(name, "file not found " + arg);
                    }
                    input.close();
                    applicationContext->addConfigFilePath(arg);
                } else if (c2(arg, 'l', "level")) {
                    if (++i == size) {
                        // missingArgumentExit(name, arg);
                    }
                    arg = list[i];
                    const char* level = arg.c_str();
                    if (strcasecmp(level, "VERBOSE") == 0) {
                        applicationContext->setLevel(Level::VERBOSE);
                    } else if (strcasecmp(level, "INFO") == 0) {
                        applicationContext->setLevel(Level::INFO);
                    } else if (strcasecmp(level, "METRIC") == 0) {
                        applicationContext->setLevel(Level::METRIC);
                    } else if (strcasecmp(level, "WARN") == 0) {
                        applicationContext->setLevel(Level::WARN);
                    } else if (strcasecmp(level, "ERROR") == 0) {
                        applicationContext->setLevel(Level::ERROR);
                    } else if (strcasecmp(level, "CRITICAL") == 0) {
                        applicationContext->setLevel(Level::CRITICAL);
                    } else if (strcasecmp(level, "NONE") == 0) {
                        applicationContext->clearLevel();
                    } else {
                        // errorExit(name, "unknown level " + arg);
                    }
                } else if (c2(arg, 'm', "menu")) {
                    if (++i == size) {
                        // missingArgumentExit(name, arg);
                    }
                    arg = list[i];
                    auto input = std::ifstream(std::string(arg), std::ifstream::in);
                    if (!input.good()) {
                        // errorExit(name, "file not found " + arg);
                    }
                    input.close();
                    applicationContext->addMenuFilePath(arg);
                } else if (c2(arg, ' ', "browser")) {
                    if (++i == size) {
                        // missingArgumentExit(name, arg);
                    }
                    arg = list[i];
                    applicationContext->setBrowserCommand(arg);
                } else if (c2(arg, 'i', "audio-input-device")) {
                    if (++i == size) {
                        // missingArgumentExit(name, arg);
                    }
                    arg = list[i];
                    applicationContext->setAudioInputDevice(arg);
                } else if (c2(arg, ' ', "media-player")) {
                    if (++i == size) {
                        // missingArgumentExit(name, arg);
                    }
                    arg = list[i];
                    applicationContext->setMediaPlayerCommand(arg);
                } else if (c2(arg, ' ', "payload-script")) {
                    if (++i == size) {
                        // missingArgumentExit(name, arg);
                    }
                    arg = list[i];
                    applicationContext->setPayloadScriptCommand(arg);
                } else if (c2(arg, ' ', "render-player-info")) {
                    std::cerr << "--render-player-info option is deprecated (replaced with generic --payload-script)\n";
                } else if (c2(arg, ' ', "render-template")) {
                    std::cerr << "--render-template option is deprecated (replaced with generic --payload-script)\n";
                } else if (c2(arg, ' ', "single-threaded-ui")) {
                    applicationContext->setSingleThreadedUI(true);
                } else if (c2(arg, 'w', "wake-word")) {
                    auto support =
                        applicationContext->isWakeWordSupported() ? "wake word supported" : "wake word not supported";
                    std::cerr << "--wake-word option is deprecated (" << support << ")\n";
                } else if (c2(arg, 'h', "help") || c2(arg, '?')) {
                    exit(Status::Failure);
                } else {
                    // unknownArgumentExit(name, arg);
                }
            } else {
                applicationContext->addAudioFilePath(arg);
            }
        }
        if (applicationContext->getConfigFilePaths().empty()) {
            // errorExit(name, "Configuration file is required");
        }
        if (applicationContext->getMenuFilePaths().empty()) {
            // errorExit(name, "Menu file is required");
        }
        if (cbreak) {
            Ensures(tty.isatty(fileno(stdin)));
            Ensures(tty.cbreak(fileno(stdin)) != -1);
            Ensures(std::atexit(cbreakOnExit) != -1);
            // NOLINTNEXTLINE(cppcoreguidelines-pro-type-cstyle-cast)
            Ensures(std::signal(SIGINT, cbreakSigCatch) != SIG_ERR);
            // NOLINTNEXTLINE(cppcoreguidelines-pro-type-cstyle-cast)
            Ensures(std::signal(SIGQUIT, cbreakSigCatch) != SIG_ERR);
            // NOLINTNEXTLINE(cppcoreguidelines-pro-type-cstyle-cast)
            Ensures(std::signal(SIGTERM, cbreakSigCatch) != SIG_ERR);
        }
        std::unique_ptr<Application> application{};
        Status status;
        do {
                std::cout << "TESTTTTTT" << std::endl;
                std::cout << "TESTTTTTT" << std::endl;
                std::cout << "TESTTTTTT" << std::endl;
                std::cout << "TESTTTTTT" << std::endl;
                std::cout << "TESTTTTTT" << std::endl;
                std::cout << "TESTTTTTT" << std::endl;
                std::cout << "TESTTTTTT" << std::endl;
                std::cout << "TESTTTTTT" << std::endl;
                std::cout << "TESTTTTTT" << std::endl;
                std::cout << "TESTTTTTT" << std::endl;
                std::cout << "TESTTTTTT" << std::endl;
            Ensures((application = Application::create()) != nullptr);
            status = application->run(applicationContext);
            application.reset();
        } while (status == Status::Restart);
        return status;
    } catch (std::exception& exception) {
        std::cerr << "\n" << exception.what() << "\n\n";
    }
    return Status::Failure;
}
