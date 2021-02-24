//  ZMQ test
/*
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5555");

    while (true) {
        zmq::message_t request;

        //  Wait for next request from client
        socket.recv (&request);

        // std::cout << "Received FROM ALEXA FRONTEND" << std::flush;
        // std::cout << "Received FROM ALEXA FRONTEND" << std::flush;


        //  Do some 'work'
    	sleep(1);

        //  Send reply back to client
        std::string reply_message = "FROM ALEXA BACKEND";
        zmq::message_t reply (reply_message.size());
        memcpy (reply.data (), reply_message.data(), reply_message.size());
        socket.send (reply);
    }
    return 0;*/
