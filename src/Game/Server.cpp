#include "Server.hpp"

Server::Server(std::string host_ip, int port, std::string name) : User(host_ip, port, name) {
    std::cout << "Serveur" << std::endl;
}