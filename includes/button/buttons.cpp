#include "buttons.h"




Buttons::Buttons()
{
    this->_buttons = vector<Button>();   
    this->_init_buttons();
}

Buttons::~Buttons(){}


// init buttons used in this project
void Buttons::_init_buttons()
{
    Button hit_btn("HIT", {150, 50}, 25, sf::Color::White, sf::Color::Red);
    hit_btn.setFont(config.get_font(ARIAL));
    hit_btn.setPosition({700, 250});
    this->_buttons.push_back(hit_btn);

    Button stand_btn("STAND", {150, 50}, 25, sf::Color::White, sf::Color::Red);
    stand_btn.setFont(config.get_font(ARIAL));
    stand_btn.setPosition({900, 250});
    this->_buttons.push_back(stand_btn);

    Button another_game_btn("Another Game", {200, 50}, 25, sf::Color::White, sf::Color::Red);
    another_game_btn.setFont(config.get_font(ARIAL));
    another_game_btn.setPosition({450, 250});
    this->_buttons.push_back(another_game_btn);
}


// return action code 
int Buttons::update_buttons(sf::RenderWindow &window, sf::Event& event)
{
    for(int i = 0; i < this->_buttons.size(); ++i)
    {
        if(this->_buttons[i].isMouseOver(window))
        {
            this->_buttons[i].setBackColor(sf::Color::Yellow);
            continue;
        }
        this->_buttons[i].setBackColor(sf::Color::White);
    }
    for(int i = 0; i < this->_buttons.size(); ++i)
    {
        bool clicked = this->_buttons[i].isMouseOver(window) && event.type == sf::Event::MouseButtonPressed;
        if(clicked && i == HIT) return HIT;
        if(clicked && i == STAND) return STAND;
        if(clicked && i == ANOTHER_GAME) return ANOTHER_GAME;
    }
    return INVALID;
}

void Buttons::draw_buttons(sf::RenderWindow &window)
{
    for(int i = 0; i < this->_buttons.size(); ++i)
    {
        this->_buttons[i].setFont(config.get_font(ARIAL));
        this->_buttons[i].drawTo(window);
    }
}