
#ifndef PYRAMIC_TIC_H
#define PYRAMIC_TIC_H


#include "../../src/BoardGame_Classes.h"
//Directions of neighbours  to check the winner
          //           R        L       D        U         RD       LD
inline int X[6] = {  0 ,   0 , +1 , -1 ,  +1 ,  +1 };
inline int Y[6] = { +1 ,  -1 ,  0 ,  0 ,  +1 ,  -1 };
template <typename T>
//class of game board
class Pyramic_Board:public Board<T> {
public:
    Pyramic_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
    ~Pyramic_Board();
};
//class of player of pyramic game
template <typename T>
class Pyramic_Player : public Player<T> {
public:
    Pyramic_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};
//class of random player of pyramic game
template <typename T>
class Pyramic_Random_Player : public RandomPlayer<T>{
public:
    Pyramic_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};





//*IMPLEMENTATION* ^_^

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <limits>
using namespace std;

// Constructor for Pyramic_Board
template <typename T>
Pyramic_Board<T>::Pyramic_Board() {
    //board 3*5
    this->rows =3;
    this->columns = 5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            if (((j == 0||j==4)&&i!=2)||(i==0&&(j==3||j==1))) {
                //assign out of the line of pyramid with char 0
                this->board[i][j] = '0';
            }else {
                //assign where we play to null char
                this->board[i][j] = 0;
            }

        }
    }//assign n-moves with 0
    this->n_moves = 0;
}
template <typename T>
//destructor of Pytamic board to delete the Dynamic array
Pyramic_Board<T>::~Pyramic_Board() {
    for (int i = 0; i < this->rows; ++i) {
        delete [] this->board[i];
    }
    delete [] this->board;
}
template <typename T>
bool Pyramic_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0)) {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void Pyramic_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        // Print the spaces to create the pyramid effect
        cout << right << setw(18 - 3 * i);  // Adjusting the spaces to center-align the pyramid

        // For each row, print the '+' and '-' symbols based on the row index
        if (i==1) {
            cout<< setw(13 )<<setfill(' ');
        }else if (i==0) {
            cout<< setw(24)<<setfill(' ');
        }
        else {
            cout<< setw(5)<<setfill(' ');
        }
        for (int k = 0; k < (2 * i + 1); ++k) {

            if (i == 0) {

               cout<<'+' << setw(9) << setfill('-') << '+';  // Top row has '+' and '-'
                setfill(' ');  // Reset fill to space after printing '-'
            } else {
                cout << '+' << setw(9) <<setfill( '-')<<'+';  // Print other rows with '+' and '-'
            }
        }
        setfill(' ');
        cout<<endl;
        if (i==1) {
            cout<< setw(17 - 3 * i )<<setfill(' ');
        }else if (i==0) {
            cout<< setw(25 - 3 * i)<<setfill(' ');
        }
        else {
            cout<< setw(12 - 3 * i)<<setfill(' ');
        }

        // Now print the board content for each row (symbols, numbers, etc.)
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] != '0') { // Skip empty cells
                cout  <<setfill(' ') << "| " << "(" << i << "," << j << ")";
                cout  << setw(1) << this->board[i][j] << " |";
            }
        }
        cout<<endl;
    }
    cout <<setw(4) <<' '<<"+---------+---------+---------+---------+---------+" << endl;
}


// Returns true if there is any winner
template <typename T>
bool Pyramic_Board<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < 6; j++) {
            int colomn=2;
            int m1=X[j],m2=Y[j];
            //check the index and its neighbour and its neighbour from the direction
            if (i+2*m1<this->rows&&i+2*m1>=0&&colomn+2*m2<this->columns&&colomn+2*m2>=0) {
                if (this->board[i+2*m1][colomn+2*m2]==this->board[i][2]&&this->board[i][2]==this->board[i+m1][colomn+m2]&&this->board[i][2]!=0) {
                    return true;
                }

            }
                   //check the neighbour from different sides
            if((j!=5||j!=4)&&i+m1<this->rows&&i+m1>=0&&i-m1<this->rows&&i-m1>=0&&colomn+m2<this->columns&&colomn+m2>=0&&colomn-m2<this->columns&&colomn-m2>=0) {
                if (this->board[i+m1][2+m2]==this->board[i][2]&&this->board[i][2]==this->board[i-m1][colomn-m2]&&this->board[i][2]!=0) {
                    return true;
                }
            }
        }


    }
    return false;
}
// Return true if 9 moves are done and no winner
template <typename T>
bool Pyramic_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}
//return true if there is win or draw
template <typename T>
bool Pyramic_Board<T>::game_is_over() {
    return is_win() || is_draw();
}


// Constructor for Pyramic_Player
template <typename T>
Pyramic_Player<T>::Pyramic_Player(string name, T symbol) : Player<T>(name, symbol) {}
//function to get move
template <typename T>
void Pyramic_Player<T>::getmove(int& x, int& y) {
    cout << "Boundries of move x and y as it is showed in the pyramid \n"
         <<"X:";
    cin >> x ;
    cout<<"\n";
    while (cin.fail()) {
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"please enter your move x right \n"
            <<"X:";
        cin >>x ;
        cout<<"\n";
    }
    cout << "Y:";
    cin >> y ;
    cout<<"\n";
    while (cin.fail()) {
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"please enter your move Y right \n"
            <<"Y:";
        cin >>y ;
        cout<<"\n";
    }
}

// Constructor for X_O_Random_Player
template <typename T>
Pyramic_Random_Player<T>::Pyramic_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Pyramic_Random_Player<T>::getmove(int& x, int& y) {

    x = rand() % 3;  // Random number between 0 and 2
    y = rand() % 5;// Random number between 0 and 5
    //check if it is with in the interval or not
while (((y == 0||y==4)&&x!=2)||(x==0&&(y==3||y==1)))
    {

     x = rand() % 3;
     y = rand() % 5;
    }

}
#endif //PYRAMIC_TIC_H
