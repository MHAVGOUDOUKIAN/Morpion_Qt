#include "EventHandler.hpp"

EventHandler* EventHandler::_instance=0;

EventHandler::EventHandler() {}

void EventHandler::processEvents(sf::RenderWindow& targetWindow)
{
    sf::Event m_event;
    while(targetWindow.pollEvent(m_event))
    {
        switch(m_event.type) {
            case sf::Event::KeyPressed:
                for(KeyBoardObserver* ko: m_VKO) { ko->notify(m_event.key.code, true); }
                break;

            case sf::Event::KeyReleased:
                for(KeyBoardObserver* ko: m_VKO) ko->notify(m_event.key.code, false);
                break;

            case sf::Event::MouseButtonPressed:
                for(MouseObserver* mo: m_VMO) mo->notify(m_event.mouseButton.button, true);
                break;

            case sf::Event::MouseButtonReleased:
                for(MouseObserver* mo: m_VMO) mo->notify(m_event.mouseButton.button, false);
                break;

            case sf::Event::LostFocus:
                callResetCommand();
                break;
            
            case sf::Event::Closed:
                for(EventObserver* eo: m_VEO) eo->notify(m_event);
                break;
        }
    }
}

void EventHandler::addKeyBoardObserver(KeyBoardObserver* obj) { m_VKO.push_back(obj); }
void EventHandler::addMouseObserver(MouseObserver* obj) { m_VMO.push_back(obj); }
void EventHandler::addEventObserver(EventObserver* obj) { m_VEO.push_back(obj); }

void EventHandler::callResetCommand() {
    for(KeyBoardObserver* ko: m_VKO) ko->reset();
    for(MouseObserver* mo: m_VMO) mo->reset();
    for(EventObserver* eo: m_VEO) eo->reset();
}


EventHandler* EventHandler::getEventHandler() {
    if(_instance == nullptr) _instance = new EventHandler();
    return _instance;
}

EventHandler::~EventHandler() {}
