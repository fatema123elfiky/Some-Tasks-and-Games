//
// Created by Fatma on 11/29/2024.
//

#include "Four_in_a_row.h"

 bool IsDigit(string s){
    for(auto c :s){
        if(!isdigit(c))
            return false;
    }
    return true;
}




//class Connect_Board

Connect_Board::Connect_Board() {

    this->n_moves=0;
    this->rows=6;
    this->columns=7;
    board=new char * [rows];
    for (int i = 0; i < rows; ++i) {
        board[i]=new char [columns];
    }

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
    cout<<"\n";
    for (int i = 0; i < rows; ++i){
        cout<<i<<"  ";
        for (int j = 0; j < columns; ++j) {
            cout<<board[i][j]<<" || ";
        }
        cout<<'\n';
        for (int j = 0; j < columns ; ++j) {
            cout<<"=====";
        }
        cout<<'\n';
    }

}

bool Connect_Board::update_board(int x, int y, char symbol)
{
 // the coming one (x) is always (5) then change it
    //x=5;


    //That part for undo part in the ai player backtrack !!
    if(symbol=='.'){
        x=0;
        while(x<=5){
            if(board[x][y]!='.'){
                board[x][y]='.';
                n_moves--;
                return true;
            }
            x++;
        }
    }



    if(y<0||y>=columns) {
        cout<<"Out of Bounderies !! \n\n";
        return false;
    }
    while (x>=0&&board[x][y]!='.'){
        x--;
    }

    if(x<0) {
        //cout<<"Try another column !!\n";
        return false;
    }
    else {
        board[x][y] = symbol;
        n_moves++;
    }


    return true;

}
// Revise
bool Connect_Board:: is_win()
{
    //bool Is_win= false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {

            if(board[i][j]=='.')
                continue;


            if((j-3>=0)){//back horizontal

                if(board[i][j]==board[i][j-1]&&board[i][j]==board[i][j-2]&&board[i][j]==board[i][j-3])
                    return true;



            }
            if(j+3<columns){//front horizontal

                if(board[i][j]==board[i][j+1]&&board[i][j]==board[i][j+2]&&board[i][j]==board[i][j+3])
                    return true;

            }
            if(i-3>=0){//back vertical
                if(board[i][j]==board[i-1][j]&&board[i][j]==board[i-2][j]&&board[i][j]==board[i-3][j])
                    return true;

            }
            if(i+3<rows){//front vertical

                if(board[i][j]==board[i+1][j]&&board[i][j]==board[i+2][j]&&board[i][j]==board[i+3][j])
                    return true;


            }
            if(i-3>=0&&j-3>=0){//back off diagonal

                if(board[i][j]==board[i-1][j-1]&&board[i][j]==board[i-2][j-2]&&board[i][j]==board[i-3][j-3])
                    return true;


            }
            if(i+3<rows&&j+3<columns){//front off diagonal


                if(board[i][j]==board[i+1][j+1]&&board[i][j]==board[i+2][j+2]&&board[i][j]==board[i+3][j+3])
                    return true;


            }
            if(i+3<rows&&j-3>=0){// back main diagonal

                if(board[i][j]==board[i+1][j-1]&&board[i][j]==board[i+2][j-2]&&board[i][j]==board[i+3][j-3])
                    return true;


            }
            if(i-3>=0&&j+3<columns){//ba

                if(board[i][j]==board[i-1][j+1]&&board[i][j]==board[i-2][j+2]&&board[i][j]==board[i-3][j+3])
                    return true;


            }


        }

    }
    return false;
}

bool Connect_Board::is_draw(){

    //we can add && !is_win or not too it will be dummy to be added
    // and will not be efficient as win fun is O(n^2)
    if(n_moves==6*7&& !is_win())
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

Connect_Player::Connect_Player(string n, char c):Player<char>(n,c){
    // for some reason are commented for trial
    /*this->name=n;
    this->symbol=c;*/
}

void Connect_Player:: getmove(int& x, int& y){

    x=5;
    cout<<"Please Enter the Column number : ";
    string Y;
    getline(cin,Y);
    while(!IsDigit(Y)){
        cout<<"Please Enter a correct number: ";
        getline(cin,Y);
    }
    y=stoi(Y);

}





//class Connect_Random_Player

Connect_Random_Player::Connect_Random_Player(char c) : RandomPlayer<char>(c)
{
   this->name="Random Computer Player";// but it will change the value as the parent set a value before
   srand(static_cast<unsigned int>(time(0)));
   this->dimension=7;

}

void Connect_Random_Player::getmove(int& x, int& y)
{
   x=5;
   y=rand()%dimension;
}




