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
#include "../user/player.h"
#include "../user/dealer.h"
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
    Dealer _dealer;

    // private member variables here
    bool _entered_bet;
    int _bet;
    vector<Card> _player_cards;
    vector<Card> _dealer_cards;
    

    
    // private helper functions here
    void _init();
    void _update_buttons_event(sf::Event& event);
    void _update_bet_event();
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