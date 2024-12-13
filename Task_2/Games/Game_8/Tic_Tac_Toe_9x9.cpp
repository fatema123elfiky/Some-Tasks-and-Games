//
// Created by Fatma on 12/12/2024.
//

#include "Tic_Tac_Toe_9x9.h"

Tic_Tac_Toe_9x9_board::Tic_Tac_Toe_9x9_board() {

    this->n_moves=0;
    this->rows=this->columns=3;
    board=new X_O_Board* [rows];
    for (int i = 0; i < rows; ++i) {
        board[i]=new X_O_Board [columns];
    }

}
Tic_Tac_Toe_9x9_board::~Tic_Tac_Toe_9x9_board() {

    for (int i = 0; i < rows; ++i) {
        delete [] board[i];
    }
    delete [] board;
}

bool Tic_Tac_Toe_9x9_board::game_is_over() {

     return is_win() || is_draw();
}

bool Tic_Tac_Toe_9x9_board::is_draw() {
    if(n_moves==9*9&& !is_win())
        return true;
    return false;
}

void Tic_Tac_Toe_9x9_board::display_board()
{
    for (int i = 0; i < 3; ++i) {

       // board[i][0]->display_row(board[i][0],board[i][1],board[i][2],i);
       board[i][0].display_row(board[i][0],board[i][1],board[i][2],i) ;
       cout << "\n\n";
        for (int j = 0; j < 9; ++j) {
            cout << "======";
        }
        cout<<'\n';
        for (int j = 0; j < 9; ++j) {
            cout << "======";
        }
        cout << "\n\n";
    }
}





