#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <string.h>

#include "User.hpp"

class Client : public User{
    public:
        Client(std::string host_ip, int port, std::string name);

        void connection();
        void read();
        void write();

    private:
        int socket;
        hostent* m_host;
        sockaddr_in host_addr;

};

#endif