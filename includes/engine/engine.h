#ifndef ENGINE_H
#define ENGINE_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../config/config.h"
#include "../input_box/input_box.h"
#include "../button/button.h"
#include "../card_deck/card_deck.h"
using namespace std;


class Engine 
{
private:
    // sfml private members here
    sf::RenderWindow _window;

    // system setup here
    Config _config;
    InputBox _input_box;
    CardDeck _card_deck;

    // private member variables here
    vector<Card> _current_cards;
    vector<Button> _buttons;
    
    // private helper functions here
    
    void _update_input_box();
    void _draw_constant_text();

    void _init_buttons();
    void _draw_button();
    void _update_buttons(sf::Event& event);
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