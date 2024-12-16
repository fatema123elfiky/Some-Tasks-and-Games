//
// Created by Fatma on 12/12/2024.
//

#ifndef _3X3X_O_H
#define _3X3X_O_H

#include "../../src/BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

class X_O_Board:public Board<char> {


public:
    X_O_Board ();
    bool update_board (int x , int y , char symbol);
    void display_board () ;

    //for 9*9 xo
    void display_row(const X_O_Board &board1,const X_O_Board &board2,const X_O_Board &board3,int k);

    bool is_win() ;
    bool is_draw();
    bool game_is_over();
    ~X_O_Board();

    //for 9*9 xo
    void setter();
    int increment();

};







#endif //GAMES_TIC_TAC_TOE_3X3_H
