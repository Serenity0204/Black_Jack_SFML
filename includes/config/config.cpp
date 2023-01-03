#include "config.h"


Config config = Config();


Config::Config()
{
    this->_set_texture();
    this->_set_font();
}

Config::~Config(){}


std::shared_ptr<sf::Texture> Config::_get_texture(string key)
{
    if(this->_texture_map.find(key) != this->_texture_map.end()) 
    {
        return this->_texture_map[key];
    }
    return nullptr;
}

std::shared_ptr<sf::Font> Config::_get_font(int key)
{
    if(this->_font_map.find(key) != this->_font_map.end()) 
    {
        return this->_font_map[key];
    }
    return nullptr;
}



sf::Texture& Config::get_texture(string index)
{
    std::shared_ptr<sf::Texture> texture = this->_get_texture(index);
    assert(texture != nullptr && "Getting non existed texture");
    return *texture;
}


sf::Font& Config::get_font(int index)
{
    std::shared_ptr<sf::Font> font = this->_get_font(index);
    assert(font != nullptr && "Getting non existed font");
    return *font;
}




void Config::_set_texture()
{
    // set texture example

    for(int i = 0; i < 13; ++i)
    {
        string temp = "";

        // get the substring path
        switch (i)
        {
        case 0:
            temp += "ace";
            break;
        case 10:
            temp += "jack";
            break;
        case 11:
            temp += "queen";
            break;
        case 12:
            temp += "king";
            break;
        default:
            temp += to_string(i + 1);
            break;
        }

        string clubs = PATH + temp + CLUBS;
        auto club_ptr = std::make_shared<sf::Texture>();
        club_ptr->loadFromFile(clubs);
        string club_hash = "c" + to_string(i + 1);
        this->_texture_map[club_hash] = club_ptr;
   

        string diamonds = PATH + temp + DIAMONDS;
        auto diamond_ptr = std::make_shared<sf::Texture>();
        diamond_ptr->loadFromFile(diamonds);
        string diamond_hash = "d" + to_string(i + 1);
        this->_texture_map[diamond_hash] = diamond_ptr;


        string hearts = PATH + temp + HEARTS;
        auto heart_ptr = std::make_shared<sf::Texture>();
        heart_ptr->loadFromFile(hearts);
        string heart_hash = "h" + to_string(i + 1);
        this->_texture_map[heart_hash] = heart_ptr;

        string spades = PATH + temp + SPADES;
        auto spade_ptr = std::make_shared<sf::Texture>();
        spade_ptr->loadFromFile(spades);
        string spade_hash = "s" + to_string(i + 1);
        this->_texture_map[spade_hash] = spade_ptr;
        
    
    }
    string bet = "1";
    for(int i = 0; i < 4; ++i)
    {
        string temp = PATH + bet + PNG;
        
        auto ptr = std::make_shared<sf::Texture>();
        ptr->loadFromFile(temp);
        this->_texture_map[bet] = ptr;
        bet += "0";
    }
    auto p = std::make_shared<sf::Texture>();
    p->loadFromFile("../assets/max.png");
    this->_texture_map["max"] = p;

    p = std::make_shared<sf::Texture>();
    p->loadFromFile("../assets/cardBack.png");
    this->_texture_map["back"] = p;
}

void Config::_set_font()
{
    // set font example
    
    auto f1 = std::make_shared<sf::Font>();
    f1->loadFromFile("../assets/arial.ttf");
    this->_font_map[ARIAL] = f1;
}


void Config::draw_constants(sf::RenderWindow &window, bool exclude)
{
    sf::Font font = this->get_font(ARIAL);
    sf::Text betInputTitle;
    betInputTitle.setFont(font);
    betInputTitle.setString("Enter your bet\n(Press Enter)");
    betInputTitle.setCharacterSize(20);
    betInputTitle.setPosition({1060, 325});
    betInputTitle.setFillColor(sf::Color::Red);
    window.draw(betInputTitle);
    
    vector<sf::Sprite> holds;
    string bet = "1";
    for(int i = 0; i < 4; ++i)
    {
        sf::Sprite bets(this->get_texture(bet));
        bets.setPosition({1100, float(10 + 60 * i)});
        holds.push_back(bets);
        bet += "0";
    }

    sf::Sprite m(this->get_texture("max"));
    m.setPosition({1100, 250});
    holds.push_back(m);

    if(exclude)
    {
        sf::Sprite b(this->get_texture("back"));
        b.setPosition({670, 25});
        holds.push_back(b);
    }
    for(int i = 0; i < holds.size(); ++i)
    {
        window.draw(holds[i]);
    }
}



