#include "button.h"

vector<sf::Sprite> Button::_btns;
vector<sf::Texture> Button::_textures;

Button::Button(string path, float x_pos, float y_pos)
{
    this->_texture.loadFromFile(path);
    this->_btn.setTexture(this->_texture);
    this->_btn.setPosition(sf::Vector2f(x_pos, y_pos));
    Button::_btns.resize(1);
    Button::_btns[0] = this->_btn;
    Button::_textures.resize(1);
    Button::_textures[0] = this->_texture;
}


Button::~Button(){}

// initializing static private member




