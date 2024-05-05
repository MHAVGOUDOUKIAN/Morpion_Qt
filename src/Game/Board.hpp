#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

class Board : public sf::Drawable{
    public:
        Board(const int x, const int y);
        virtual ~Board();
        void set(int x, int y, short value=0);
        short get(int x, int y);
        void clear();
        void renderBoard();
        int checkWhoWin();
        void update(sf::Time deltaTime);
        void show() const ;

        int getLines();
        int getRows();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        int lines;
        int rows;
        std::vector<short> m_board;
        sf::VertexArray m_vertex;
        sf::VertexArray m_fond;
        sf::Texture m_texture;
};

#endif