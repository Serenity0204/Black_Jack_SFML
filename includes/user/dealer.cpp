#include "dealer.h"



Dealer::Dealer(){}

Dealer::~Dealer(){}

int Dealer::draw_card_AI(vector<Card>& cards, CardDeck card_deck)
{
    int dealer_points = this->calculate_points(cards);
    while(dealer_points <= 17)
    {
        Card c = card_deck.draw_card();
        cards.push_back(c); 
        dealer_points = this->calculate_points(cards);
    }
    return dealer_points;
}


int Dealer::calculate_points(vector<Card>& cards)
{
    int points = User::calculate_points(cards);
    return points; 
}
