#include "game_config.h"





Game_Config::Game_Config()
{

}


void Game_Config::init()
{

        
    //this->btn.setTexture(this->_texture);
    //this->btn.setPosition(sf::Vector2f(355.f, 525.f));
    Button::init_btns();




    // initialize size of 2d
    _cards_texture.resize(4);
    for(int i = 0; i < 4; ++i)
    {
        _cards_texture[i].resize(13);
    }
    
    _cards.resize(4);
    for(int i = 0; i < 4; ++i)
    {
        _cards[i].resize(13);
    }









    // creating sprites
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 13; ++j)
        {
            auto ptr = std::make_shared<sf::Texture>();
            _cards_texture[i][j] = ptr;    
        }
    }


    // loading cards
    for(int i = 0; i < 13; ++i)
    {
        string temp = "";

        // get the substring path
        switch (i)
        {
        case 0:
            temp += "ace";
            break;
        case 10:
            temp += "jack";
            break;
        case 11:
            temp += "queen";
            break;
        case 12:
            temp += "king";
            break;
        default:
            temp += to_string(i + 1);
            break;
        }

        string clubs = PATH + temp + CLUBS;
        _cards_texture[0][i]->loadFromFile(clubs);
        
        string diamonds = PATH + temp + DIAMONDS;
        _cards_texture[1][i]->loadFromFile(diamonds);

        string hearts = PATH + temp + HEARTS;
        _cards_texture[2][i]->loadFromFile(hearts);

        string spades = PATH + temp + SPADES;
        _cards_texture[3][i]->loadFromFile(spades);
    }


    // creating sprites
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 13; ++j)
        {
            auto ptr = std::make_shared<sf::Sprite>();
            ptr->setTexture(*_cards_texture[i][j]);
            _cards[i][j] = ptr;
        }
    }



}




