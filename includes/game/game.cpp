#include "game.h"

Game::Game()
{
    this->window.create(sf::VideoMode(1500, 1000), "Black Jack");
}

Game::~Game(){}


void Game::run()
{
    sf::RectangleShape shape(sf::Vector2f(200, 40));
    shape.setFillColor(sf::Color::Green);
    //this->init();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}