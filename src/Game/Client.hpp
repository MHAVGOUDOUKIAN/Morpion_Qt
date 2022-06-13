#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <csignal>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#include "User.hpp"

class Client : public User{
    public:
        Client(std::string host_ip, int port, std::string name);
};

#endif