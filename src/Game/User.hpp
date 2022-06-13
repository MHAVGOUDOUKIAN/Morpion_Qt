#ifndef USER_HPP
#define USER_HPP

#include <iostream>

class User {
    public:
        User(std::string h, int p, std::string n);
    
        void connect();
        void read();
        void write();

    protected:
        std::string host_ip;
        int port;
        std::string name;
};

#endif