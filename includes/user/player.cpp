#include "player.h"


Player::Player()
{
    this->_bet = 2500;
}

Player::~Player(){}

void Player::set_bet(int amount, bool did_lose)
{
    if(did_lose)
    {
        this->_bet -= amount;
        return;
    }
    this->_bet += amount;
}



int Player::calculate_points(vector<Card>& cards)
{
    int points = User::calculate_points(cards);
    return points;
}




int Player::get_bet()
{
    return this->_bet;
}