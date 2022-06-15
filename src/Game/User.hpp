#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <string.h>
#include <thread>

class Game;

class User {
    public:
        User(Game* gmobj, std::string h, int p, std::string n);
        virtual ~User();

        void connection();
        void read();
        virtual void send(std::string)=0;
        int getStatus();

    public:
        bool mustPlay;

    protected:
        Game* gameObject;
        int status; // 0 = serveur / 1 = client
        std::string ipToCo;
        
        int port;
        std::string name;
        
        std::thread* initConnect;
        std::thread* receive;
        std::string msgReceived{""};


};

#endif