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
            cout<<"====";
        }
        cout<<'\n';
    }
}

bool Math_Tic_Tac_Teo_board::update_board(int x, int y, int symbol)
{
    //could I validate in the get move function of the player that if he is the first player should be odd otherwise
    /*||symbol<1||symbol>9*///not imp

    // for the ai part in the backtrack the undo part

    if(symbol==0){
        board[x][y]=0;
        n_moves--;
        Valid_Number[symbol] = true;
        return true;
    }


    /*if(*//*symbol!=0&&*//*(x>=rows||x<0||y>=columns||y<0)&&!Valid_Number[symbol]){
       cout<<"Try again !!\n\n";
       return false;
    }*/

    if(x>=rows||x<0||y>=columns||y<0) {
       cout<<"Out of Bounderies !! \n";
        return false;
    }

    if(board[x][y]!=0) {
        //cout<<"This place is filled with number !! \n\n";
        return false;
    }
    else{
        if(/*symbol!=0&&*/!Valid_Number[symbol]) {
          // cout<<" This number is taken before !!\n\n";
            return false;
        }
        board[x][y]=symbol;
        n_moves++;
        /*if(symbol!=0){*/ Valid_Number[symbol] = false; //}
        return true;
    }

}

bool Math_Tic_Tac_Teo_board::is_draw()
{
    //we can add && !is_win or not too it will be dummy to be added
    // and will not be efficient as win fun is O(n^2)

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
    if(c==1) {
        Numbers = {1, 3, 5, 7, 9};
    }
    else {
        Numbers = {2, 4, 6, 8};
    }

   // setBoard(); in the main we will set the board in the player to validate only  and update_board will not validate
}

void Math_Tic_Tac_Teo_player:: getmove(int& x, int& y)
{
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
    cin>>num;
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
    cout<<"Rows :";cin>>X;
    cout<<"Columns : ";cin>>Y;

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
    this->name="Random Computer Player";
    if(c==1) {
        Numbers = {1, 3, 5, 7, 9};
        //Valid_Number = {true, true, true, true,true};
    }
    else {
        Numbers = {2, 4, 6, 8};
       // Valid_Number={true,true,true,true};
    }

    srand(static_cast<unsigned int>(time(0)));

    this->dimension=3;


}

void Math_Tic_Tac_Teo_random_player::getmove(int &x, int &y) {
    int num;
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
    x=rand()%dimension;
    y=rand()%dimension;
}




//Class  Math_Tic_Tac_Teo_AI_player


Math_Tic_Tac_Teo_AI_player::Math_Tic_Tac_Teo_AI_player(int c): Player<int>(c){

    if(c==1){
        Numbers={1,3,5,7,9};
    }else {
        Numbers = {2,4,6,8};
    }

    this->name="AI_Player";


}

//this means that we should set the board!!
void Math_Tic_Tac_Teo_AI_player::getmove(int &x, int &y)
{

    int c;
    if(Numbers[0]%2==0)
        c=2;
    else
        c=1;

    // ai is the maximizing player
   backtrack(x,y,symbol,c,true,true);


}

// NEED SOME REVISION AND TEST
int Math_Tic_Tac_Teo_AI_player::backtrack(int& x,int & y,int& symbol,int c, bool isMaximizing,bool first)
{

    //base case
    if(boardPtr->is_win()){
        if(!isMaximizing){
            return 1;
        }else{
            return -1;
        }
    }
    if(boardPtr->is_draw())
        return 0;


    //opponent
    static vector<int>player_odd{1,3,5,7,9};
    static vector<int>player_even{2,4,6,8};
    vector<int>& player = (c == 1) ?player_odd :player_even;



    int bestvalue;
    if(isMaximizing)
        bestvalue=INT_MIN;
    else
        bestvalue=INT_MAX;

    int Symbol=-1,X=-1,Y=-1;


    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < player.size(); ++k) {
                if(boardPtr->update_board(i,j,player[k])){
                    int score;
                    if(c==1){
                         score= backtrack(x,y,symbol,2,!isMaximizing,false);
                    } else
                         score= backtrack(x,y,symbol,1,!isMaximizing,false);
                    boardPtr->update_board(i,j,0);
                    if(isMaximizing)
                    {
                       if(score>bestvalue){
                           bestvalue=score;
                           Symbol=player[k];
                           X=i;
                           Y=j;
                       }
                    }else{
                        if(score<bestvalue){
                            bestvalue=score;
                            Symbol=player[k];
                            X=i;
                            Y=j;
                        }
                    }

                }
            }
        }
    }

    if(first){
        symbol=Symbol;
        x=X;
        y=Y;
    }
    return bestvalue;

}
