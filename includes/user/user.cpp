#include "user.h"

User::User()
{

}

User::~User()
{

}




int User::calculate_points(vector<Card>& cards)
{
    int ace_count = 0;
    int total = 0;
    for(int i = 0; i < cards.size(); ++i)
    {
        int rank = cards[i].get_card_rank();

        if(rank == ACE && i <= 1)
        {
            ace_count++;
            continue;
        }

        if(rank >= ACE && rank <= TEN)
        {
            total += rank;
            continue;
        }
        if(rank == JACK || rank == QUEEN || rank == KING)
        {
            total += TEN;
            continue;
        }
    }
    bool busted = (total + 11) > 21;
    if(ace_count == 1 && !busted) total += 11;
    if(ace_count == 1 && busted) total += 1;
    
    busted = (total + 11 + 1) > 21;
    if(ace_count == 2 && !busted) total += 12;
    if(ace_count == 2 && busted) total += 2;

    cards.clear();
    return total;
}