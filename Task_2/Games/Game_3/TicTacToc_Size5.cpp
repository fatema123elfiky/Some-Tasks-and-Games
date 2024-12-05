#include "TicTacToc_Size5.h"

#include <map>

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
    this->board[x][y] = (symbol != "X" && symbol != "O" ? this->board[x][y] : symbol);
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

    map<string,int> players;

    for(int i = 0 ; i < this->columns ; i++){
        for(int j = 0 ; j < this->rows ; j++){
            if(this->board[i][j] == this->board[i+1][j] && this->board[i+2][j] == this->board[i][j])
                players[this->board[i][j]]++;

            if(this->board[i][j] == this->board[i][j+1] && this->board[i][j+2] == this->board[i][j])
                players[this->board[i][j]]++;

            if(this->board[i][j] == this->board[i+1][j+1] && this->board[i+2][j+2] == this->board[i][j])
                players[this->board[i][j]]++;
        }
    }

    auto firstplayer = players.begin();
    auto lastplayer = players.end();
    --lastplayer;
    if(firstplayer->second != lastplayer->second)
        return true;
    return false;
}

bool TicTacToc_Size5::is_draw(){
    return this->n_moves == 25 && !is_win();
}

bool TicTacToc_Size5::game_is_over(){
    return is_win() || is_draw();
}

TicTacTocPlayer::~TicTacTocPlayer() = default;

void TicTacTocPlayer::getmove(int& x, int& y){
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
                cout << "Please Enter in the range of 1 to 5\n";
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
                cout << "Please Enter in the range of 1 to 5\n";
                continue;
            }
            break;
        }
        cout << "Please Enter a valid number\n";
    }
    x = stoi(tempx) - 1;
    y = stoi(tempy) - 1;
}

TicTacTocRandomPlayer::~TicTacTocRandomPlayer() = default;

void TicTacTocRandomPlayer::getmove(int& x, int& y){
    do{
        x = rand() % this->dimension;
        y = rand() % this->dimension;
    }while (!this->boardPtr->update_board(x, y, "_"));
}




