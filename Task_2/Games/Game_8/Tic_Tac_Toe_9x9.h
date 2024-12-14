//
// Created by Fatma on 12/12/2024.
//

#ifndef GAMES_TIC_TAC_TOE_9X9_H
#define GAMES_TIC_TAC_TOE_9X9_H

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

};

class Tic_Tac_Toe_9x9_random_player :RandomPlayer<char>{

};



#endif //GAMES_TIC_TAC_TOE_9X9_H
