#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>

class Server {
    public:
        Server(std::string name, int port);
        
    private:
        int port;
        std::string name;
};

#endif