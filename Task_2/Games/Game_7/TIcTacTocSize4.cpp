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
    if(x < 0 || x >= this->rows || y < 0 || y >= this->columns || (this->board[x][y] != "-" && symbol != "-" && symbol != "!"))
        return false;
    if(this->board[x][y]!= "-")
        return false;

    if(symbol == "!"){
        if(this->board[x][y] == "-")
            return true;

        this->n_moves--;
        this->board[x][y] = "-";
        return true;
    }

    if (symbol == "-"){
        if(n_moves % 2 == 1){
            if(this->board[x][y] == "X"){
                this->board[x][y] = "-";
                return true;
            }
            return false;
        }
        if(this->board[x][y] == "O"){
            this->board[x][y] = "-";
            return true;
        }
        return false;

    }
    this->n_moves++;
    this->board[x][y] = symbol;

    return true;
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
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns ; j++) {
            if (this->board[i][j] != "-" && this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2] && j < this->columns - 2)
                return true;
            if (this->board[i][j] != "-" && this->board[i][j] == this->board[i+1][j] && this->board[i+1][j] == this->board[i+2][j] && i < this->rows - 2)
                return true;
            if (this->board[i][j] != "-" && this->board[i][j] == this->board[i+1][j+1] && this->board[i+1][j+1] == this->board[i+2][j+2] && i < this->rows - 2 && this->columns - 2)
                return true;
            if (this->board[i][j] != "-" && this->board[i][j] == this->board[i+1][j-1] && this->board[i+1][j-1] == this->board[i+2][j-2] && i < this->rows - 2 && j > 1)
                return true;
        }
    }

    return false;
}

bool TicTacTocSize4Board::is_draw(){
    return false;
}

bool TicTacTocSize4Board::game_is_over(){
    return is_win();
}

TicTacTocSize4Player::TicTacTocSize4Player(const string& n, const string& symbol) : Player(n, symbol){}

TicTacTocSize4Player::~TicTacTocSize4Player()= default;

void TicTacTocSize4Player::getmove(int& x, int& y){
    string tempx, tempy;
    int placex , placey;
    do{
        while (true) {
            cout << "Enter the number of rows to remove from: ";
            getline(cin, tempx);

            if(tempx.length() == 1 && stoi(tempx) > 0 && stoi(tempx) < 5)
                break;
            cout << "Please Enter a valid number\n";
        }

        while (true) {
            cout << "Enter the number of colmns to remove from: ";
            getline(cin, tempy);

            if(tempy.length() == 1 && stoi(tempy) > 0 && stoi(tempy) < 5)
                break;
            cout << "Please Enter a valid number\n";
        }

        x = placex = stoi(tempx) - 1;
        y = placey = stoi(tempy) - 1;
    }while(!this->boardPtr->update_board(x,y,"-"));

    do{
        if(placex == x && placey == y)
            this->boardPtr->update_board(x, y, "!");

        while (true) {
            cout << "Enter the number of rows to move: ";
            getline(cin, tempx);

            if(tempx.length() == 1 && stoi(tempx) > 0 && stoi(tempx) < 5)
                break;
            cout << "Please Enter a valid number\n";
        }

        while (true) {
            cout << "Enter the number of colmns to move: ";
            getline(cin, tempy);

            if(tempy.length() == 1 && stoi(tempy) > 0 && stoi(tempy) < 5)
                break;
            cout << "Please Enter a valid number\n";
        }

        x = stoi(tempx) - 1;
        y = stoi(tempy) - 1;
    }while(!this->boardPtr->update_board(x,y,this->symbol) || (placex == x && placey == y));
}

TicTacTocSize4RandomPlayer::TicTacTocSize4RandomPlayer(const string& symbol): RandomPlayer<string>(symbol){}

TicTacTocSize4RandomPlayer::~TicTacTocSize4RandomPlayer() =default;

void TicTacTocSize4RandomPlayer::getmove(int& x, int& y){
    int tempx,tempy;
    do{
        x = rand() % 4;
        y = rand() % 4;
        tempx = x;tempy = y;
    }while(!this->boardPtr->update_board(x,y,"-"));

    do{
        if(tempx == x && tempy == y)
            this->boardPtr->update_board(x, y, "!");
        x = rand() % 4;
        y = rand() % 4;
    }while(!this->boardPtr->update_board(x,y,this->symbol) || (x == tempx && y == tempy));
}

