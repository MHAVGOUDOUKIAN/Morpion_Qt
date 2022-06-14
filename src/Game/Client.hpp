#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "User.hpp"

class Client : public User{
    public:
        Client(std::string host_ip, int port, std::string name);

        void connection();
        void read();
        void send(std::string);

    private:
        int socket;
        hostent* m_host;
        sockaddr_in host_addr;
};

#endif