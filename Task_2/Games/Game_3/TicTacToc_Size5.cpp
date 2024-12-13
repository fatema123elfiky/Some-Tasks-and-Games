#include "TicTacToc_Size5.h"

#include <limits>
#include <map>

TicTacToc_Size5::TicTacToc_Size5(){
    this->rows = this->columns = 5;
    this->board = new string*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new string[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = "-";
        }
    }
    this->n_moves = 0;
    winningNumber["X"] = 0;
    winningNumber["O"] = 0;
}

TicTacToc_Size5::~TicTacToc_Size5() = default;

bool TicTacToc_Size5::update_board(int x, int y, string symbol){
    if(x<0 || x >= this->rows || y<0 || y >= this->columns || (this->board[x][y] != "-" && symbol != "-") )
        return false;

    if (symbol == "-"){
        this->n_moves--;
        this->board[x][y] = "-";
    }
    else {
        this->n_moves++;
        this->board[x][y] = symbol;
    }

    return true;
}


void TicTacToc_Size5::display_board(){
    for (int i = 0; i < this->rows; ++i){
        for(int j = 0; j < this->columns; ++j)
            cout << this->board[i][j] << (j != this->columns-1 ? "|" : "");
        cout << endl;
        cout << "__________" << endl;
    }
}

bool TicTacToc_Size5::is_win(){
    if(this->n_moves < 25)
        return false;

    map<string,int> players;

    for(int i = 0 ; i < this->columns-2 ; i++){
        for(int j = 0 ; j < this->rows-2 ; j++){
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

    if(n_moves % 2 == 1 && firstplayer->second > lastplayer->second)
        return true;

    if(n_moves % 2 == 0 && firstplayer->second < lastplayer->second)
        return true;
    return false;
}



bool TicTacToc_Size5::is_draw(){
    return this->n_moves > 24 && !is_win();
}

bool TicTacToc_Size5::game_is_over(){
    return is_win() || is_draw();
}

TicTacTocPlayer::~TicTacTocPlayer() = default;

void TicTacTocPlayer::getmove(int& x, int& y){
    string tempx, tempy;

    while (true) {
        cout << "Enter the number of rows to move: ";
        getline(cin, tempx);

        if(tempx.length() == 1 && stoi(tempx) > 0 && stoi(tempx) < 6)
            break;
        cout << "Please Enter a valid number\n";
    }

    while (true) {
        cout << "Enter the number of colmns to move: ";
        getline(cin, tempy);

        if(tempy.length() == 1 && stoi(tempy) > 0 && stoi(tempy) < 6)
            break;
        cout << "Please Enter a valid number\n";
    }

    x = stoi(tempx) - 1;
    y = stoi(tempy) - 1;

}

TicTacTocRandomPlayer::~TicTacTocRandomPlayer() = default;

void TicTacTocRandomPlayer::getmove(int& x, int& y){
    x = rand() % 5;
    y = rand() % 5;
}