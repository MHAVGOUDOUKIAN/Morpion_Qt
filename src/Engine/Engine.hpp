#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "EventHandler.hpp"
#include "TimeManager.hpp"
#include "../Game/Game.hpp"
#include "Observer.hpp"

class Engine : public KeyBoardObserver, public EventObserver
{
    public:
        Engine();
        virtual ~Engine();

        void run();
        void update(sf::Time deltaTime);
        void render();

        virtual void notify(sf::Keyboard::Key key, bool pressed);
        virtual void notify(sf::Event m_event);

        void addEventListerner();

    private:
        sf::RenderWindow m_window;
        sf::Time TimePerFrame;

        TimeManager m_timer;
        EventHandler* m_eventHandler;

        Game m_g;
};

#endif
