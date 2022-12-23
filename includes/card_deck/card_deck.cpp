#include "card_deck.h"

void CardDeck::_init_cards()
{
    for(int i = 1; i <= 13; ++i)
    {
        Card spade_card("s", i);
        this->_cards["s" + to_string(i)] = spade_card;

        Card heart_card("h", i);
        this->_cards["h" + to_string(i)] = heart_card;

        Card diamond_card("d", i);
        this->_cards["d" + to_string(i)] = diamond_card;

        Card club_card("c", i);
        this->_cards["c" + to_string(i)] = club_card;
    }
}


CardDeck::CardDeck()
{
    this->_init_cards();
}

CardDeck::~CardDeck(){}


string CardDeck::_rand_card()
{
    int rand_suit = rand() % 4;
    int rand_rank = rand() % 13 + 1;

    string card = "";
    switch (rand_suit)
    {
    case 0:
        card += "s";
        break;
    case 1:
        card += "c";
        break;
    case 2:
        card += "d";
        break;
    case 3:
        card += "h";
        break;
    default:
        break;
    }

    card += to_string(rand_rank);
    return card;
}

Card CardDeck::draw_card()
{
    string card_hash = this->_rand_card();
    return this->_cards[card_hash];
}