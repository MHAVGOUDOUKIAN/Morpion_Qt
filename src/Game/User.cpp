#include "User.hpp"

User::User(std::string h, int p, std::string n) : ipToCo(h), port(p), name(n){}

int User::getStatus() { return status; }

User::~User() {
    if(initConnect!=nullptr) { initConnect->detach(); };
    if(receive!=nullptr) { receive->detach(); };
}