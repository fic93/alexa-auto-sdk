#ifndef Z_H
#define Z_H

#include <zmq.hpp>
#include <string>
#include <unistd.h>

namespace Z {
    extern zmq::context_t context;
    extern zmq::socket_t socket;
    extern std::string port;


    class ZmqHandler {       
    public:
        ZmqHandler();
        void listenForRequests();
        void sendMessage(std::string _message);
    };

}

#endif