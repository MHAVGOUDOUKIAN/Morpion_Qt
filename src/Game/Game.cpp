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
            player = new Server(this, host_ip, port, name);
        } else {
            player = new Client(this, host_ip, port, name);
        }

    } else {
        std::cout << "[ERREUR] Can't reach configuration file" << std::endl;
    }
    EventHandler::getEventHandler()->addMouseObserver(this);
    std::cout  << "plpayer created" << std::endl;
}

Game::~Game() { if(player != nullptr) delete player; }

void Game::update(sf::Time deltaTime) {
    m_board.update(deltaTime);
}

void Game::notify(sf::Mouse::Button mouse, sf::Vector2i& pos, bool clicked) {
    if(mouse == sf::Mouse::Button::Left) {
        if(clicked && player->mustPlay) {
            int x{pos.x/(800/m_board.getLines())};
            int y{pos.y/(600/m_board.getLines())};
            if(m_board.get(x,y)==0){
                player->mustPlay=false;
                std::string msg="PLAY:";
                msg+=std::to_string(x)+":";
                msg+=std::to_string(y)+":";
                msg+=std::to_string(player->getStatus()+1);
                player->send(msg);
                m_board.set(x, y, player->getStatus()+1);
            }
        }
    }
    
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
    if(l_cmd.size()>0) {
        if(l_cmd[0]=="PLAY") {
            player->mustPlay=true;
            m_board.set(std::stoi(l_cmd[1]), std::stoi(l_cmd[2]), std::stoi(l_cmd[3]));
            if(m_board.checkWhoWin() >0) { m_board.clear();}
        }
        else if(l_cmd[0]=="BEGIN") {
            if(std::stoi(l_cmd[1])==0) { player->mustPlay=false;}
            else { player->mustPlay=true;}
        }
    }
}