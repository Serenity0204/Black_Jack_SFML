#ifndef USER_H
#define USER_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "../card_deck/card.h"
#include "../config/config.h"
using namespace std;

int _calculate_points(vector<Card>& cards);

class User
{   
public:
    User();
    ~User();
    int calculate_points(vector<Card>& cards);
};








#endif