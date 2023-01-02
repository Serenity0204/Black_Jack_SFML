#include "logic.h"


Logic::Logic(){}

Logic::~Logic(){}


int Logic::check_user_win(int user_points, int dealder_points)
{
    bool win1 = (user_points <= 21) && (dealder_points <= 21) && (user_points > dealder_points);
    bool win2 = (user_points <= 21) && (dealder_points > 21);
    bool tie = (user_points <= 21) && (dealder_points <= 21) && (user_points == dealder_points);

    if(win1 || win2) return WIN;
    if(tie) return TIE;
    return LOSE;
}