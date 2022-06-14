#include "Game.hpp"

Game::Game() : m_board(){
    std::ifstream file("./conf.cfg");
    if(file) {
        file.seekg(0, std::ios::beg);
        std::string str;
        std::getline(file, str);
        int status = std::stoi(str);
        std::getline(file, str);
        std::string host_ip = str;
        std::getline(file, str);
        int port = std::stoi(str);
        std::getline(file, str);
        std::string name = str;
        file.close();

        if(!status) {
            player = new Server(host_ip, port, name);
        } else {
            player = new Client(host_ip, port, name);
        }

    } else {
        std::cout << "[ERREUR] Can't reach configuration file" << std::endl;
    }
    EventHandler::getEventHandler()->addMouseObserver(this);
}

Game::~Game() { if(player != nullptr) delete player; }

void Game::update(sf::Time deltaTime) {
    m_board.update(deltaTime);
}

void Game::notify(sf::Mouse::Button mouse, sf::Vector2i& pos, bool clicked) {
    if(mouse == sf::Mouse::Button::Left) {
        if(clicked) {
            m_board.set(pos.x/(800/m_board.getLines()), pos.y/(600/m_board.getLines()), 1);
        }
    }

    if(mouse == sf::Mouse::Button::Right) {
        if(clicked) {
            m_board.set(pos.x/(800/m_board.getLines()), pos.y/(600/m_board.getLines()), 2);
        }
    }

    if(mouse == sf::Mouse::Button::Middle) {
        if(clicked) {
            m_board.set(pos.x/(800/m_board.getLines()), pos.y/(600/m_board.getLines()), 0);
        }
    }

    m_board.checkWhoWin();

    if(m_board.checkWhoWin() >0) { m_board.clear();}
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_board);
}

void Game::parseMessage(std::string msg) {
    std::vector<std::string> l_cmd;
    std::stringstream strStream(msg);
    std::string str;
    while(std::getline(strStream, str, ':')) { l_cmd.push_back(str); }
    for(int i=0; i<l_cmd.size(); i++) std::cout << l_cmd[i] << std::endl;

    // ces message decrivent l'action de l'autre joueur
    if(l_cmd[0]=="OK"){
        // Reponse neutre
    }
    else if(l_cmd[0]=="PLAY") { 
        // L'autre joueur à joué
    }
    else if(l_cmd[0]=="BEGIN") {
        player->mustPlay=false;
        // l'autre joueur commence à jouer
    }
    else if(l_cmd[0]=="WIN") {

    }
    else if(l_cmd[0]=="RESET") {
        // La partie recommence va recommencer
    }
}