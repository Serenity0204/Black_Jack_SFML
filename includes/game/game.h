#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "../game_config/game_config.h"
using namespace std;




class Game
{
private:
    sf::RenderWindow window;
public:
    vector<vector<sf::Texture>> cards_holder;
    vector<vector<sf::Sprite>> cards;
    vector<sf::Texture> bets;

    Game();
    ~Game();
    void init()
    {
        //     // creating sprites
    for(int i = 0; i < 4; ++i)
    {
        sf::Texture t;
        for(int j = 0; j < 13; ++j)
        {
            cards_holder[i].push_back(t);    
        }
    }


    // loading cards
    for(int i = 0; i < 13; ++i)
    {
        string temp = "";

        // get the substring path
        switch (i)
        {
        case 0:
            temp += "ace";
            break;
        case 10:
            temp += "jack";
            break;
        case 11:
            temp += "queen";
            break;
        case 12:
            temp += "king";
            break;
        default:
            temp += to_string(i + 1);
            break;
        }

        string clubs = PATH + temp + CLUBS;
        cards_holder[0][i].loadFromFile(clubs);
        
        string diamonds = PATH + temp + DIAMONDS;
        cards_holder[1][i].loadFromFile(diamonds);

        string hearts = PATH + temp + HEARTS;
        cards_holder[2][i].loadFromFile(hearts);

        string spades = PATH + temp + SPADES;
        cards_holder[3][i].loadFromFile(spades);
    }


    // creating sprites
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 13; ++j)
        {
            sf::Sprite sprite(cards_holder[i][j]);
            cards[i].push_back(sprite);
        }
    }
    }
    // main loop
    void run();
};






#endif // !GAME_H