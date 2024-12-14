#include "TIcTacTocSize4.h"

TicTacTocSize4Board::TicTacTocSize4Board(){
    this->rows = 4;
    this->columns = 4;
    this->n_moves = 0;
    this->board = new string* [rows];

    for(int i = 0 ; i < this->columns; i++)
        this->board[i] = new string[3];

    for(int i = 0 ; i < this->rows; i++){
        for(int j = 0 ; j < this->columns; j++){
            this->board[i][j] = "-";
        }
    }
    for(int i = 0 ; i < this->columns; i++){
        if(i % 2 == 0)
            this->board[0][i]  = "O";
        else
            this->board[0][i] = "X";
    }
    for(int i = 0 ; i < this->columns; i++){
        if(i % 2 == 0)
            this->board[this->rows-1][i]  = "X";
        else
            this->board[this->rows-1][i] = "O";
    }

}

TicTacTocSize4Board::~TicTacTocSize4Board() = default;

bool TicTacTocSize4Board::update_board(int x, int y, string symbol){
    if(x<0||x>=this->rows||y<0||y>=this->columns)
        return false;
    if(this->board[x][y]!= "-")
        return false;

    this->n_moves++;

}

void TicTacTocSize4Board::display_board(){
    for (int i = 0; i < this->rows; ++i){
        for(int j = 0; j < this->columns; ++j)
            cout << this->board[i][j] << (j != this->columns-1 ? "|" : "");;
        cout << "_____--_" << endl;
        cout << endl;
    }
}

bool TicTacTocSize4Board::is_win() {
    // Check rows for a win (3 consecutive marks in any row)
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] != "-" &&
                this->board[i][j] == this->board[i][j+1] &&
                this->board[i][j+1] == this->board[i][j+2]) {
                return true; // 3 consecutive marks in a row
                }
        }
    }

    // Check columns for a win (3 consecutive marks in any column)
    for (int j = 0; j < this->columns; j++) {
        for (int i = 0; i < this->rows - 2; i++) {
            if (this->board[i][j] != "-" &&
                this->board[i][j] == this->board[i+1][j] &&
                this->board[i+1][j] == this->board[i+2][j]) {
                return true; // 3 consecutive marks in a column
                }
        }
    }

    // Check the main diagonal (top-left to bottom-right) for 3 consecutive marks
    for (int i = 0; i < this->rows - 2; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] != "-" &&
                this->board[i][j] == this->board[i+1][j+1] &&
                this->board[i+1][j+1] == this->board[i+2][j+2]) {
                return true; // 3 consecutive marks in the main diagonal
                }
        }
    }

    // Check the anti-diagonal (top-right to bottom-left) for 3 consecutive marks
    for (int i = 0; i < this->rows - 2; i++) {
        for (int j = 2; j < this->columns; j++) {
            if (this->board[i][j] != "-" &&
                this->board[i][j] == this->board[i+1][j-1] &&
                this->board[i+1][j-1] == this->board[i+2][j-2]) {
                return true; // 3 consecutive marks in the anti-diagonal
                }
        }
    }

    // No win detected
    return false;
}

bool TicTacTocSize4Board::is_draw(){
    return false;
}

bool TicTacTocSize4Board::game_is_over(){
    return is_win();
}

TicTacTocSize4Player::~TicTacTocSize4Player()= default;

void TicTacTocSize4Player::getmove(int& x, int& y){


}



