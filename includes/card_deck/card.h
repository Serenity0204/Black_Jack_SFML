#ifndef CARD_H
#define CARD_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../config/config.h"
using namespace std;


class Card
{
private:
    string _suit;
    int _rank;
    sf::Sprite _card;
    string get_card_hash();
public:
    Card();
    Card(string suit, int rank);
    ~Card();
    int get_card_rank(){return this->_rank;}
    void drawTo(sf::RenderWindow &window);
    void set_card_position(sf::Vector2f pos);
};


#endif