#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include "User.hpp"

class Server : public User{
    public:
        Server(std::string host_ip, int port, std::string name);
};

#endif