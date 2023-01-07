#ifndef DEALER_H
#define DEALER_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "user.h"
#include "../card_deck/card_deck.h"
using namespace std;

class Dealer : public User
{   
public:
    Dealer();
    ~Dealer();
    int draw_card_AI(vector<Card>& cards, CardDeck card_deck);
    int calculate_points(vector<Card>& cards);
};


#endif