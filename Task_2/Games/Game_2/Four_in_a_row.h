//
// Created by Fatma on 11/29/2024.
//

#ifndef GAMES_FOUR_IN_A_ROW_H
#define GAMES_FOUR_IN_A_ROW_H
#include "../../src/BoardGame_Classes.h"
#include <vector>


class Connect_Board:public Board<char>{

    Connect_Board();

    ~Connect_Board();

    void display_board();

    //of course a value will be given to y and symbol but x no
    bool update_board(int x=5, int y=0, char symbol='X');

    bool is_win();

    bool is_draw();

    bool game_is_over();

};


class Connect_Player:public Player<char>{

    Connect_Player(string n, char c);
    void getmove(int& x, int& y);

};


class Connect_Random_Player:public RandomPlayer<char>{

    Connect_Random_Player(char c);

    void getmove(int& x, int& y);

};




#endif //GAMES_FOUR_IN_A_ROW_H
