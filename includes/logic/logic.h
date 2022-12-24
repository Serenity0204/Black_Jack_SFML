#ifndef LOGIC_H
#define LOGIC_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

class Logic
{
private:
public:
    Logic();
    ~Logic();
    bool check_user_busted(int points);
    bool check_user_black_jack(int points);
    bool check_tie(int user_points, int dealer_points);
    bool check_user_win(int user_points, int dealder_points);
};


#endif