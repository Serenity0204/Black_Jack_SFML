#ifndef PLAYER_H
#define PLAYER_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "user.h"
using namespace std;

class Player : public User
{
private:
    int _bet;
public:
    Player();
    ~Player();
    // from base user class
    int calculate_points(vector<Card>& cards);

    // member functions
    void set_bet(int amount, bool did_lose=false);
    int get_bet();
    int reset();
};


#endif