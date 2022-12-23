#include "engine.h"


Engine::Engine()
{
    //                                                  Change the name of the project here
    this->_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML");
    this->_window.setKeyRepeatEnabled(true);

    // ADD MORE IN CTOR
    this->_input_box = InputBox(INPUT_BOX_FONT_SIZE, INPUT_BOX_SIZE, INPUT_BOX_POS, sf::Color::Red, sf::Color::White, false);
}

// RELEASE MEMORY IN DESTRUCTOR IF USED NEW
Engine::~Engine(){}


void Engine::_update_input_box()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        //cout << "User selecting input box" << endl;
        this-> _input_box.setSelected(true);
        return;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        //cout << "User quit inputing" << endl;
        this->_input_box.setSelected(false);
        return;
    }
}



void Engine::input()
{
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        // User quit
        if (event.type == sf::Event::Closed)
        {
            cout << "User Quit" << endl;
            this->_window.close();
        }

        // User input text
        if (event.type == sf::Event::TextEntered)
        {
            this->_input_box.typedOn(event);   
        }

        // User press key on keyboard
        // if(sf::Keyboard::isKeyPressed(sf::Keyboard::THE KEY))
        // {

        // }

        
    }
}











void Engine::display()
{
    // ADD MORE THINGS TO DRAW
    // this->_window.draw();
    this->_input_box.drawTo(this->_window);
    
    sf::Sprite s;
    Config c;
    s.setTexture(c.get_texture("s13"));
    this->_window.draw(s);
}

void Engine::run()
{
    sf::Font arial = this->_config.get_font(ARIAL);
    this->_input_box.setFont(arial);
    this->_input_box.setLimit(true, CHAR_LIMIT);

    while (this->_window.isOpen())
    {
        this->_update_input_box();
        this->input();
        this->_window.clear();
        this->display();
        this->_window.display();
    }

}