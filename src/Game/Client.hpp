#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <csignal>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

class Client {
    public:
        Client(std::string host_ip, std::string name, int port);

    public:
        void signalHandler(int signum);

    private:
        int port;
        std::string name;
        std::string host_ip;
        int socket;
};

#endif