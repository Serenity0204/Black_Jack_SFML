#include "dealer.h"



Dealer::Dealer(){}

Dealer::~Dealer(){}

int Dealer::calculate_points(vector<Card>& cards)
{
    int points = User::calculate_points(cards);
    return points; 
}
