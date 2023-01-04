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
        this->_update_buttons_event(event);

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
            this->_update_bet_event();
            break;
        }
        
    }
}

// main draw method, update screen
void Engine::display()
{
    // ADD MORE THINGS TO DRAW

    
    
    this->_header.drawTo(this->_window);
    this->_bet_board.drawTo(this->_window);
    if(this->_entered_bet) this->_buttons.draw_buttons(this->_window);

    this->_input_box.drawTo(this->_window);

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
    config.draw_constants(this->_window, this->_entered_bet);
}




// main loop
void Engine::run()
{
    sf::Font arial = config.get_font(ARIAL);
    this->_input_box.setFont(arial);
    this->_input_box.setLimit(true, CHAR_LIMIT);
    this->_header.setFont(arial);
    this->_bet_board.setFont(arial);

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









void Engine::_init()
{
    this->_entered_bet = false;
    this->_bet = 0;
    this->_player_cards = vector<Card>();
    this->_dealer_cards = vector<Card>();

    this->_buttons = Buttons();
    this->_header = Header(WELCOME_MESSAGE, HEADER_SIZE, HEADER_POS, HEADER_FONT_SIZE, sf::Color(0, 102, 0), sf::Color::Red);
    this->_bet_board = Header("$" + to_string(this->_player.get_bet()), BET_BOARD_SIZE, BET_BOARD_POS, INPUT_BOX_FONT_SIZE, sf::Color(0, 102, 0), sf::Color(255,215,0));

    this->_input_box = InputBox(INPUT_BOX_FONT_SIZE, INPUT_BOX_SIZE, INPUT_BOX_POS, sf::Color::Red, sf::Color::White, false);
    this->_card_deck = CardDeck();
    this->_player = Player();
    this->_dealer = Dealer();
}



void Engine::_update_bet_event()
{
    StrToIntParser parser(this->_input_box.getText());
    int bet = parser.to_int();
    if(bet == -1) return;
    string bet_str = this->_bet_board.getHeader();
    int original_bet = stoi(bet_str.substr(1, bet_str.length()));
    if(bet > original_bet) return;

    this->_player_cards.clear();
    this->_dealer_cards.clear();
    this->_entered_bet = true;
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
    this->_bet = bet;
    this->_player.set_bet(this->_bet,true);
    this->_bet_board.setHeader("$" + to_string(this->_player.get_bet()));
    cout << "Bet: " << bet << endl;
}



void Engine::_update_buttons_event(sf::Event& event)
{
    if(!this->_entered_bet) return;

    int action = this->_buttons.update_buttons(this->_window, event);
    if(action == HIT && this->_player_cards.size() < MAX_CARDS)
    {
        cout << "hit" << endl;
        Card c = this->_card_deck.draw_card();
        this->_player_cards.push_back(c); 
        return;
    }
    if(action == STAND)
    {
        cout << "stand" << endl;
        int player_points = this->_player.calculate_points(this->_player_cards);
        int dealer_points = this->_dealer.calculate_points(this->_dealer_cards);
        while(dealer_points <= 17)
        {
            Card c = this->_card_deck.draw_card();
            this->_dealer_cards.push_back(c); 
            dealer_points = this->_dealer.calculate_points(this->_dealer_cards);
        }
        for(int i = 2; i < this->_dealer_cards.size(); ++i)
        {
            this->_dealer_cards[i].drawTo(this->_window);
        }
        cout << "player points: " << player_points << endl;
        cout << "dealer points: " << dealer_points << endl;
        this->_entered_bet = false;
        Logic logic;
        int win_code = logic.check_user_win(player_points, dealer_points);
        if(win_code == WIN)
        {
            this->_header.setHeader(WIN_MESSAGE);
            this->_player.set_bet(2 * this->_bet, false);
            this->_bet_board.setHeader("$" + to_string(this->_player.get_bet()));
            cout << "now user has: " << this->_player.get_bet() << endl;
            return;
        }
        if(win_code == TIE)
        {
            this->_header.setHeader(TIE_MESSAGE);
            this->_player.set_bet(this->_bet, false);
            this->_bet_board.setHeader("$" + to_string(this->_player.get_bet()));
            cout << "now user has: " << this->_player.get_bet() << endl;
            return;
        }

        if(win_code == LOSE)
        {
            this->_header.setHeader(LOSE_MESSAGE);
            this->_player.set_bet(this->_bet, true);
            this->_bet_board.setHeader("$" + to_string(this->_player.get_bet()));
            cout << "now user has: " << this->_player.get_bet() << endl;
            return;
        }
    }
    if(action == ANOTHER_GAME)
    {
        this->_player_cards.clear();
        this->_dealer_cards.clear();

        this->_entered_bet = false;
        this->_header.setHeader(WELCOME_MESSAGE);
    }
}


