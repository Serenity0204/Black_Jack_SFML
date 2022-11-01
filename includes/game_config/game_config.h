#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "../button/button.h"
using namespace std;


const string PATH = "../assets/";
const string CLUBS = "_of_clubs.png";
const string DIAMONDS = "_of_diamonds.png";
const string HEARTS = "_of_hearts.png";
const string SPADES = "_of_SPADES.png";




class Game_Config
{
private:
    vector<vector<sf::Texture>> cards_holder;
    vector<vector<sf::Sprite>> cards;
    vector<Button> buttons;
    
public:
    
    Game_Config();
    ~Game_Config(){}
    void init();
    vector<Button>& get_button();
    vector<vector<sf::Sprite>>& get_cards();
};




#endif // GAME_CONFIG_H