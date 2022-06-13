#include "Game.hpp"

Game::Game() : m_board() {
    /*std::ifstream file("./conf.cfg");
    if(file) {
        file.seekg(0, std::ios::beg);
        std::string str;
        std::getline(file, str);
        int status = std::stoi(str);
        std::getline(file, str);
        std::string host_ip = str;
        std::getline(file, str);
        int port = std::stoi(str);
        std::getline(file, str);
        std::string name = str;
        
        if(!status) {
            player = new Server(host_ip, port, name);
        } else {
            player = new Client(host_ip, port, name);
        }

    } else {
        std::cout << "[ERREUR] Can't reach configuration file" << std::endl;
    }*/
}

Game::~Game() {}

void Game::update(sf::Time deltaTime) {
    m_board.update(deltaTime);
}

void Game::notify(sf::Mouse::Button, bool clicked) {

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_board);
}