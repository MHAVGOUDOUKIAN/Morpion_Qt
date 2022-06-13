#include "Board.hpp"

Board::Board() : lines(3), rows(3), m_board(lines*rows, 0), m_vertex(sf::Quads, lines*rows*4), m_fond(sf::Quads, 4) {
    m_texture.loadFromFile("./src/assets/signs.png");

    m_fond[0].position = sf::Vector2f(0,0);
    m_fond[1].position = sf::Vector2f(800,0);
    m_fond[2].position = sf::Vector2f(800,600);
    m_fond[3].position = sf::Vector2f(0,600);

    m_fond[0].color = sf::Color(250,254, 156);
    m_fond[1].color = sf::Color(250,254, 156);
    m_fond[2].color = sf::Color(250,254, 156);
    m_fond[3].color = sf::Color(250,254, 156);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<lines; j++) {
            m_vertex[(i*lines+ j)*4].position = sf::Vector2f(i*800/lines, j*600/rows);
            m_vertex[(i*lines+ j)*4+1].position = sf::Vector2f((i+1)*800/lines, j*600/rows);
            m_vertex[(i*lines+ j)*4+2].position = sf::Vector2f((i+1)*800/lines, (j+1)*600/rows);
            m_vertex[(i*lines+ j)*4+3].position = sf::Vector2f(i*800/lines, (j+1)*600/rows);
        }    
    }   
}

Board::~Board() {}

void Board::set(int x, int y, short value) { if(x<lines && x>=0 && y<rows && y>=0) m_board[x*lines+ y]=value; }

void Board::clear() {
    m_board.clear();
    m_board = std::vector<short>(lines*rows, 0);
}

void Board::update(sf::Time deltaTime) { renderBoard(); }

void Board::show() const {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<lines; j++) {
            std::cout << m_board[i*lines+ j];
        }    
        std::cout << std::endl;
    }   
    std::cout << std::endl;
}

int Board::getLines() { return lines;}
int Board::getRows() { return rows; }

int Board::checkWhoWin() {
    
    //Diagonale
    if(get(0,0) != 0 ) if(get(0,0) == get(1,1) && get(0,0) == get(2,2)) return get(0,0);
    if(get(0,2) != 0 ) if(get(0,2) == get(1,1) && get(0,2) == get(2,0)) return get(0,2);

    //Colonnes
    if(get(0,0) != 0 ) if(get(0,0) == get(1,0) && get(0,0) == get(2,0)) return get(0,0);
    if(get(0,1) != 0 ) if(get(0,1) == get(1,1) && get(0,1) == get(2,1)) return get(0,1);
    if(get(0,2) != 0 ) if(get(0,2) == get(1,2) && get(0,2) == get(2,2)) return get(0,2);

    //Colonnes
    if(get(0,0) != 0 ) if(get(0,0) == get(0,1) && get(0,0) == get(0,2)) return get(0,0);
    if(get(1,0) != 0 ) if(get(1,0) == get(1,1) && get(1,0) == get(1,2)) return get(1,0);
    if(get(2,0) != 0 ) if(get(2,0) == get(2,1) && get(2,0) == get(2,2)) return get(2,0);

    return -1;
}

short Board::get(int x, int y) {
    return m_board[x*lines+ y];
}

void Board::renderBoard() {
    for(int i=0; i<rows*lines; i++) {
        if(m_board[i]==1) {
            m_vertex[i*4].texCoords = sf::Vector2f(0,0);
            m_vertex[i*4+1].texCoords = sf::Vector2f(64,0);
            m_vertex[i*4+2].texCoords = sf::Vector2f(64,64);
            m_vertex[i*4+3].texCoords = sf::Vector2f(0,64);
        }
        else if(m_board[i]==2) {
            m_vertex[i*4].texCoords = sf::Vector2f(64,0);
            m_vertex[i*4+1].texCoords = sf::Vector2f(128,0);
            m_vertex[i*4+2].texCoords = sf::Vector2f(128,64);
            m_vertex[i*4+3].texCoords = sf::Vector2f(64,64);
        } 
        else {
            m_vertex[i*4].texCoords = sf::Vector2f(0,0);
            m_vertex[i*4+1].texCoords = sf::Vector2f(0,0);
            m_vertex[i*4+2].texCoords = sf::Vector2f(0,0);
            m_vertex[i*4+3].texCoords = sf::Vector2f(0,0);
        }
    }
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_fond);
    target.draw(m_vertex, &m_texture);
}