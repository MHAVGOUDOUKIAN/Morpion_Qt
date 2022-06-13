#include "Client.hpp"

Client::Client(std::string host_ip, int port, std::string name) : User(host_ip, port, name) {
    std::cout << "Client" << std::endl;
}