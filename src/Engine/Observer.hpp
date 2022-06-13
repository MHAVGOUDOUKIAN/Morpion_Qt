#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <SFML/Graphics.hpp>

class KeyBoardObserver {
    public:
        virtual ~KeyBoardObserver() {}
        virtual void notify(sf::Keyboard::Key, bool pressed) =0;
        virtual void reset() {}
};

class MouseObserver {
    public:
        virtual ~MouseObserver() {}
        virtual void notify(sf::Mouse::Button, sf::Vector2i&, bool clicked) =0;
        virtual void reset() {}
};

class EventObserver {
    public:
        virtual ~EventObserver() {}
        virtual void notify(sf::Event) =0;
        virtual void reset() {}
};

#endif