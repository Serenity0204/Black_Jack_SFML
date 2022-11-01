#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "../game_config/game_config.h"
using namespace std;




class Game
{
private:
    sf::RenderWindow _window;
public:
    Game();
    ~Game();

    // main loop
    void run();
};






#endif // !GAME_H