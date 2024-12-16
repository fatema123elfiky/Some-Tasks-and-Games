//
// Created by Fatma on 11/29/2024.
//

#ifndef GAMES_FOUR_IN_A_ROW_H
#define GAMES_FOUR_IN_A_ROW_H
#include "../../src/BoardGame_Classes.h"
#include <vector>

inline bool IsDigit(string s);
class Connect_Board:public Board<char>{

public:

    Connect_Board();

    ~Connect_Board();

    void display_board();


    bool update_board(int x, int y, char symbol);

    bool is_win();

    bool is_draw();

    bool game_is_over();

};


class Connect_Player:public Player<char>{

public:
    Connect_Player(string n, char c);
    void getmove(int& x, int& y);

};


class Connect_Random_Player:public RandomPlayer<char>{

public:

    Connect_Random_Player(char c);
    void getmove(int& x, int& y);

};



#endif //GAMES_FOUR_IN_A_ROW_H
