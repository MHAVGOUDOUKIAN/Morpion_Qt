#include "User.hpp"
#include "Game.hpp"

User::User(Game* gmobj, std::string h, int p, std::string n) : gameObject(gmobj), ipToCo(h), port(p), name(n), mustPlay(false) {}

int User::getStatus() { return status; }

User::~User() {
    if(initConnect!=nullptr) { initConnect->detach(); };
    if(receive!=nullptr) { receive->detach(); };
}