#include "button.h"


Button::Button(string path, float x_pos, float y_pos)
{
    this->_texture.loadFromFile(path);
    this->btn.setTexture(this->_texture);
    this->btn.setPosition(sf::Vector2f(x_pos, y_pos));
}


Button::~Button()
{

}