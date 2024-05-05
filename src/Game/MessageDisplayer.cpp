#include "MessageDisplayer.hpp"

MessageDisplayer::MessageDisplayer(User* ptr_to_player) : m_Ptr_To_Player(ptr_to_player) {
    m_font.loadFromFile("./src/assets/AldotheApache.ttf");
    m_text.setFont(m_font);
    m_text.setCharacterSize(18);
    m_text.setFillColor(sf::Color::Black);
    m_text.setPosition(sf::Vector2f(0,0));
}

MessageDisplayer::~MessageDisplayer() {}

void MessageDisplayer::update() {
    if(m_Ptr_To_Player->playerMustPlay()) m_text.setString("C'est votre tour ! Choisissez une case");
    else m_text.setString("En attente de votre adversaire..");
}

void MessageDisplayer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_text);
}