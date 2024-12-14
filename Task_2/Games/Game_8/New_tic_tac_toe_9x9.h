//
// Created by Fatma on 12/13/2024.
//

#ifndef GAMES_NEW_TIC_TAC_TOE_9X9_H
#define GAMES_NEW_TIC_TAC_TOE_9X9_H


#include "Tic_Tac_Toe_3x3.h"
#include "../../src/BoardGame_Classes.h"


class Tic_Tac_Toe_9x9_board :Board<char>{

private :
    X_O_Board **boards;
public:
    Tic_Tac_Toe_9x9_board();
    ~Tic_Tac_Toe_9x9_board();
    bool game_is_over();
    bool is_draw();
    void display_board();
    bool update_board(int x, int y, char symbol);
    bool is_win();


};

class Tic_Tac_Toe_9x9_player:Player<char> {

public:
    Tic_Tac_Toe_9x9_player(string n, char c);
    void getmove(int& x, int& y);

};

class Tic_Tac_Toe_9x9_random_player :RandomPlayer<char>{
public:
    Tic_Tac_Toe_9x9_random_player(char c);
    void getmove(int& x, int& y);
};



#endif //GAMES_NEW_TIC_TAC_TOE_9X9_H
