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
    this->_buttons = Buttons();
    this->_header = Header(WELCOME_MESSAGE, HEADER_SIZE, HEADER_POS, HEADER_FONT_SIZE, sf::Color(0, 102, 0), sf::Color::Red);
    this->_input_box = InputBox(INPUT_BOX_FONT_SIZE, INPUT_BOX_SIZE, INPUT_BOX_POS, sf::Color::Red, sf::Color::White, false);
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
        int action = this->_buttons.update_buttons(this->_window, event);
        if(action == HIT && this->_player_cards.size() < MAX_CARDS)
        {
            cout << "hit" << endl;
            Card c = this->_card_deck.draw_card();
            this->_player_cards.push_back(c); 
            break;
        }
        if(action == STAND)
        {
            cout << "stand" << endl;
            this->_player.calculate_points(this->_player_cards);
            int points = this->_player.get_points();
            cout << "player points: " << points << endl;
            this->_entered_bet = false;
            if(points > 21)
            {
                this->_header.setHeader(LOSE_MESSAGE);
                break;
            }
            else
            {
                this->_header.setHeader(WIN_MESSAGE);
                break;
            }
        }
        if(action == ANOTHER_GAME)
        {
            this->_player_cards.clear();
            this->_entered_bet = false;
            this->_header.setHeader(WELCOME_MESSAGE);
        }


        // User quit
        if(event.type == sf::Event::Closed)
        {
            cout << "User Quit" << endl;
            this->_window.close();
            break;
        }

        // User input text
        if(event.type == sf::Event::TextEntered)
        {
            this->_input_box.typedOn(event);   
            break;
        }

        // User press key on keyboard
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !this->_entered_bet)
        {
            StrToIntParser parser(this->_input_box.getText());
            int bet = parser.to_int();
            if(bet == -1) break;
            this->_entered_bet = true;
            for(int i = 0; i < 2; ++i)
            {
                Card c = this->_card_deck.draw_card();
                this->_player_cards.push_back(c);
            }
            cout << "Bet: " << bet << endl;
            break;
        }
        
    }
}

// main draw method, update screen
void Engine::display()
{
    // ADD MORE THINGS TO DRAW

    config.draw_constants(this->_window);
    
    // if(!this->_entered_bet) 
    this->_header.drawTo(this->_window);
    if(this->_entered_bet) this->_buttons.draw_buttons(this->_window);

    this->_input_box.drawTo(this->_window);

    for(int i = 0; i < this->_player_cards.size(); ++i)
    {
        this->_player_cards[i].set_card_position({float(850 - 180 * i), 325});
        this->_player_cards[i].drawTo(this->_window);
    }


}




// main loop
void Engine::run()
{
    sf::Font arial = config.get_font(ARIAL);
    this->_input_box.setFont(arial);
    this->_input_box.setLimit(true, CHAR_LIMIT);
    this->_header.setFont(arial);

    while (this->_window.isOpen())
    {
        this->_input_box.update_input_box();
        this->input();
        this->_window.clear(sf::Color(0, 102, 0));
        this->display();
        this->_window.display();
    }

}
// *****************************************************************************************************************

















