#include "Client.hpp"

Client::Client(std::string host_ip, int port, std::string name) : User(host_ip, port, name) {
    std::cout << "Client" << std::endl;
}

void Client::connection() {
    socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if(socket<0) { std::cout << "> [ERROR] Can't init socket" << std::endl;}

    m_host = gethostbyname(ipToCo.c_str());
    if(m_host == nullptr) { std::cout << "> [ERROR] No such host" << std::endl; }

    bzero((char*)&host_addr, sizeof(host_addr));
    host_addr.sin_family = AF_INET;
    bcopy((char*) m_host->h_addr, (char*)&host_addr.sin_addr.s_addr, m_host->h_length);
    host_addr.sin_port = htons(port);

    std::cout << "> Connected to: " << ipToCo.c_str() << std::endl;

    if(connect(socket, (struct sockaddr *) &host_addr, sizeof(host_addr)) < 0) { 
        std::cout << "> [ERROR] Connection impossible" << std::endl;
    }
}

void Client::read() {

}

void Client::write() {

}