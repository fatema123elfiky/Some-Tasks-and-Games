
// THE NEW ONE TO BE USED
#include "Tic_Tac_Toe_9x9.h"

Tic_Tac_Toe_9x9_board::Tic_Tac_Toe_9x9_board() {

    boards = new X_O_Board *[3];
    for (int i = 0; i < rows; ++i) {
        boards[i]=new X_O_Board [3];
    }

    this->n_moves=0;
    this->rows=this->columns=3;
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
    for (int i = 0; i < 3; ++i) {


        boards[i][0].display_row(boards[i][0],boards[i][1],boards[i][2],i*3) ;


        cout << "\n\n";
        for (int j = 0; j < 9; ++j) {
            cout << "======";
        }
        cout<<'\n';
        for (int j = 0; j < 9; ++j) {
            cout << "======";
        }
        cout << "\n\n";

    }
}

// some work will be added
bool Tic_Tac_Toe_9x9_board::update_board(int x, int y, char symbol){

      if(x>=9||x<0||y>=9||y<0)
      {
          cout<<"Out of bounderies \n\n";
          return false;
      }

    if (!boards[x%3][y%3].update_board(x/3,y/3,symbol))
    {
        cout<<"Try again !!\n\n";
        return false;
    }

    n_moves++;
    if(boards[x%3][y%3].is_win())
    {
        board[x%3][y%3]=symbol;
    }
    // case of draw how in the small board as it is possible or we will leave it ?

    return true;

}







