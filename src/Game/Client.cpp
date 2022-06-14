#include "Client.hpp"

Client::Client(std::string host_ip, int port, std::string name) : User(host_ip, port, name) {
    status = 0;
    std::cout << "Client" << std::endl;
    initConnect = new std::thread(&Client::connection, this);
}

void Client::connection() {
    std::cout << "Connecting.." << std::endl;
    socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if(socket<0) { std::cout << "> [ERROR] Can't init socket" << std::endl;}

    m_host = gethostbyname(ipToCo.c_str());
    if(m_host == nullptr) { std::cout << "> [ERROR] No such host" << std::endl; }

    bzero((char*)&host_addr, sizeof(host_addr));
    host_addr.sin_family = AF_INET;
    bcopy((char*) m_host->h_addr, (char*)&host_addr.sin_addr.s_addr, m_host->h_length);
    host_addr.sin_port = htons(port);

    if(connect(socket, (struct sockaddr *) &host_addr, sizeof(host_addr)) < 0) { 
        std::cout << "> [ERROR] Connection impossible" << std::endl;
    } else {
        std::cout << "> Connected to: " << ipToCo.c_str() << std::endl;
    }

    receive = new std::thread(&Client::read, this);
}

void Client::read() {
    int n;
    char buffer[256];
    bzero(buffer, 255);
    n = ::read(socket, buffer, sizeof(buffer)); // -1 to avoid EOF
    if(n<0) std::cout << "> [ERROR] Cannot receive messages" << std::endl;
    msgReceived = buffer;
}

void Client::send(std::string msg) {
    int n;
    n = write(socket, msg.c_str(), msg.length());
    if(n<0) std::cout << "> [ERROR] Cannot send messages" << std::endl;
}