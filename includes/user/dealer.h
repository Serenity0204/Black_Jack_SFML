#ifndef DEALER_H
#define DEALER_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "user.h"
using namespace std;

class Dealer : public User
{   
public:
    Dealer();
    ~Dealer();
    int calculate_points(vector<Card>& cards);
};


#endif