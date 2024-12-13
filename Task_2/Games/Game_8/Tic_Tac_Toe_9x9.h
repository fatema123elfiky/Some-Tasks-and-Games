//
// Created by Fatma on 12/12/2024.
//

#ifndef GAMES_TIC_TAC_TOE_9X9_H
#define GAMES_TIC_TAC_TOE_9X9_H

#include "Tic_Tac_Toe_3x3.h"
#include "../../src/BoardGame_Classes.h"


class Tic_Tac_Toe_9x9_board :Board<X_O_Board>{
public:
    Tic_Tac_Toe_9x9_board();
    ~Tic_Tac_Toe_9x9_board();
    bool game_is_over();
    bool is_draw();
    void display_board();
    /*void display_row(X_O_Board board1,X_O_Board board2,X_O_Board board3,int k);
*/

};

class Tic_Tac_Toe_9x9_player:Player<X_O_Board> {

};

class Tic_Tac_Toe_9x9_random_player :RandomPlayer<X_O_Board>{

};



#endif //GAMES_TIC_TAC_TOE_9X9_H
