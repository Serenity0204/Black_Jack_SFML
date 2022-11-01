#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;


const string PATH = "../assets/";
const string CLUBS = "_of_clubs.png";
const string DIAMONDS = "_of_diamonds.png";
const string HEARTS = "_of_hearts.png";
const string SPADES = "_of_SPADES.png";




class Game_Config
{
private:
    vector<sf::Sprite> btn;
    vector<vector<sf::Texture>> cards_holder;
    vector<vector<sf::Sprite>> cards;
    vector<sf::Texture> bets;
public:

    Game_Config();
    ~Game_Config(){}
    void init();
    sf::Sprite& get_btn()
    {
        return this->btn[0];
    }
    vector<vector<sf::Sprite>>& get_cards();
};




#endif // GAME_CONFIG_H