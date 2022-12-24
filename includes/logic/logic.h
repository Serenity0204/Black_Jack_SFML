#ifndef LOGIC_H
#define LOGIC_H
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

struct StrToIntParser
{
private:
    string _str;
    // private helper to check if is digit
    bool is_digit()
    {
        for(int i = 0; i < this->_str.length(); ++i)
        {
            // 48 - 57
            if(!(this->_str[i] >= 48 && this->_str[i] <= 57)) return false;
        }
        return true;
    }
public:
    StrToIntParser(string str);
    // if can not be converted to int, return -1, else into int
    int to_int()
    {
        if(!this->is_digit()) return -1;
        return stoi(this->_str);
    }
};




class Logic
{
private:
public:
    Logic();
    ~Logic();
    bool check_user_busted(int points);
    bool check_user_black_jack(int points);
    bool check_tie(int user_points, int dealer_points);
    bool check_user_win(int user_points, int dealder_points);
};





#endif