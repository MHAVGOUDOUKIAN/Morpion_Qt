#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "User.hpp"

class Game;

class Client : public User{
    public:
        Client(Game* obj, std::string host_ip, int port, std::string name);
        virtual ~Client();

        void connection();
        void read();
        virtual void send(std::string);

    private:
        int socket;
        hostent* m_host;
        sockaddr_in host_addr;
};

#endif