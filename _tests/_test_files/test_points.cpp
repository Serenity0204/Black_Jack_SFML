#include "gtest/gtest.h"
#include <bits/stdc++.h>
//------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/player/player.h"
#include "../../includes/card_deck/card.h"


//------------------------------------------------------------------------------

using namespace std;


bool test_player_card1(bool debug=false)
{
  vector<Card> cards;
  cards.push_back(Card("s", 1));
  cards.push_back(Card("s", 10));
  Player player;
  player.calculate_points(cards);
  int p = player.get_points();
  if(debug)
  {
    cout << "Points: " << p << endl; 
  }
  if(p != 21) return false;
  return true;
}


bool test_player_card2(bool debug=false)
{
  vector<Card> cards;
  cards.push_back(Card("s", 1));
  cards.push_back(Card("s", 10));
  cards.push_back(Card("s", 10));

  Player player;
  player.calculate_points(cards);
  int p = player.get_points();
  if(debug)
  {
    cout << "Points: " << p << endl; 
  }
  if(p != 21) return false;
  return true;
}


bool test_player_card3(bool debug=false)
{
  vector<Card> cards;
  cards.push_back(Card("s", 1));
  cards.push_back(Card("s", 1));
  cards.push_back(Card("s", 9));

  Player player;
  player.calculate_points(cards);
  int p = player.get_points();
  if(debug)
  {
    cout << "Points: " << p << endl; 
  }
  if(p != 21) return false;
  return true;
}

bool test_player_card4(bool debug=false)
{
  vector<Card> cards;
  cards.push_back(Card("s", 1));
  cards.push_back(Card("s", 1));
  cards.push_back(Card("s", 10));

  Player player;
  player.calculate_points(cards);
  int p = player.get_points();
  if(debug)
  {
    cout << "Points: " << p << endl; 
  }
  if(p != 12) return false;
  return true;
}


//Lord help me! 
const bool debug = false;

TEST(TEST_PLAYER, TestPlayer1)
{
  bool success = test_player_card1(debug);
  EXPECT_EQ(success, true);
}

TEST(TEST_PLAYER, TestPlayer2)
{
  bool success = test_player_card2(debug);
  EXPECT_EQ(success, true);
}

TEST(TEST_PLAYER, TestPlayer3)
{
  bool success = test_player_card3(debug);
  EXPECT_EQ(success, true);
}


TEST(TEST_PLAYER, TestPlayer4)
{
  bool success = test_player_card4(debug);
  EXPECT_EQ(success, true);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}
