#include "card.h"

Config Card::_config = Config();

Card::Card(){}

Card::Card(string suit, int rank)
{
    this->_rank = rank;
    this->_suit = suit;
    this->_card = sf::Sprite();
    
}

Card::~Card(){}

string Card::get_card_hash()
{
    string hash = this->_suit + to_string(this->_rank);
    //cout << hash << endl;
    return hash;
}


void Card::set_card_position(sf::Vector2f pos)
{
    this->_card.setPosition(pos);
}


void Card::drawTo(sf::RenderWindow &window)
{
    string hash = this->get_card_hash();
    this->_card.setTexture(Card::_config.get_texture(hash));
    window.draw(this->_card);
}