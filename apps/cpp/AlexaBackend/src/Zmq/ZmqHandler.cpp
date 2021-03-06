
// #include <string>
// #include <unistd.h>
// #include <zmq.hpp>
#include "AlexaBackend/Zmq/ZmqHandler.h"
#include <iostream>

namespace Z {

zmq::context_t context(1);
zmq::socket_t socket(context, ZMQ_REP);
std::string port = "tcp://*:5555";

ZmqHandler::ZmqHandler(){};

void ZmqHandler::listenForRequests() {
    socket.bind(port);

    while (true) {
        zmq::message_t request;

        //  Wait for next request from client
        socket.recv(&request);


        // std::string rpl = std::string(static_cast<char*>(request.data()), request.size());

        //  Do some 'work'
        // sleep(1);

        // if (rpl == "T") {
        //     //  Send reply back to client
        std::string reply_message = "FROM ALEXA BACKEND";
        zmq::message_t reply(reply_message.size());
        memcpy(reply.data(), reply_message.data(), reply_message.size());
        socket.send(reply);
        // }
        // std::cout << "Reply: " << rpl << std::endl;
    }
}

void ZmqHandler::sendMessage(std::string message) {
    //  TODO
}
}  // namespace Z
