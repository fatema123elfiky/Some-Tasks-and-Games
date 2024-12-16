//
// Created by Fatma on 11/29/2024.
//

#include "Math_Tic_Tac_Teo.h"

bool Isdigit(string s){
    for(auto c :s){
        if(!isdigit(c))
            return false;
    }
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
    for (int i = 0; i < 10; ++i) {
        Valid_Number.push_back(true);
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
    cout<<"\n";
    for (int i = 0; i < rows; ++i){
        cout<<i<<"  ";
        for (int j = 0; j < columns; ++j) {
            cout<<board[i][j]<<" || ";
        }
        cout<<'\n';
        for (int j = 0; j < columns ; ++j) {
            cout<<"======";
        }
        cout<<'\n';
    }
}

bool Math_Tic_Tac_Teo_board::update_board(int x, int y, int symbol)
{


    if(symbol==0){
        board[x][y]=0;
        n_moves--;
        Valid_Number[symbol] = true;
        return true;
    }


  // Checking for a valid range or location

    if(x>=rows||x<0||y>=columns||y<0) {
       cout<<"Out of Bounderies !! \n";
        return false;
    }

    // Check weather that place is taken or not
    if(board[x][y]!=0) {

        return false;
    }
    else{
        // check weather that number used before or not in the board
        if(!Valid_Number[symbol]) {
            return false;
        }
        board[x][y]=symbol;
        n_moves++;// increment of number of moves
        Valid_Number[symbol] = false;
        return true;
    }

}

bool Math_Tic_Tac_Teo_board::is_draw()
{

    if(n_moves==3*3&& !is_win())
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

    // determination of the type of the player
    if(c==1) {
        Numbers = {1, 3, 5, 7, 9};
    }
    else {
        Numbers = {2, 4, 6, 8};
    }


}

void Math_Tic_Tac_Teo_player:: getmove(int& x, int& y)
{
    // taking a number in my valid range and taking the location of the cell and some validations
 X:
   cout<<"Enter a different ";
    if(symbol%2!=0)
    {
        cout<<" odd number you want to put from 1 to 9 : ";
    }else{
        cout<<" even number you want to put from 2 to 8 : ";
    }


    string num;
    cout<<"Enter the number : ";
    getline(cin,num);
    if(!Isdigit(num)){
        cout<<"Enter a valid number please !!\n\n";
        goto X;
    }

    if(find(Numbers.begin(),Numbers.end(),stoi(num))==Numbers.end()) {
        cout<<"Enter a number in your valid range !!\n\n ";
        goto X;
    }
    symbol=stoi(num);

again:
    cout<<"Enter the position of the cell : ";
    string X,Y;
    cout<<"Rows :";getline(cin,X);
    cout<<"Columns : ";getline(cin,Y);

    while(!Isdigit(X)||!Isdigit(Y)){
        cout<<"Enter correct numbers please!!\n\n ";
        goto again;
    }
    x= stoi(X);
    y= stoi(Y);



}




//Class Math_Tic_Tac_Teo_random_player


Math_Tic_Tac_Teo_random_player::Math_Tic_Tac_Teo_random_player(int c): RandomPlayer<int>(c)
{
    // determination of the type of the player as even or odd and giving him a name

    this->name="Random Computer Player";
    if(c==1) {
        Numbers = {1, 3, 5, 7, 9};

    }
    else {
        Numbers = {2, 4, 6, 8};

    }

    srand(static_cast<unsigned int>(time(0)));

    this->dimension=3;

}

void Math_Tic_Tac_Teo_random_player::getmove(int &x, int &y) {

    int num;

    // here we randomize the taken number
    if(symbol%2!=0){
        num = rand() % 10;
        while (find(Numbers.begin(),Numbers.end(),num)==Numbers.end()){
            num = rand() % 10;
        }
    }else{
        num = rand() % 9;
        while (find(Numbers.begin(),Numbers.end(),num)==Numbers.end()){
            num = rand() % 9;
        }
    }

    symbol=num;

    // here we randomize the location of the cell
    x=rand()%dimension;
    y=rand()%dimension;
}





