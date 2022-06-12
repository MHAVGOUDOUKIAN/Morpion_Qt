#include "Game.hpp"

Game::Game() {
    std::ifstream file("./conf.cfg");
    if(file) {
        std::string str;
        while(std::getline(file,str)) {
        }
    } else {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;

    }
}

Game::~Game() {}

void Game::update(sf::Time deltaTime) {}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {}