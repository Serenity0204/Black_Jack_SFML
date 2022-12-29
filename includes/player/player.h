#ifndef PLAYER_H
#define PLAYER_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../card_deck/card.h"
#include "../config/config.h"
#include "../logic/logic.h"
using namespace std;

class Player
{
private:
    int _bet;
    int _points;
public:
    Player();
    ~Player();
    void calculate_points(vector<Card>& cards);
    void set_bet(int amount, bool did_lose=false);
    void reset();
    int get_points();
    int get_bet();
    
};


#endif