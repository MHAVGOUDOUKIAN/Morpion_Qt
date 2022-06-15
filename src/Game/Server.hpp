#ifndef SERVER_HPP
#define SERVER_HPP

#include "User.hpp"

class Game;

class Server : public User {
    public:
        Server(Game* obj, std::string host_ip, int port, std::string name);
        virtual ~Server();

        void connection();
        void read();
        virtual void send(std::string);

    private:
        int socketServeur, socketClient;
        sockaddr_in server,client;
        bool clientConnected;  
};

#endif