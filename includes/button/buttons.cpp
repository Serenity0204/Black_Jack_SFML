#include "buttons.h"




Buttons::Buttons()
{
    this->_buttons = vector<Button>();   
    this->_init_buttons();
}

Buttons::~Buttons(){}

void Buttons::_init_buttons()
{
    Config config;
    Button hit_btn("HIT", {150, 50}, 25, sf::Color::White, sf::Color::Red);
    hit_btn.setFont(config.get_font(ARIAL));
    hit_btn.setPosition({250, 250});
    this->_buttons.push_back(hit_btn);

    Button stand_btn("STAND", {150, 50}, 25, sf::Color::White, sf::Color::Red);
    stand_btn.setFont(config.get_font(ARIAL));
    stand_btn.setPosition({450, 250});
    this->_buttons.push_back(stand_btn);
}

// return action code 
int Buttons::update_buttons(sf::RenderWindow &window, sf::Event& event, bool can_update)
{
    if(!can_update) return INVALID;
    
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
        if(clicked && i == HIT)
        {
            //if(this->_current_cards.size() == MAX_CARDS) break;
            cout << "hit 1" << endl;
            return HIT;
            //Card c = this->_card_deck.draw_card();
            //this->_current_cards.push_back(c);
            //continue;

        }
        if(clicked && i == STAND)
        {
            cout << "stand 1" << endl;
            //this->_player.calculate_points(this->_current_cards);
            //int points = this->_player.get_points();
            //cout << "player points: " << points << endl;
            return STAND;
            //continue;
        }
    }
    return INVALID;
}

void Buttons::draw_button(sf::RenderWindow &window)
{
    Config config;
    for(int i = 0; i < this->_buttons.size(); ++i)
    {
        this->_buttons[i].setFont(config.get_font(ARIAL));
        this->_buttons[i].drawTo(window);
    }
}