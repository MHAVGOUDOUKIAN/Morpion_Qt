#include "Board.hpp"

Board::Board() : lines(3), rows(3), m_board(lines*rows, false), m_vertex(sf::Quads, lines*rows*4+4) {
    m_vertex[m_vertex.getVertexCount()*4-4].position=sf::Vector2f(0,0);
    m_vertex[m_vertex.getVertexCount()*4-3].position=sf::Vector2f(800,0);
    m_vertex[m_vertex.getVertexCount()*4-2].position=sf::Vector2f(800,600);
    m_vertex[m_vertex.getVertexCount()*4-1].position=sf::Vector2f(0,600);

    m_vertex[m_vertex.getVertexCount()*4-4].color = sf::Color(248, 249, 202);
    m_vertex[m_vertex.getVertexCount()*4-3].color = sf::Color(248, 249, 202);
    m_vertex[m_vertex.getVertexCount()*4-2].color = sf::Color(248, 249, 202);
    m_vertex[m_vertex.getVertexCount()*4-1].color = sf::Color(248, 249, 202);

    m_texture->loadFromFile("./src/assets/signs.png");
}

Board::~Board() {}

void Board::set(int x, int y, bool value) {
    if(x<lines && x>=0 && y<rows && y>=0) {
        m_board[y*lines+ x]=value;
        std::cout << "settings" << true << std::endl;
    }
}

void Board::clear() {
    m_board.clear();
    m_board = std::vector<bool>(lines*rows, false);
}

void Board::update(sf::Time deltaTime) {
    
    renderBoard();
}

void Board::show() const {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<lines; j++) {
            std::cout << m_board[i*lines+ j];
        }    
        std::cout << std::endl;
    }   
    std::cout << std::endl;
}

void Board::renderBoard() {

}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {

}