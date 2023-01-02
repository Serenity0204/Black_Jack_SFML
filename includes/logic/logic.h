#ifndef LOGIC_H
#define LOGIC_H
#include <bits/stdc++.h>
#include "../config/config.h"
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
            if(i == 0 && this->_str[i] == '0') return false;
            if(!(this->_str[i] >= 48 && this->_str[i] <= 57)) return false;
        }
        return true;
    }
public:
    StrToIntParser(string str)
    {
        this->_str = str;
    }
    // if can not be converted to int, return -1, else into int
    int to_int()
    {
        if(this->_str.length() == 0) return -1;
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
    int check_user_win(int player_points, int dealder_points);
};





#endif