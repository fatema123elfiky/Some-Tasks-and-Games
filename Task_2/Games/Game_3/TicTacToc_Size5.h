
#ifndef TICTACTOC_SIZE5_H
#define TICTACTOC_SIZE5_H
#include <iostream>
#include <string>
#include "../../src/BoardGame_Classes.h"

using namespace std;

class TicTacToc_Size5 : public Board<string>{

};

class TicTacTocPlayer : public Player<string>{

};

class TicTacTocRandomPlayer : public RandomPlayer<string>{

};

#endif
