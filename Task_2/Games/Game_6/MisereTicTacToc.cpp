#include "MisereTicTacToc.h"
#include <iostream>
#include <cstdlib>

MisereTicTacToc::MisereTicTacToc(){
    this->rows = 3;
    this->columns = 3;
    this->board = new string*[3];
    this->n_moves = 0;

    for (int i = 0; i < this->rows; ++i)
        board[i] = new string[3];

    for (int i = 0; i < this->rows; ++i){
        for (int j = 0; j < this->columns; ++j)
            this->board[i][j] = '-';
    }
};

MisereTicTacToc::~MisereTicTacToc()= default;

bool MisereTicTacToc::update_board(int x, int y, string symbol){
    if(x<0||x>=this->rows||y<0||y>=this->columns)
        return false;
    if(this->board[x][y] != "-")
        return false;

    this->n_moves++;
    this->board[x][y] = (symbol != "X" && symbol != "O" ? this->board[x][y] : symbol);
    return true;
}

void MisereTicTacToc::display_board(){
    for (int i = 0; i < this->rows; ++i){
        for(int j = 0; j < this->columns; ++j)
            cout << this->board[i][j] << (j != this->columns-1 ? "|" : "");;
        cout << "______" << endl;
        cout << endl;
    }
}

bool MisereTicTacToc::is_win(){
    for(int i = 0; i < this->rows; ++i){
        if(this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != "-")
            return true;
    }
    for(int j = 0; j < this->columns; ++j){
        if(this->board[0][j] == this->board[1][j] && this->board[1][j] == this->board[2][j] && this->board[0][j]!= "-")
            return true;
    }
    if(this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0]!= "-")
        return true;
    if(this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2]!= "-")
        return true;
    return false;
}

bool MisereTicTacToc::is_draw(){
    if(MisereTicTacToc::is_win()){
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->columns; j++)
                if(this->board[i][j] == "-")
                    return false;
        }
        return true;
    }
    return false;
}

bool MisereTicTacToc::game_is_over(){
    return n_moves == 9;
}

void MisereTicTacTocPlayer::getmove(int& x, int& y){
    string tempx, tempy;

    while (true){
        bool check = false;
        cout << "Enter the number of rows to move: ";
        getline(cin, tempx);
        for (char i : tempx){
            if (!isdigit(i)){
                check = true;
                break;
            }
        }
        if (!check){
            if(this->boardPtr->update_board(stoi(tempx), stoi(tempy),"_")){
                cout << "Please Enter in the range of 1 to 3\n";
                continue;
            }
            break;
        }
        cout << "Please Enter a valid number\n";
    }
    while (true){
        bool check = false;
        cout << "Enter the number of column to move: ";
        getline(cin, tempy);
        for (char i : tempy){
            if (!isdigit(i)){
                check = true;
                break;
            }
        }
        if (!check){
            if(this->boardPtr->update_board(stoi(tempx), stoi(tempy),"_")){
                cout << "Please Enter in the range of 1 to 3\n";
                continue;
            }
            break;
        }
        cout << "Please Enter a valid number\n";
    }
    x = stoi(tempx) - 1;
    y = stoi(tempy) - 1;
}

void MisereTicTacTocRandomPlayer::getmove(int& x, int& y){
    do{
        x = rand() % this->dimension;
        y = rand() % this->dimension;
    }while (!this->boardPtr->update_board(x, y, "_"));
}