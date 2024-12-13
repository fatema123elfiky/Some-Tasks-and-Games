//
// Created by Fatma on 12/12/2024.
//

#include "Tic_Tac_Toe_3x3.h"


bool Isdigit(string s){
    for(auto c :s){
        if(!isdigit(c))
            return false;
    }
    return true;
}

// Constructor for X_O_Board

X_O_Board::X_O_Board() {
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = '.';//changed --> '.'
        }
    }
    this->n_moves = 0;
}

X_O_Board::~X_O_Board() {

    for (int i = 0; i < this->rows; ++i) {
        delete [] board[i];
    }
    delete [] board;
}


bool X_O_Board::update_board(int x, int y, char mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            //undo part
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

// Display the board and the pieces on it

void X_O_Board::display_board() {

    cout<<"  ";
    for (int i = 0; i < columns; ++i) {
        cout<<i<<"    ";
    }
    cout<<"\n\n";
    for (int i = 0; i < rows; ++i){
        cout<<i<<"  ";
        for (int j = 0; j < columns; ++j) {
            cout<<board[i][j]<<" || ";
        }
        cout<<'\n';
        for (int j = 0; j < columns ; ++j) {
            cout<<"====";
        }
        cout<<'\n';
    }
}
// for the 9x9 xo displaying
void X_O_Board::display_row(const X_O_Board &board1,const X_O_Board &board2,const X_O_Board &board3,int k)
{

    cout<<"  ";
    for (int i = 0; i < 9; ++i) {
        cout<<i<<"    ";
        if(i!=0&&i%3==0){
            cout<<"  ";
        }
    }
    cout<<"\n\n";
    for (int i = 0; i < 3 ; ++i) {
        cout << i+k << "  ";


        for (int j = 0; j < 2; ++j) {
            cout << board1.board[i][j] << " || ";
        }
        cout << board1.board[i][2] << " ||   ";
        for (int j = 0; j < 2; ++j) {
            cout << board2.board[i][j] << " || ";
        }
        cout << board2.board[i][2] << " ||   ";
        for (int j = 0; j < 2; ++j) {
            cout << board3.board[i][j] << " || ";
        }
        cout << board3.board[i][2] << " ||   ";


            cout << '\n';
            for (int j = 0; j < 9; ++j) {
                cout << "======";
            }
            cout << '\n';

    }

}
// Returns true if there is any winner

bool X_O_Board::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != '.') ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != '.')) {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != '.') ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != '.')) {
        return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner

bool X_O_Board::is_draw() {
    return (this->n_moves == 9 && !is_win());
}


bool X_O_Board::game_is_over() {
    return is_win() || is_draw();
}



// Constructor for X_O_Player

X_O_Player::X_O_Player(string name, char symbol) : Player<char>(name, symbol) {}


void X_O_Player::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    string X,Y;
    cout<<"Rows : ";
    cin >> X ;
    cout<<"Columns : ";
    cin>> Y;
    while (!Isdigit(X)||!Isdigit(Y)){
        cout<<"Enter proper numbers !!\n\n";
        cout<<"Rows : ";
        cin >> X ;
        cout<<"Columns : ";
        cin>> Y;
    }
    x= stoi(X);
    y= stoi(Y);
}

// Constructor for X_O_Random_Player

X_O_Random_Player::X_O_Random_Player(char symbol) : RandomPlayer<char>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}


void X_O_Random_Player::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
}