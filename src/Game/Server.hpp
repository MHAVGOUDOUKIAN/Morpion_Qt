#ifndef SERVER_HPP
#define SERVER_HPP

#include "User.hpp"

class Server : public User {
    public:
        Server(std::string host_ip, int port, std::string name);

        void connection();
        void read();
        void send(std::string);

    private:
        int socketServeur, socketClient;
        sockaddr_in server,client;
        bool clientConnected;  
};

#endif