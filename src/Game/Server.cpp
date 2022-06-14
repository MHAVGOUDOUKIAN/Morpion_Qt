#include "Server.hpp"

Server::Server(std::string host_ip, int port, std::string name) : User(host_ip, port, name), clientConnected(false) {
    status = 0;
    std::cout << "Serveur" << std::endl;
    std::cout << "Connecting .." << std::endl;
    socklen_t clientLenght = sizeof(client);

    socketServeur= socket(AF_INET, SOCK_STREAM, 0);
    if(socketServeur==-1) { 
        std::cout << "> [ERROR] can't init socket" << std::endl;
    }

    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (bind(socketServeur, (struct sockaddr *) &server, sizeof(server)) == -1) { 
        std::cout << "[ERROR] port already used " << std::endl;   
    }

    listen(socketServeur,1);
    initConnect = new std::thread(&Server::connection, this);
}

void Server::connection() {
    socklen_t clientLenght = sizeof(client);
    int newClientSocket = accept(socketServeur, (struct sockaddr *) &client, &clientLenght);
    std::cout << "Checking connection status" << std::endl;
    if( newClientSocket< 0) {
        std::cout << "> [ERROR] Error on accept" << std::endl;
    }
    else if(clientConnected) {
        std::cout << "> Can't accept more client" << std::endl;
        close(newClientSocket);
    } 
    else {
        clientConnected=true;
        socketClient = newClientSocket;
        std::cout << "A client just connected" << std::endl;

    }

    receive = new std::thread(&Server::read, this);
}

void Server::read() {
    int n;
    char buffer[256];
    bzero(buffer, 255);
    n = ::read(socketClient, buffer, sizeof(buffer)); // -1 to avoid EOF
    if(n<0) std::cout << "> [ERROR] Cannot receive messages" << std::endl;
    msgReceived = buffer;
}

void Server::send(std::string msg) {
    int n;
    n = write(socketClient, msg.c_str(), msg.length());
    if(n<0) std::cout << "> [ERROR] Cannot send messages" << std::endl;
}