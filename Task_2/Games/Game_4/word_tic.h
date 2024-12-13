
#ifndef UNTITLED_WORD_TIC_H
#define UNTITLED_WORD_TIC_H

#include "../../src/BoardGame_Classes.h"
#include <fstream>
#include<unordered_set>
#include <limits>
vector<string>check;

void setvector(){

    fstream file("dic.txt");
    if (!file.is_open()){
        cout<<"file can not be opened !!";
    }
    string line;
    while(getline(file,line)){
check.push_back(line);
    }

}
template <typename T>
class Word_Board:public Board<T> {
public:
    Word_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    pair<int,int> IsAbout2Win();
    pair<int,int> Isdanger();

    bool is_draw();
    bool game_is_over();

};

template <typename T>
class Word_Player: public Player<T>{
public:
    Word_Player (string name);
    void getmove(int& x, int& y) ;

};

template <typename T>
class Word_Random_Player : public RandomPlayer<T>{
public:
    Word_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};




//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()

using namespace std;

// Constructor for X_O_Board
template <typename T>
Word_Board<T>::Word_Board() {
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = ' ';
        }
    }
    this->n_moves = 0;
    if(check.empty()) {
        setvector();
    }

}

template <typename T>
bool Word_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == ' '|| mark == ' ')) {
        if (mark == ' '){
            this->n_moves--;
            this->board[x][y] = ' ';
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
template <typename T>
void Word_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool Word_Board<T>::is_win() {
    // Check rows and columns
unordered_set<string> words;
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] != ' ' && this->board[i][1] != ' '&& this->board[i][0] != ' ') ){
            string l=string(1,this->board[i][0]) + string(1,this->board[i][1]) +string(1,this->board[i][2]);
            
            words.insert(l);

        }

        if (this->board[0][i] != ' ' && this->board[1][i] != ' ' && this->board[0][i] != ' ') {
            string l=string(1,this->board[0][i]) + string(1,this->board[1][i]) +string(1,this->board[2][i]);
            words.insert(l);

        }
    }
    if (this->board[0][0] != ' ' && this->board[1][1] != ' ' && this->board[0][0] != ' '){
       string l= string(1,this->board[0][0]) + string(1,this->board[1][1]) +string(1,this->board[2][2]);
       words.insert(l);
    }

    // Check diagonals
    if (this->board[0][2] != ' ' && this->board[1][1] != ' ' && this->board[0][2] != ' ') {
        string l= string(1,this->board[0][2]) + string(1,this->board[1][1]) +string(1,this->board[2][0]);
        words.insert(l);
    }
    
    for (auto it=words.begin();it!=words.end();++it ) {
        for (int i = 0; i <check.size() ; ++i) {
           string inverse=(*it);
            char temp=inverse[2];
            inverse[2]=inverse[0];
            inverse[0]=temp;
            if ((*it)==check[i]||inverse==check[i]){
                return true;
            }
        }    
        
    }

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool Word_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Word_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for X_O_Player
template <typename T>
Word_Player<T>::Word_Player(string name) : Player<T>(name, ' ') {}

template <typename T>
void Word_Player<T>::getmove(int& x, int& y) {
    cout << "\nBoundries of move x and y (0 to 2) \n"
         <<"X:";
    cin >> x ;
    cout<<"\n";
    while (cin.fail()) {
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
cout<<"please enter your move x as integer \n"
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
        cout<<"please enter your move Y as integer \n"
            <<"Y:";
        cin >>y ;
        cout<<"\n";
    }
    cout<<"choose the letter you want\n";
    cout << "Your letter is: ";
    string s;
    cin.ignore();
    getline(cin, s,'\n');
    while (s.size()!=1||!(isalpha(s[0]))||s.empty()) {
        cout<<"wrong input please try again!!\n";
        s="";
        getline(cin, s,'\n');
    }

this->symbol=s[0];
}

// Constructor for X_O_Random_Player
template <typename T>
Word_Random_Player<T>::Word_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Word_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
    int randomchar = (rand() % 26 )+ 65;
    this->symbol = char(randomchar);
}






#endif //UNTITLED_WORD_TIC_H