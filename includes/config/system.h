#ifndef SYSTEM_H
#define SYSTEM_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;



enum FONTS
{
    // ADD MORE FONTS HERE
    ARIAL = 0,
};


enum ACTION_CODE
{
    INVALID = -1,
    HIT = 0,
    STAND = 1,
    ANOTHER_GAME= 2,
};


enum RANKS
{
    ACE = 1,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
};



// windows
// ADD WINDOWS CONFIG VARIABLE HERE
const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 1200;
const int INPUT_BOX_FONT_SIZE = 24;
const int HEADER_FONT_SIZE = 35;
const int CHAR_LIMIT = 4;
const int MAX_CARDS = 5;



// const string for path  
const string PATH = "../assets/";
const string CLUBS = "_of_clubs.png";
const string DIAMONDS = "_of_diamonds.png";
const string HEARTS = "_of_hearts.png";
const string SPADES = "_of_spades.png";
const string PNG = ".png";


// system variable config
// ADD SYSTEM  VARIABLE HERE
const string WELCOME_MESSAGE = "Enter the bet to proceed";
const string WIN_MESSAGE = "You Win! Play Again?";
const string LOSE_MESSAGE = "You Lose! Play Again?";
const string DRAW_MESSAGE = "It's a Draw! Play Again?";
const string BROKE_MESSAGE = "YOU LOST ALL OF YOUR BET, BROKIE!";

const sf::Vector2f INPUT_BOX_SIZE = sf::Vector2f(75, 35);
const sf::Vector2f INPUT_BOX_POS = sf::Vector2f(1100, 400);
const sf::Vector2f HEADER_SIZE = sf::Vector2f(400, 50);
const sf::Vector2f HEADER_POS = sf::Vector2f(10, 250);






#endif