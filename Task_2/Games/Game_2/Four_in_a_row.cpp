//
// Created by Fatma on 11/29/2024.
//

#include "Four_in_a_row.h"

//class Connect_Board

Connect_Board::Connect_Board() {

    this->rows=6;
    this->columns=7;
    board=new char * [rows];
    for (int i = 0; i < rows; ++i) {
        board[i]=new char [columns];
    }
    this->n_moves=0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            board[i][j]='.';
        }
    }

}

Connect_Board::~Connect_Board()
{
    for (int i = 0; i < rows; ++i) {
        delete [] board[i];
    }
    delete [] board;
}

void Connect_Board::display_board()
{
    cout<<"  ";
    for (int i = 0; i < columns; ++i) {
        cout<<i<<"    ";
    }
    for (int i = 0; i < rows; ++i){
        cout<<i<<"  ";
        for (int j = 0; j < columns; ++j) {
            cout<<board[i][j]<<" || ";
        }
        cout<<'\n';
        for (int j = 0; j < columns ; ++j) {
            cout<<"===";
        }
        cout<<'\n';
    }

}

bool Connect_Board::update_board(int x, int y, char symbol)
{
 // the coming one (x) is always (5) then change it
    if(y<0||y>=columns)
        return false;
    while (x>=0&&board[x][y]!='.'){
        x--;
    }

    if(x<0)
        return false;
    else {
        board[x][y] = symbol;
        n_moves++;
    }


    return true;

}

bool Connect_Board:: is_win()
{
    //bool Is_win= false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            bool win=false;
            if(j-1>=0&&j-2>=0&&j-3>=0){//back horizontal
                for (int k = 1; k <=3 ; ++k) {
                    if(board[i][j]!=board[i][j-k]) {
                        win= false;
                        break;
                    }else
                        win=true;
                }
            }else if(j+1<columns && j+2<columns && j+3<columns){//front horizontal
                for (int k = 1; k <=3 ; ++k) {
                    if(board[i][j]!=board[i][j+k])
                    {
                        win= false;
                        break;
                    }else
                        win=true;
                }
            }else if(i-1>=0&&i-2>=0&&i-3>=0){//back vertical
                for (int k = 1; k <=3 ; ++k) {
                    if(board[i][j]!=board[i-k][j])
                    {
                        win= false;
                        break;
                    }else
                        win=true;
                }
            }else if(i+1<rows&&i+2<rows&&i+3<rows){//front vertical
                for (int k = 1; k <=3 ; ++k) {
                    if(board[i][j]!=board[i+k][j])
                    {
                        win= false;
                        break;
                    }else
                        win=true;
                }
            }else if(i-1>=0&&j-1>=0&&i-2>=0&&j-2>=0&&i-3>=0&&j-3>=0){//back off diagonal
                for (int k = 1; k <=3 ; ++k) {
                    if(board[i][j]!=board[i-k][j-k])
                    {
                        win= false;
                        break;
                    }else
                        win=true;
                }
            }else if(i+1<rows&&j+1<columns&&i+2<rows&&j+2<columns&&i+3<rows&&j+3<columns){//front off diagonal
                for (int k = 0; k <=3 ; ++k) {
                    if(board[i][j]!=board[i+k][j+k])
                    {
                        win= false;
                        break;
                    }else
                        win=true;
                }
            }else if(i+1<rows&&j-1>=0&&i+2<rows&&j-2>=0&&i+3<rows&&j-3>=0){// back main diagonal
                for (int k = 0; k <=3 ; ++k) {
                    if(board[i][j]!=board[i+k][j-k])
                    {
                        win= false;
                        break;
                    }else
                        win=true;
                }
            }else if(i-1>=0&&j+1<columns&&i-2>=0&&j+2<columns&&i-3>=0&&j+3<columns){//ba
                for (int k = 0; k <=3 ; ++k) {
                    if(board[i][j]!=board[i-k][j+k])
                    {
                        win= false;
                        break;
                    }else
                        win=true;
                }
            }

            if(win)
                return true;
        }
    }
    return false;
}

bool Connect_Board::is_draw(){

    //we can &&add is_win or not too it will be dummy to be added
    if(n_moves==6*7)
        return true;
    return false;

}

bool Connect_Board:: game_is_over()
{
   if(is_draw()||is_win())
       return true;
    return false;
}

//class Connect_Player

Connect_Player::Connect_Player(string n, char c):Player<char>(n,c){}

void Connect_Player:: getmove(int& x, int& y){

    cout<<"Please Enter the Column number : ";
    cin>>y;

}

//class Connect_Random_Player

Connect_Random_Player::Connect_Random_Player(char c) : RandomPlayer<char>(c)
{
   this->name="Random Computer Player";// but it will change the value as the parent set a value before
   srand(static_cast<unsigned int>(time(0)));

}

void Connect_Random_Player::getmove(int& x, int& y)
{
   x=rand()%6;
   y=rand()%7;
}
