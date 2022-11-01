#include "game.h"

Game::Game()
{
    this->_window.create(sf::VideoMode(1500, 1000), "Black Jack");
}

Game::~Game(){}


void Game::run()
{
    Game_Config game_config;
    game_config.init();
    int i = 0;
    while (this->_window.isOpen())
    {
        sf::Event event;
        while (this->_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
            {
                this->_window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                float x = sf::Mouse::getPosition(this->_window).x;
				float y = sf::Mouse::getPosition(this->_window).y;
                if(!(x>=355 && y>=525 && y<=585 && x<=585)) continue;
                i++;
            }

        }

        this->_window.clear();
        game_config.get_btn().setPosition(355, 525);
        this->_window.draw(game_config.get_btn());
        this->_window.draw(game_config.get_cards()[3][i]);
        this->_window.display();
    }
}