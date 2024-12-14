//
// Created by Fatma on 12/13/2024.
//

#include "New_tic_tac_toe_9x9.h"

bool Isdigit(string s){
    for(auto c :s){
        if(!isdigit(c))
            return false;
    }
    return true;
}


//CLASS BOARD

Tic_Tac_Toe_9x9_board::Tic_Tac_Toe_9x9_board() {


    this->n_moves=0;
    this->rows=this->columns=3;

    boards = new X_O_Board *[3];
    for (int i = 0; i < rows; ++i) {
        boards[i]=new X_O_Board [3];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            boards[i][j].setter();
        }
    }

    board=new char* [rows];
    for (int i = 0; i < rows; ++i) {
        board[i]=new char [columns];
        for (int j = 0; j < columns; ++j) {
            board[i][j]='.';
        }
    }

}

// CHECK FOR DESTRUCTOR ACTION HERE
Tic_Tac_Toe_9x9_board::~Tic_Tac_Toe_9x9_board() {

    for (int i = 0; i < rows; ++i) {
        delete [] boards[i];
    }
    delete [] boards;
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
    cout<<"##### The representative board ##### \n\n";
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


    cout << "\n\n";
    cout <<"#### The Whole board #### \n\n";
    for (int j = 0; j < 9; ++j) {
        cout << "======";
    }
    cout<<"\n";
    cout<<"  ";
    for (int i = 0; i < 9; ++i) {
        if(i!=0&&i%3==0){
            cout<<"   ";
        }
        cout<<i<<"    ";
    }
    cout<<"\n\n";
    for (int i = 0; i < 3; ++i) {


        boards[i][0].display_row(boards[i][0],boards[i][1],boards[i][2],i*3) ;



        for (int j = 0; j < 9; ++j) {
            cout << "======";
        }
        cout << "\n";

    }
}

// some work will be added
bool Tic_Tac_Toe_9x9_board::update_board(int x, int y, char symbol){

    if(x>=9||x<0||y>=9||y<0)
    {
        cout<<"Out of bounderies \n\n";
        return false;
    }
    if(boards[x/3][y/3].is_win())
    {
        return false;
    }
    if (!boards[x/3][y/3].update_board(x-3*(x/3),y-3*(y/3),symbol))
    {
        cout<<"Try again !!\n\n";
        return false;
    }

    n_moves++;
    if(boards[x/3][y/3].is_win())
    {
        board[x/3][y/3]=symbol;
    }
    // case of draw how in the small board as it is possible or we will leave it ?

    return true;

}


bool Tic_Tac_Toe_9x9_board:: is_win()
{
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


//CLASS PLAYER

Tic_Tac_Toe_9x9_player::Tic_Tac_Toe_9x9_player(string n, char c) : Player<char>(n,c){}

void Tic_Tac_Toe_9x9_player:: getmove(int& x, int& y)
{
    string X,Y;

    again:
    cout<<"Enter the row : ";
    cin>>X;
    if(!Isdigit(X)){
        cout<<"Enter a correct number !!\n\n";
        goto again;
    }

    again_2:

    cout<<"Enter the column : ";
    cin>>Y;

    if(!Isdigit(Y)){
        cout<<"Enter a correct number !!\n\n";
        goto again_2;
    }
    x=stoi(X);
    y=stoi(Y);
}

//CLASS RANDOM PLAYER
Tic_Tac_Toe_9x9_random_player::Tic_Tac_Toe_9x9_random_player(char c): RandomPlayer<char>(c)
{
    this->dimension=9;
    this->name="Random Computer Player";
    srand(static_cast<int>(time(0)));
}

void Tic_Tac_Toe_9x9_random_player:: getmove(int& x, int& y)
{
    x=rand()%this->dimension;
    y=rand()%this->dimension;
}



