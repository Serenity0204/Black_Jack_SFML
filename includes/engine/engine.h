#ifndef ENGINE_H
#define ENGINE_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../config/config.h"
#include "../input_box/input_box.h"
#include "../button/buttons.h"
#include "../card_deck/card_deck.h"
#include "../header/header.h"
#include "../logic/logic.h"
#include "../player/player.h"
using namespace std;


class Engine 
{
private:
    // sfml private members here
    sf::RenderWindow _window;

    // system setup here
    InputBox _input_box;
    CardDeck _card_deck;
    Buttons _buttons;
    Header _header;
    Player _player;

    // private member variables here
    bool _entered_bet;
    vector<Card> _current_cards;

    

    
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