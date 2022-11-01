#include "game.h"

Game::Game(sf::RenderWindow& window)
{
    window.create(sf::VideoMode(1500, 1000), "Black Jack");
}

Game::~Game(){}


void Game::run()
{
}