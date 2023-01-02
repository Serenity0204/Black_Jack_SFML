#include "logic.h"


Logic::Logic(){}

Logic::~Logic(){}


int Logic::check_user_win(int player_points, int dealder_points)
{
    bool win1 = (player_points <= 21) && (dealder_points <= 21) && (player_points > dealder_points);
    bool win2 = (player_points <= 21) && (dealder_points > 21);
    bool tie = (player_points <= 21) && (dealder_points <= 21) && (player_points == dealder_points);

    if(win1 || win2) return WIN;
    if(tie) return TIE;
    return LOSE;
}