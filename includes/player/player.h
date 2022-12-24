#ifndef PLAYER_H
#define PLAYER_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

class Player
{
private:
    int _bet;
    int _points;
public:
    Player();
    ~Player();
    void set_points();
    int get_points();
    int get_bet();
};


#endif