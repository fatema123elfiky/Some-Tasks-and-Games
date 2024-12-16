//
// Created by Fatma on 11/29/2024.
//

#ifndef GAMES_MATH_TIC_TAC_TEO_H
#define GAMES_MATH_TIC_TAC_TEO_H
#include "../../src/BoardGame_Classes.h"
#include <algorithm>
#include <utility>

inline bool Isdigit(string s);

class Math_Tic_Tac_Teo_board: public Board<int>
{
private:
    vector<bool>Valid_Number;// vector to know which numbers to use only once
public:

    Math_Tic_Tac_Teo_board();

    ~Math_Tic_Tac_Teo_board();

    void display_board();

    bool update_board(int x, int y, int symbol);

    bool is_draw();

    bool game_is_over();

    bool  is_win();





};

class Math_Tic_Tac_Teo_player:public Player<int>
{

private:

    vector<int>Numbers;// that vector for the ranges of the numbers that the player play with

public:

   Math_Tic_Tac_Teo_player(string n, int c);// 1 -> player / 2 -> player 2

   void getmove(int& x, int& y);

};

class Math_Tic_Tac_Teo_random_player:public RandomPlayer<int>{

private:
    vector<int>Numbers;// that vector for the ranges of the numbers that the player play with

public:
    Math_Tic_Tac_Teo_random_player(int c);
    void getmove(int& x, int& y);

};



#endif //GAMES_MATH_TIC_TAC_TEO_H
