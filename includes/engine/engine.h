#ifndef ENGINE_H
#define ENGINE_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../config/config.h"

using namespace std;


class Engine 
{
private:
    // sfml private members here
    sf::RenderWindow _window;

    // system setup here
    Config _config;

    // private member variables here


    // private helper functions here


public:
    // constructors and destructors
    Engine();
    ~Engine();
    
    // game processing
    void input();
    void run();
    void display();
};




#endif