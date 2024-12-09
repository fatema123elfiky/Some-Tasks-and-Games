#include "TicTacToc_Size5.h"

#include <limits>
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
    if(x<0||x>=this->rows||y<0||y>=this->columns|| (this->board[x][y] != "-" && symbol != "-"))
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
            if(this->boardPtr->update_board(stoi(tempx), stoi(tempy),this->symbol)){
                this->boardPtr->update_board(stoi(tempx), stoi(tempy), "-");
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
            if(this->boardPtr->update_board(stoi(tempx), stoi(tempy),this->symbol)){
                this->boardPtr->update_board(stoi(tempx), stoi(tempy), "-");
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
    }while (!this->boardPtr->update_board(x, y, this->symbol));
    this->boardPtr->update_board(x, y, "-");
}

TicTacTocAIPlayer::TicTacTocAIPlayer(const string& symbol) : Player(symbol){
    this->name = "AI Player";
}

TicTacTocAIPlayer::~TicTacTocAIPlayer() = default;

void TicTacTocAIPlayer::getmove(int& x, int& y){
    pair<int, int> bestMove = BestMove();
    x = bestMove.first;
    y = bestMove.second;
}

int TicTacTocAIPlayer::calculateMinMax(string s, bool isMaximizing){
    if (this->boardPtr->is_win()) {
        return isMaximizing ? -1 : 1;
    } else if (this->boardPtr->is_draw()) {
        return 0;
    }

    int bestValue = isMaximizing ? numeric_limits<int>::min() : numeric_limits<int>::max();
    string opponentSymbol = (s == "X") ? "O" : "X";

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (this->boardPtr->update_board(i, j, s)) {
                int value = calculateMinMax(opponentSymbol, !isMaximizing);
                this->boardPtr->update_board(i, j, "-");

                if (isMaximizing) {
                    bestValue = std::max(bestValue, value);
                } else {
                    bestValue = std::min(bestValue, value);
                }
            }
        }
    }

    return bestValue;
}
}


pair<int, int> TicTacTocAIPlayer::BestMove(){
    int bestValue = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = {-1, -1};
    string opponentSymbol = (this->symbol == "X") ? "O" : "X";


    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (this->boardPtr->update_board(i, j, this->symbol)) {
                int moveValue = calculateMinMax(this->symbol, false);
                this->boardPtr->update_board(i, j, 0);

                if (moveValue > bestValue) {
                    bestMove = {i, j};
                    bestValue = moveValue;
                }
            }
        }
    }

    return bestMove;
}