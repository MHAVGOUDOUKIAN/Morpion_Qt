#ifndef USER_HPP
#define USER_HPP

#include <iostream>

class User {
    public:
        User(std::string h, int p, std::string n);
    
        void connection();
        void read();
        void write();

    protected:
        std::string ipToCo;
        int port;
        std::string name;
};

#endif