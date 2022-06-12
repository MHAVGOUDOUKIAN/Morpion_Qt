#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Observer.hpp"

class EventHandler {
    public:
        void processEvents(sf::RenderWindow& targetWindow);
        virtual void addKeyBoardObserver(KeyBoardObserver* obj);
        virtual void addMouseObserver(MouseObserver* obj);
        virtual void addEventObserver(EventObserver* obj);
        static EventHandler* getEventHandler();
        void callResetCommand();

    private:
        ~EventHandler();
        EventHandler();
        std::vector<KeyBoardObserver*> m_VKO;
        std::vector<MouseObserver*> m_VMO;
        std::vector<EventObserver*> m_VEO;
        static EventHandler* _instance;
};

#endif