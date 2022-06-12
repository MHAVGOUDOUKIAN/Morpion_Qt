#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>
#include <fstream>

class Engine;

class Game : public sf::Drawable{
    public:
        Game();
        virtual ~Game();
        void update(sf::Time deltaTime);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
};

#endif