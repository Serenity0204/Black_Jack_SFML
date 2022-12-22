#include "engine.h"


Engine::Engine()
{
    //                                                  Change the name of the project here
    this->_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML");
    this->_window.setKeyRepeatEnabled(true);

    // ADD MORE IN CTOR
}

// RELEASE MEMORY IN DESTRUCTOR IF USED NEW
Engine::~Engine(){}






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
        // if (event.type == sf::Event::TextEntered)
        // {
            
        // }

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
}

void Engine::run()
{

    while (this->_window.isOpen())
    {
        this->input();
        this->_window.clear();
        this->display();
        this->_window.display();
    }

}