#ifndef MESSAGEDISPLAYER_HPP
#define MESSAGEDISPLAYER_HPP

#include "User.hpp"
#include "SFML/Graphics.hpp"

class MessageDisplayer : public sf::Drawable {
    public:
        MessageDisplayer(User* ptr_to_player);
        ~MessageDisplayer();
        void update();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        User* m_Ptr_To_Player;
        sf::Font m_font;
        sf::Text m_text;

};

#endif