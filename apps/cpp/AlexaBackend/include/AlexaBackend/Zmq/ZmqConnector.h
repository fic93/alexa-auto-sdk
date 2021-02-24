#include <zmq.hpp>
#include <string>
#include <unistd.h>

class ZmqConnector {
private:
    zmq::context_t context;
    zmq::socket_t socket;
public:
    ZmqConnector();
    ~ZmqConnector();
    void connect(std::string port);
};

