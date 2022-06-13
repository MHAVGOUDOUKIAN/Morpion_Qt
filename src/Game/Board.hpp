#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

class Board : public sf::Drawable{
    public:
        Board();
        virtual ~Board();
        void set(int x, int y, bool value=true);
        void clear();
        void renderBoard();
        void update(sf::Time deltaTime);
        void show() const ;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        int lines;
        int rows;
        std::vector<bool> m_board;
        sf::VertexArray m_vertex;
        sf::Texture* m_texture;
};

#endif