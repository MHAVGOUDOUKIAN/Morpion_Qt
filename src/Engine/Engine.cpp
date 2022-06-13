#include "Engine.hpp"

using namespace std;

Engine::Engine(): m_window(sf::VideoMode(800,600), "Application SFML"), m_eventHandler(EventHandler::getEventHandler()), m_g()
{
    srand(time(0));

    TimePerFrame = sf::seconds(1.f/120.f);
    m_window.setFramerateLimit(120); // Apparition de certains artefacts graphiques mais réduit l'utilisation du CPU
    m_window.setKeyRepeatEnabled(false);

    EventHandler::getEventHandler()->addKeyBoardObserver(this);
    EventHandler::getEventHandler()->addEventObserver(this);
}

void Engine::run()
{
    m_timer.add("Clock1");
    sf::Time timeSinceLastUpdate = m_timer.restart("Clock1");

    while (m_window.isOpen())
    {
        m_eventHandler->processEvents(m_window); // On détermine les actions relatives aux events à exécuter à la prochaine frame
        timeSinceLastUpdate += m_timer.restart("Clock1");
        while (timeSinceLastUpdate > TimePerFrame)
        {
            m_eventHandler->processEvents(m_window); // On détermine les actions relatives aux events à exécuter à la prochaine frame
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame);
        }
        render();
    }
}

void Engine::notify(sf::Keyboard::Key key, bool pressed) {
    if(key == sf::Keyboard::Escape) {
        m_window.close();
    }
}

void Engine::notify(sf::Event m_event) {
    if(m_event.type == sf::Event::Closed) {
        m_window.close();
    }
}

void Engine::update(sf::Time deltaTime)
{
    m_g.update(deltaTime);
}

void Engine::render(void)
{
    m_window.clear();
    m_window.draw(m_g);
    m_window.display();
}

Engine::~Engine(){}
