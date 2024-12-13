//
// Created by Fatma on 11/29/2024.
//

#include "Four_in_a_row.h"

bool Isdigit(string s){
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
            bool win=false;
            if(j-1>=0&&j-2>=0&&j-3>=0){//back horizontal
                for (int k = 1; k <=3 ; ++k) {
                    if(board[i][j]!=board[i][j-k]) {
                        win= false;
                        break;
                    }else if(board[i][j]==board[i][j-k]&&board[i][j]!='.') {
                        win = true;
                    }
                }
            }else if(j+1<columns && j+2<columns && j+3<columns){//front horizontal
                for (int k = 1; k <=3 ; ++k) {
                    if(board[i][j]!=board[i][j+k])
                    {
                        win= false;
                        break;
                    }else if(board[i][j]==board[i][j+k]&&board[i][j]!='.')
                        win=true;
                }
            }else if(i-1>=0&&i-2>=0&&i-3>=0){//back vertical
                for (int k = 1; k <=3 ; ++k) {
                    if(board[i][j]!=board[i-k][j])
                    {
                        win= false;
                        break;
                    }else if(board[i][j]==board[i-k][j]&&board[i][j]!='.')
                        win=true;
                }
            }else if(i+1<rows&&i+2<rows&&i+3<rows){//front vertical
                for (int k = 1; k <=3 ; ++k) {
                    if(board[i][j]!=board[i+k][j])
                    {
                        win= false;
                        break;
                    }else if(board[i][j]==board[i+k][j]&&board[i][j]!='.')
                        win=true;
                }
            }else if(i-1>=0&&j-1>=0&&i-2>=0&&j-2>=0&&i-3>=0&&j-3>=0){//back off diagonal
                for (int k = 1; k <=3 ; ++k) {
                    if(board[i][j]!=board[i-k][j-k])
                    {
                        win= false;
                        break;
                    }else if(board[i][j]==board[i-k][j-k]&&board[i][j]!='.')
                        win=true;
                }
            }else if(i+1<rows&&j+1<columns&&i+2<rows&&j+2<columns&&i+3<rows&&j+3<columns){//front off diagonal
                for (int k = 0; k <=3 ; ++k) {
                    if(board[i][j]!=board[i+k][j+k])
                    {
                        win= false;
                        break;
                    }else if(board[i][j]!='.'&&board[i][j]==board[i+k][j+k])
                        win=true;
                }
            }else if(i+1<rows&&j-1>=0&&i+2<rows&&j-2>=0&&i+3<rows&&j-3>=0){// back main diagonal
                for (int k = 0; k <=3 ; ++k) {
                    if(board[i][j]!=board[i+k][j-k])
                    {
                        win= false;
                        break;
                    }else if(board[i][j]==board[i+k][j-k]&&board[i][j]!='.')
                        win=true;
                }
            }else if(i-1>=0&&j+1<columns&&i-2>=0&&j+2<columns&&i-3>=0&&j+3<columns){//ba
                for (int k = 0; k <=3 ; ++k) {
                    if(board[i][j]!=board[i-k][j+k])
                    {
                        win= false;
                        break;
                    }else if(board[i][j]==board[i-k][j+k]&&board[i][j]!='.')
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
    cin>>Y;
    while(!Isdigit(Y)){
        cout<<"Please Enter a correct number: ";
        cin>>Y;
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




//AI_PLAYER_CONNECT_FOUR CLASS

AI_Player_Connect_Four::AI_Player_Connect_Four(char c): Player<char>(c) {
    this->name="AI-Player";
}

void AI_Player_Connect_Four::getmove(int &x, int &y) {

    x=5;
    backtrack(y,symbol,true,true);

}

int AI_Player_Connect_Four::backtrack( int &y, char symbol, bool IsMaximizing, bool first) {

    // base_case
    if(boardPtr->is_win()){
        if(!IsMaximizing){
            return 1;
        }else{
            return -1;
        }
    }
    if(boardPtr->is_draw()){
        return 0;
    }


    //opponent
    char opponent;
    if(symbol=='X')
        opponent='O';
    else
        opponent='X';


    int best_value;
    if(IsMaximizing){
        best_value=INT_MIN;
    }else
        best_value=INT_MAX;

    int initial_y;


    for (int i = 0; i < 7; ++i) {

        if(boardPtr->update_board(5,i,symbol)){//do

            int score= backtrack(y,opponent,!IsMaximizing,false);//recurse

            if(IsMaximizing){
                if(score>best_value){
                    best_value=score;
                    initial_y=i;
                }
            }else{
                if(score<best_value){
                    best_value=score;
                    initial_y=i;
                }
            }


            boardPtr->update_board(5,i,'.');//undo
        }

    }

    if(first)
        y=initial_y;
    return best_value;


}