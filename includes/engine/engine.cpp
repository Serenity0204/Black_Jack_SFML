#include "engine.h"


// Engine main
// *****************************************************************************************************************
Engine::Engine()
{
    //                                                  Change the name of the project here
    this->_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Black Jack");
    this->_window.setKeyRepeatEnabled(true);

    // ADD MORE IN CTOR
    this->_init();
}

// RELEASE MEMORY IN DESTRUCTOR IF USED NEW
Engine::~Engine(){}

// taking input
void Engine::input()
{
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        // calling update event helper functions
        this->_update_buttons_event(event);
        this->_update_end_game_event(event);
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
        // User press up and already entered bet
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !this->_entered_bet)
        {
            this->_update_bet_event();
            break;
        }
    }
}


// main draw method, update screen
void Engine::display()
{
    // ADD MORE THINGS TO DRAW
    if(this->_end)
    {
        this->_draw_end_game();
        return;
    }
    
    // draw header and betboard
    this->_header.drawTo(this->_window);
    this->_bet_board.drawTo(this->_window);

    // display the input box for user to enter bet
    this->_input_box.drawTo(this->_window);


    // if user entered bet, then draw the buttons for hit, stand, another game
    if(this->_entered_bet) this->_buttons.draw_buttons(this->_window);

    // setting cards position
    this->_set_card_pos_helper();

    // draw the constants to the screen
    config.draw_constants(this->_window, this->_entered_bet);
}


// run method for game
void Engine::run()
{
    // set the position and font before running
    sf::Font arial = config.get_font(ARIAL);
    this->_input_box.setFont(arial);
    this->_input_box.setLimit(true, CHAR_LIMIT);
    this->_header.setFont(arial);
    this->_bet_board.setFont(arial);
    this->_restart.setFont(arial);  
    this->_restart.setPosition({300, 500});

    // main loop
    while (this->_window.isOpen())
    {
        // update input box
        this->_input_box.update_input_box();
        // taking input
        this->input();
        // clear the screen
        this->_window.clear(sf::Color(0, 102, 0));
        // draw the updated events
        this->display();
        // sfml method to display to the screen
        this->_window.display();
    }

}
// *****************************************************************************************************************






// Init
// *****************************************************************************************************************
// init the attributes
void Engine::_init()
{
    this->_entered_bet = false;
    this->_end = false;
    this->_bet = 0;
    this->_player_cards = vector<Card>();
    this->_dealer_cards = vector<Card>();

    this->_buttons = Buttons();
    this->_restart = Button("Play Again", {200, 50}, 25, sf::Color::White, sf::Color::Red);
    this->_header = Header(WELCOME_MESSAGE, HEADER_SIZE, HEADER_POS, HEADER_FONT_SIZE, sf::Color(0, 102, 0), sf::Color::Red);
    this->_bet_board = Header("$" + to_string(this->_player.get_bet()), BET_BOARD_SIZE, BET_BOARD_POS, INPUT_BOX_FONT_SIZE, sf::Color(0, 102, 0), sf::Color(255,215,0));

    this->_input_box = InputBox(INPUT_BOX_FONT_SIZE, INPUT_BOX_SIZE, INPUT_BOX_POS, sf::Color::Red, sf::Color::White, false);
    this->_card_deck = CardDeck();
    this->_player = Player();
    this->_dealer = Dealer();
}
// *****************************************************************************************************************








// Update
// *****************************************************************************************************************
// update bet
void Engine::_update_bet_event()
{
    // parse the input into int
    StrToIntParser parser(this->_input_box.getText());
    int bet = parser.to_int();
    // if parsing fails, then do nothing
    if(bet == -1) return;

    // if it's a number greater than the player has, then it fails too
    string bet_str = this->_bet_board.getHeader();
    int original_bet = stoi(bet_str.substr(1, bet_str.length()));
    if(bet > original_bet) return;


    // clear the cards for both dealer and players from last round
    this->_player_cards.clear();
    this->_dealer_cards.clear();

    // set the user entered bet or not to be true
    this->_entered_bet = true;

    // draws two cards for both player and dealer
    for(int i = 0; i < 2; ++i)
    {
        Card c = this->_card_deck.draw_card();
        this->_player_cards.push_back(c);
    }
    for(int i = 0; i < 2; ++i)
    {
        Card c = this->_card_deck.draw_card();
        this->_dealer_cards.push_back(c);
    }

    // set the bet and deduct it from the player's bet
    this->_bet = bet;
    this->_player.set_bet(this->_bet, true);
    this->_bet_board.setHeader("$" + to_string(this->_player.get_bet()));
    cout << "Bet: " << bet << endl;
}

