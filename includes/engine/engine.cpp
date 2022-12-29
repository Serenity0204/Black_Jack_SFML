#include "engine.h"


// Engine main
// *****************************************************************************************************************
Engine::Engine()
{
    //                                                  Change the name of the project here
    this->_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Black Jack");
    this->_window.setKeyRepeatEnabled(true);

    // ADD MORE IN CTOR
    this->_entered_bet = false;
    this->_init_buttons();
    this->_header = Header("Enter the bet to proceed", {400, 50},{250, 250}, 35, sf::Color::Black, sf::Color::White);
    

    this->_input_box = InputBox(FONT_SIZE, INPUT_BOX_SIZE, INPUT_BOX_POS, sf::Color::Red, sf::Color::White, false);
    this->_card_deck = CardDeck();
    this->_player = Player();

}


// RELEASE MEMORY IN DESTRUCTOR IF USED NEW
Engine::~Engine(){}

// taking input
void Engine::input()
{
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        if(this->_entered_bet) this->_update_buttons(event);

        // User quit
        if(event.type == sf::Event::Closed)
        {
            cout << "User Quit" << endl;
            this->_window.close();
        }

        // User input text
        if(event.type == sf::Event::TextEntered)
        {
            this->_input_box.typedOn(event);   
        }

        // User press key on keyboard
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !this->_entered_bet)
        {
            StrToIntParser parser(this->_input_box.getText());
            int bet = parser.to_int();
            if(bet == -1) break;
            this->_entered_bet = !this->_entered_bet;
            cout << "Bet: " << bet << endl;
        }
        
    }
}

// main draw method, update screen
void Engine::display()
{
    // ADD MORE THINGS TO DRAW

    this->_draw_constant_text();
    
    if(!this->_entered_bet) this->_header.drawTo(this->_window);
    if(this->_entered_bet) this->_draw_button();

    this->_input_box.drawTo(this->_window);

    for(int i = 0; i < this->_current_cards.size(); ++i)
    {
        this->_current_cards[i].set_card_position({float(850 - 180 * i), 325});
        this->_current_cards[i].drawTo(this->_window);
    }


}




// main loop
void Engine::run()
{
    sf::Font arial = this->_config.get_font(ARIAL);
    this->_input_box.setFont(arial);
    this->_input_box.setLimit(true, CHAR_LIMIT);
    this->_header.setFont(arial);

    while (this->_window.isOpen())
    {
        this->_update_input_box();
        this->input();
        this->_window.clear(sf::Color(0, 102, 0));
        this->display();
        this->_window.display();
    }

}
// *****************************************************************************************************************



















// buttons
// *****************************************************************************************************************

// init
void Engine::_init_buttons()
{
    Button hit_btn("HIT", {150, 50}, 25, sf::Color::White, sf::Color::Red);
    hit_btn.setFont(this->_config.get_font(ARIAL));
    hit_btn.setPosition({250, 250});
    this->_buttons.push_back(hit_btn);

    Button stand_btn("STAND", {150, 50}, 25, sf::Color::White, sf::Color::Red);
    stand_btn.setFont(this->_config.get_font(ARIAL));
    stand_btn.setPosition({450, 250});
    this->_buttons.push_back(stand_btn);
}

// update
void Engine::_update_buttons(sf::Event& event)
{
    for(int i = 0; i < this->_buttons.size(); ++i)
    {
        if(this->_buttons[i].isMouseOver(this->_window))
        {
            this->_buttons[i].setBackColor(sf::Color::Yellow);
            continue;
        }
        this->_buttons[i].setBackColor(sf::Color::White);
    }
    for(int i = 0; i < this->_buttons.size(); ++i)
    {
        bool clicked = this->_buttons[i].isMouseOver(this->_window) && event.type == sf::Event::MouseButtonPressed;
        if(clicked && i == HIT)
        {
            if(this->_current_cards.size() == MAX_CARDS) break;
            cout << "hit" << endl;
            Card c = this->_card_deck.draw_card();
            this->_current_cards.push_back(c);
            continue;
        }
        if(clicked && i == STAND)
        {
            cout << "hit" << endl;
            this->_player.calculate_points(this->_current_cards);
            int points = this->_player.get_points();
            cout << "player points: " << points << endl;
            continue;
        }
    }
}

// draw
void Engine::_draw_button()
{
    for(int i = 0; i < this->_buttons.size(); ++i)
    {
        this->_buttons[i].drawTo(this->_window);
    }
}
// *****************************************************************************************************************




// input box
// *****************************************************************************************************************
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
// *****************************************************************************************************************






// draw constant text
void Engine::_draw_constant_text()
{
    sf::Font font = this->_config.get_font(ARIAL);
    sf::Text betInputTitle;
    betInputTitle.setFont(font);
    betInputTitle.setString("Enter your bet");
    betInputTitle.setCharacterSize(20);
    betInputTitle.setPosition({1050, 325});
    betInputTitle.setFillColor(sf::Color::Cyan);
    this->_window.draw(betInputTitle);
    
    vector<sf::Sprite> holds;
    string bet = "1";
    for(int i = 0; i < 4; ++i)
    {
        sf::Sprite bets(this->_config.get_texture(bet));
        bets.setPosition({1100, float(10 + 60 * i)});
        holds.push_back(bets);
        bet += "0";
    }

    sf::Sprite m(this->_config.get_texture("max"));
    m.setPosition({1100, 250});
    holds.push_back(m);
    for(int i = 0; i < holds.size(); ++i)
    {
        this->_window.draw(holds[i]);
    }
}





