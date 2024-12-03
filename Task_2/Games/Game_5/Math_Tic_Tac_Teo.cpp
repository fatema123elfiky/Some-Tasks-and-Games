//
// Created by Fatma on 11/29/2024.
//

#include "Math_Tic_Tac_Teo.h"

bool isnum(string & s ){
    for(auto & c: s)
        if(!isdigit(c))
            return false ;
    return true;
}


//Class Math_Tic_Tac_Teo_board

Math_Tic_Tac_Teo_board::Math_Tic_Tac_Teo_board(){

    this->rows=3;
    this->columns=3;
    this->board=new int * [3];
    this->n_moves=0;
    for (int i = 0; i < rows; ++i) {
        board[i]=new int [columns];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            board[i][j]=0;
        }
    }

}

Math_Tic_Tac_Teo_board::~Math_Tic_Tac_Teo_board()
{
    for (int i = 0; i < rows; ++i) {
        delete [] board[i];
    }
    delete [] board;
}

void Math_Tic_Tac_Teo_board::display_board()
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
            cout<<"====";
        }
        cout<<'\n';
    }
}

bool Math_Tic_Tac_Teo_board::update_board(int x, int y, int symbol)
{
    //could I validate in the get move function of the player that if he is the first player should be odd otherwise
    /*||symbol<1||symbol>9*///not imp

    if(x>=rows||x<0||y>=columns||y<0)
        return false;
    if(board[x][y]!=0)
        return false;
    else{
        board[x][y]=symbol;
        n_moves++;
        return true;
    }

}

bool Math_Tic_Tac_Teo_board::is_draw()
{
    //we can add && !is_win or not too it will be dummy to be added
    // and will not be efficient as win fun is O(n^2)

    if(n_moves==3*3)
        return true;
    return false;
}

bool Math_Tic_Tac_Teo_board:: game_is_over()
{
    if(is_draw()||is_win())
        return true;
    return false;


}

bool Math_Tic_Tac_Teo_board:: is_win()
{
    for (int i = 0; i < rows; ++i) {

        if( board[i][0]!=0 && board[i][1]!=0 && board[i][2]!=0 && board[i][0]+board[i][1]+board[i][2]==15 )//rows
            return true;
        else if ( board[0][i]!=0 && board[1][i]!=0 && board[2][i]!=0 && board[0][i]+board[1][i]+board[2][i]==15 )//columns
            return true;

    }

    if(board[0][0]!=0 && board[1][1]!=0 && board[2][2]!=0 && board[0][0]+board[1][1]+board[2][2]==15)//main diagonal
        return true;
    if(board[2][0]!=0 && board[0][2]!=0 && board[1][1]!=0 && board[1][1]+board[0][2]+board[2][0]==15)//off diagonal
        return true;

    return false;
}


//Class Math_Tic_Tac_Teo_player

Math_Tic_Tac_Teo_player::Math_Tic_Tac_Teo_player(string n , int c): Player<int>(n,c){
    if(c==1) {
        Numbers = {1, 3, 5, 7, 9};
        Valid_Number = {true, true, true, true,true};
    }
    else {
        Numbers = {2, 4, 6, 8};
        Valid_Number={true,true,true,true};
    }

}

void Math_Tic_Tac_Teo_player:: getmove(int& x, int& y)
{
   cout<<"Enter the number you want to put from that list :  ";
    for (int i = 0; i < Numbers.size(); ++i) {
         if(Valid_Number[i])
             cout<<Numbers[i]<<" , ";
    }
    cout<<'\n';

    string num;
    cout<<"Enter the number : ";
    cin>>num;

    while (!isnum(num))
    {
        X:

        cout<<"Enter a valid number : ";
        cin>>num;
        if(isnum(num)){
            int nums=stoi(num);
            auto found=find(Numbers.begin(),Numbers.end(),nums);
            if(found!=Numbers.end()&&Valid_Number[found-Numbers.begin()])
                break;
            else
                goto X;
        }

    }

    symbol= stoi(num);

    cout<<"Enter the position of the cell : ";
    cin>>x>>y;



}