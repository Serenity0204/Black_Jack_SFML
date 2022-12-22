#ifndef CONFIG_H
#define CONFIG_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;


enum TEXTURES
{
    // ADD MORE TEXTURES HERE
};

enum FONTS
{
    // ADD MORE FONTS HERE

};


// windows
// ADD WINDOWS CONFIG VARIABLE HERE
const int WINDOW_HEIGHT = 1000;
const int WINDOW_WIDTH = 1200;

// system variable config
// ADD SYSTEM  VARIABLE HERE


class Config
{
private:
    std::unordered_map<int, std::shared_ptr<sf::Texture>> _texture_map;
    std::unordered_map<int, std::shared_ptr<sf::Font>> _font_map;
    std::shared_ptr<sf::Font> _get_font(int key);
    std::shared_ptr<sf::Texture> _get_texture(int key);
    void _set_texture();
    void _set_font();
public:
    Config();
    ~Config();
    sf::Texture& get_texture(int index);
    sf::Font& get_font(int index);
};



#endif