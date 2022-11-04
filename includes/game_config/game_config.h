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
    vector<vector<std::shared_ptr<sf::Texture>>> _cards_texture;
    vector<vector<std::shared_ptr<sf::Sprite>>> _cards;
    
    bool is_init;
public:
    Game_Config();
    ~Game_Config(){}
    void init();
    vector<vector<std::shared_ptr<sf::Sprite>>>& get_cards()
    {
        return Game_Config::_cards;
    }
};




#endif // GAME_CONFIG_H