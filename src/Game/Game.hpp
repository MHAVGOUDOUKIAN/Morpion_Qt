#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

#include "../Engine/EventHandler.hpp"

#include "User.hpp"
#include "Client.hpp"
#include "Server.hpp"
#include "Board.hpp"

#include "MessageDisplayer.hpp"

class Engine;

class Game : public sf::Drawable, public MouseObserver{
    public:
        Game();
        virtual ~Game();
        void update(sf::Time deltaTime);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void notify(sf::Mouse::Button, sf::Vector2i&, bool clicked);
        void parseMessage(std::string msg);

    private:
        MessageDisplayer* m_msg;
        Board m_board;
        User* player;        
};

#endif