// update buttons event
void Engine::_update_buttons_event(sf::Event& event)
{
    // if not entered bet, then cannot be clicked
    if(!this->_entered_bet) return;

    // to get which button the player clicks
    int action = this->_buttons.update_buttons(this->_window, event);

    // hit, draw one card
    if(action == HIT && this->_player_cards.size() < MAX_CARDS)
    {
        cout << "hit" << endl;
        Card c = this->_card_deck.draw_card();
        this->_player_cards.push_back(c); 
        return;
    }

    // stand, calculate points for both and compare
    if(action == STAND)
    {
        cout << "stand" << endl;
        int player_points = this->_player.calculate_points(this->_player_cards);
        int dealer_points = this->_dealer.calculate_points(this->_dealer_cards);
        
        // draw cards til hits 17 
        dealer_points = this->_dealer.draw_card_AI(this->_dealer_cards, this->_card_deck);

        // draw the cards the dealer hits
        for(int i = 2; i < this->_dealer_cards.size(); ++i) this->_dealer_cards[i].drawTo(this->_window);
    
        cout << "player points: " << player_points << endl;
        cout << "dealer points: " << dealer_points << endl;

        this->_entered_bet = false;
        this->_win_logic_helper(player_points, dealer_points);
    }

    // reset a new game
    if(action == ANOTHER_GAME)
    {
        this->_player_cards.clear();
        this->_dealer_cards.clear();
        this->_player.set_bet(this->_bet, false);
        this->_bet_board.setHeader("$" + to_string(this->_player.get_bet()));
        this->_entered_bet = false;
        this->_header.setHeader(WELCOME_MESSAGE);
    }
}

// reset the game state when player's bet hits 10000 or 0
void Engine::_update_end_game_event(sf::Event& event)
{
    if(this->_restart.isMouseOver(this->_window) && this->_end) this->_restart.setBackColor(sf::Color::Yellow);
    if(!this->_restart.isMouseOver(this->_window) && this->_end) this->_restart.setBackColor(sf::Color::White);
    
    if(this->_restart.isMouseOver(this->_window) && this->_end && event.type == sf::Event::MouseButtonPressed)
    {
        cout << "Restart" << endl;
        this->_end = false;
        this->_player.reset();
        this->_player.set_bet(2500, false);
        this->_bet_board.setHeader("$" + to_string(this->_player.get_bet()));
        this->_header.setHeader(WELCOME_MESSAGE);
        this->_player_cards.clear();
        this->_dealer_cards.clear();
        return;
    }
}

// *****************************************************************************************************************




// Draw
// *****************************************************************************************************************
// draw end game events to the screen
void Engine::_draw_end_game()
{
    if(this->_player.get_bet() == 0)
    {
        sf::Sprite end(config.get_texture("lose"));
        end.setPosition({175,75});
        this->_window.draw(end);
        this->_restart.drawTo(this->_window);
        return;
    }
    if(this->_player.get_bet() >= 10000)
    {
        sf::Sprite end(config.get_texture("win"));
        end.setPosition({175,75});
        this->_window.draw(end);
        this->_restart.drawTo(this->_window);
        return;
    }
}
// *****************************************************************************************************************









// Other helpers
// *****************************************************************************************************************
void Engine::_win_logic_helper(int player_points, int dealer_points)
{
    Logic logic;
    // check who wins
    int win_code = logic.check_user_win(player_points, dealer_points);
    // if win, double the bet and give it to the player
    if(win_code == WIN)
    {
        this->_header.setHeader(WIN_MESSAGE);
        this->_player.set_bet(2 * this->_bet, false);
        this->_bet_board.setHeader("$" + to_string(this->_player.get_bet()));
        cout << "now user has: " << this->_player.get_bet() << endl;
        if(this->_player.get_bet() >= 10000) this->_end = true;
        return;
    }
    // if tie, then return the bet to the player
    if(win_code == TIE)
    {
        this->_header.setHeader(TIE_MESSAGE);
        this->_player.set_bet(this->_bet, false);
        this->_bet_board.setHeader("$" + to_string(this->_player.get_bet()));
        cout << "now user has: " << this->_player.get_bet() << endl;
        return;
    }
    // if lose, do nothing b/c the user already entered the bet
    if(win_code == LOSE)
    {
        this->_header.setHeader(LOSE_MESSAGE);
        this->_bet_board.setHeader("$" + to_string(this->_player.get_bet()));
        cout << "now user has: " << this->_player.get_bet() << endl;
        if(this->_player.get_bet() == 0) this->_end = true;
        return;
    }
}



// setting the card position helper
void Engine::_set_card_pos_helper()
{
    for(int i = 0; i < this->_player_cards.size(); ++i)
    {
        this->_player_cards[i].set_card_position({float(850 - 180 * i), 375});
        this->_player_cards[i].drawTo(this->_window);
    }
    for(int i = 0; i < this->_dealer_cards.size(); ++i)
    {
        this->_dealer_cards[i].set_card_position({float(850 - 180 * i), 25});
        this->_dealer_cards[i].drawTo(this->_window);
    }
}
// *****************************************************************************************************************