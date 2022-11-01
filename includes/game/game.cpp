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
    while (this->_window.isOpen())
    {
        sf::Event event;
        while (this->_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->_window.close();
        }

        this->_window.clear();
        this->_window.draw(game_config.get_cards()[3][11]);
        this->_window.display();
    }
}