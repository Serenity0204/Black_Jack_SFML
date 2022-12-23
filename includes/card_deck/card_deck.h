#ifndef CARD_DECK_H
#define CARD_DECK_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "card.h"
using namespace std;


class CardDeck
{
private:
    unordered_map<string, Card> _cards;
    void _init_cards();
    string _rand_card();
public:
    CardDeck();
    ~CardDeck();
    Card draw_card();
};


#endif