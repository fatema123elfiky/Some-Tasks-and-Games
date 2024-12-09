#include "MisereTicTacToc.h"

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <limits>

MisereTicTacToc::MisereTicTacToc(){
    this->rows = this->columns = 3;
    this->board = new string*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new string[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = "-";
        }
    }
    this->n_moves = 0;
};

MisereTicTacToc::~MisereTicTacToc()= default;

bool MisereTicTacToc::update_board(int x, int y, string symbol){
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

void MisereTicTacToc::display_board(){
    for (int i = 0; i < this->rows; ++i){
        for(int j = 0; j < this->columns; ++j)
            cout << this->board[i][j] << (j != this->columns-1 ? "|" : "");
        cout << endl;
        cout << "______" << endl;
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
    return n_moves == 9 && !is_win();
}

bool MisereTicTacToc::game_is_over(){
    return n_moves == 9 || is_win() || is_draw();
}

void MisereTicTacTocPlayer::getmove(int& x, int& y){
    string tempx, tempy;

    while (true) {
        cout << "Enter the number of rows to move: ";
        getline(cin, tempx);

        if(tempx.length() == 1 && stoi(tempx) > 0 && stoi(tempx) < 4)
            break;
        cout << "Please Enter a valid number\n";
    }

    while (true) {
        cout << "Enter the number of colmns to move: ";
        getline(cin, tempy);

        if(tempy.length() == 1 && stoi(tempy) > 0 && stoi(tempy) < 4)
            break;
        cout << "Please Enter a valid number\n";
    }

    x = stoi(tempx) - 1;
    y = stoi(tempy) - 1;
}

void MisereTicTacTocRandomPlayer::getmove(int& x, int& y){
    x = rand() % 3;
    y = rand() % 3;

}

MisereTicTacTacAIPlayer::MisereTicTacTacAIPlayer(const string& symbol) : Player(symbol){
    this->name = "AI Player";
}

MisereTicTacTacAIPlayer::~MisereTicTacTacAIPlayer() = default;


void MisereTicTacTacAIPlayer::getmove(int& x, int& y){
    pair<int, int> Place = getBestMove();
    x = Place.first;
    y = Place.second;
}

int MisereTicTacTacAIPlayer::calculateMinMax(string s, bool isMaximizing){
    if (this->boardPtr->is_win())
        return isMaximizing ? -1 : 1;

    if (this->boardPtr->is_draw())
        return 0;


    int bestValue = isMaximizing ? INT_MIN : INT_MAX;
    string opponentSymbol = (s == "X") ? "O" : "X";

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (this->boardPtr->update_board(i, j, s)) {
                int value = calculateMinMax(opponentSymbol, !isMaximizing);
                this->boardPtr->update_board(i, j, "-");

                if (isMaximizing)
                    bestValue = max(bestValue, value);

                else
                    bestValue = min(bestValue, value);

            }
        }
    }

    return bestValue;
}

pair<int, int> MisereTicTacTacAIPlayer::getBestMove(){
    int bestValue = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = {-1, -1};
    string opponentSymbol = (this->symbol == "X") ? "O" : "X";

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (this->boardPtr->update_board(i, j, this->symbol)) {
                int moveValue = calculateMinMax(this->symbol, false);
                this->boardPtr->update_board(i, j, "-");

                if (moveValue > bestValue) {
                    bestMove = {i, j};
                    bestValue = moveValue;
                }
            }
        }
    }

    return bestMove;

}
