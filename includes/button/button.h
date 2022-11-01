#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;


const int BUTTON_ARRAY_SIZE = 1;


class Button
{
private:
    static vector<sf::Sprite> _btns;
    static vector<sf::Texture> _textures;
    sf::Texture _texture;
    sf::Sprite _btn;
public:
    Button(string path, float x_pos, float y_pos);
    ~Button();
    static vector<sf::Sprite>& get_btns()
    {
        return Button::_btns;
    }

    static void init_btns()
    {

    }
};





#endif // BUTTON_H