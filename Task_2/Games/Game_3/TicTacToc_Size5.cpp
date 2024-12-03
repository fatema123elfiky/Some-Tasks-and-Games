#include "TicTacToc_Size5.h"

TicTacToc_Size5::TicTacToc_Size5(){
    this->columns = 5;
    this->rows = 5;
    this->n_moves = 0;

    this->board = new string *[rows];
    for(int i = 0 ; i < this->columns; i++)
        this->board[i] = new string[3];

    for(int i = 0 ; i < this->rows; i++){
        for(int j = 0 ; j < this->columns; j++){
            this->board[i][j] = "-";
        }
    }
}

TicTacToc_Size5::~TicTacToc_Size5() = default;

bool TicTacToc_Size5::update_board(int x, int y, string symbol){
    if(x<0||x>=this->rows||y<0||y>=this->columns)
        return false;
    if(this->board[x][y] != "-")
        return false;

    this->n_moves++;
    this->board[x][y] = symbol;
    return true;
}


void TicTacToc_Size5::display_board(){
    for (int i = 0; i < this->rows; ++i){
        for(int j = 0; j < this->columns; ++j)
            cout << this->board[i][j] << (j != this->columns-1 ? "|" : "");
        cout << "__________" << endl;
        cout << endl;
    }
}

bool TicTacToc_Size5::is_win(){
    if(this->n_moves != 25)
        return false;

    for(int i = 0 ; i < this->n_moves ; i++){

    }
}
