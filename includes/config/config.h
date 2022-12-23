#ifndef CONFIG_H
#define CONFIG_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;




enum FONTS
{
    // ADD MORE FONTS HERE
    ARIAL = 0,
};


// windows
// ADD WINDOWS CONFIG VARIABLE HERE
const int WINDOW_HEIGHT = 1000;
const int WINDOW_WIDTH = 1200;
const int INPUT_BOX_FONT_SIZE = 24;
const int CHAR_LIMIT = 15;
const string PATH = "../assets/";
const string CLUBS = "_of_clubs.png";
const string DIAMONDS = "_of_diamonds.png";
const string HEARTS = "_of_hearts.png";
const string SPADES = "_of_SPADES.png";


// system variable config
// ADD SYSTEM  VARIABLE HERE
const sf::Vector2f INPUT_BOX_SIZE = sf::Vector2f(300, 100);
const sf::Vector2f INPUT_BOX_POS = sf::Vector2f(680, 840);




class Config
{
private:
    std::unordered_map<string, std::shared_ptr<sf::Texture>> _texture_map;
    std::unordered_map<int, std::shared_ptr<sf::Font>> _font_map;
    std::shared_ptr<sf::Font> _get_font(int key);
    std::shared_ptr<sf::Texture> _get_texture(string key);
    void _set_texture();
    void _set_font();
public:
    Config();
    ~Config();
    sf::Texture& get_texture(string index);
    sf::Font& get_font(int index);
};












#endif