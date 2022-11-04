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
    static vector<std::shared_ptr<sf::Texture>> _btn_textures;
    
    static void make_texture(const string& path, float x_pos, float y_pos)
    {
        auto ptr = std::make_shared<sf::Texture>();
        ptr->loadFromFile(path);
        Button::_btn_textures.push_back(ptr);
        auto _ptr = std::make_shared<sf::Sprite>();
        _ptr->setTexture(*ptr);
        _ptr->setPosition(sf::Vector2f(x_pos, y_pos));
        Button::_btns.push_back(_ptr);
    }

    static bool is_init;
public:
    Button(){}
    ~Button(){}


    static void init_btns()
    {
        if(Button::is_init) return;
        Button::is_init = true;
        const string path = "../assets/stand.png";
        Button::make_texture(path, 355.f, 525.f);
    }
    static std::shared_ptr<sf::Sprite> get_btn()
    {
        return Button::_btns[0];
    }

};





#endif // BUTTON_H