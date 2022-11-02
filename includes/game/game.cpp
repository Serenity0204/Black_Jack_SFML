#include "game.h"

Game::Game()
{
    this->_window.create(sf::VideoMode(1500, 1000), "Black Jack");
}

Game::~Game(){}


void Game::run()
{
    Game_Config game_config;
    game_config.init();
    int i = 0;
    int j = 0;



    sf::Font font;
    font.loadFromFile("../assets/arial.ttf");
    sf::Text text;
    // select the font
    text.setFont(font); // font is a sf::Font
    // set the string to display
    text.setString("Black Jack");
    // set the character size
    text.setCharacterSize(24); // in pixels, not points!
    // set the color
    text.setFillColor(sf::Color::Red);
    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(sf::Vector2f(355.f, 125.f));




    auto ptr = Button::init_btns();

    // string path = "../assets/stand.png";
    // Button stand(path, 355.f, 525.f);
    //auto ptr = Button::test();


    while (this->_window.isOpen())
    {
        sf::Event event;
        while (this->_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
            {
                this->_window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                float x = sf::Mouse::getPosition(this->_window).x;
				float y = sf::Mouse::getPosition(this->_window).y;
                if(!(x>=355 && y>=525 && y<=585 && x<=585)) continue;
                i++;
            }

        }
        if(i == 13)
        {
            i = 0;
            j++;
        }
        if(j == 4) j = 0;
        this->_window.clear();
        this->_window.draw(game_config.get_cards()[j][i]);
        this->_window.draw(*ptr);
        this->_window.draw(text);
        this->_window.display();
    }
}