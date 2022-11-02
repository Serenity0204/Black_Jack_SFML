#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;


const int BUTTON_ARRAY_SIZE = 1;


class Button
{
private:
    static vector<std::shared_ptr<sf::Sprite>> _btns;
    static vector<std::shared_ptr<sf::Texture>> _textures;
public:
    Button(string path, float x_pos, float y_pos);
    ~Button();

    static std::shared_ptr<sf::Sprite> make_texture(const string& path, float x_pos, float y_pos)
    {
        auto ptr = std::make_shared<sf::Texture>();
        ptr->loadFromFile(path);
        Button::_textures.push_back(ptr);
        auto _ptr = std::make_shared<sf::Sprite>();
        _ptr->setTexture(*ptr);
        _ptr->setPosition(sf::Vector2f(x_pos, y_pos));
        Button::_btns.push_back(_ptr);
        return _ptr;
    }
    static std::shared_ptr<sf::Sprite> init_btns()
    {
        const string path = "../assets/stand.png";
        std::shared_ptr<sf::Sprite> btn = make_texture(path, 355.f, 525.f);
        return Button::_btns[0];
    }

};





#endif // BUTTON_H