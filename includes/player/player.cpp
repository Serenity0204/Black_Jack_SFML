#include "player.h"


Player::Player()
{
    this->_bet = 2500;
    this->_points = 0;
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


void Player::reset()
{
    this->_points = 0;
}

void Player::calculate_points(vector<Card>& cards)
{
    int ace_count = 0;
    int total = 0;
    for(int i = 0; i < cards.size(); ++i)
    {
        int rank = cards[i].get_card_rank();

        if(rank == ACE && i <= 1)
        {
            ace_count++;
            continue;
        }

        if(rank >= ACE && rank <= TEN)
        {
            total += rank;
            continue;
        }
        if(rank == JACK || rank == QUEEN || rank == KING)
        {
            total += TEN;
            continue;
        }
    }
    bool busted = (total + 11) > 21;
    if(ace_count == 1 && !busted) total += 11;
    if(ace_count == 1 && busted) total += 1;
    
    busted = (total + 11 + 1) > 21;
    if(ace_count == 2 && !busted) total += 12;
    if(ace_count == 2 && busted) total += 2;

    this->_points = total;
    cards.clear();
}




int Player::get_points()
{
    int points = this->_points;
    this->reset();
    return points;
}

int Player::get_bet()
{
    return this->_bet;
}