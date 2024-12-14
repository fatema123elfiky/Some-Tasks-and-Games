
#ifndef TICTACTOC_SIZE5_H
#define TICTACTOC_SIZE5_H
#include <iostream>
#include <map>
#include <string>
#include "../../src/BoardGame_Classes.h"

using namespace std;

class TicTacToc_Size5 : public Board<string>{
    map<string, int> winningNumber;
public:
    TicTacToc_Size5();

    ~TicTacToc_Size5() ;

    bool update_board(int x, int y, string symbol) override;

    void display_board() override;

    bool is_win() override;

    bool is_draw() override;

    bool game_is_over() override;
};

class TicTacTocPlayer final : public Player<string>{
public:
    TicTacTocPlayer(const string& n, const string& symbol) : Player<string>(n, symbol) {}
    ~TicTacTocPlayer() ;
    void getmove(int& x, int& y) override;
};

class TicTacTocRandomPlayer final: public RandomPlayer<string>{
public:
    explicit TicTacTocRandomPlayer( const string& symbol) : RandomPlayer<string>(symbol) {};
    ~TicTacTocRandomPlayer() ;
    void getmove(int& x, int& y) override;
};


class TicTacTocAIPlayer final : public Player<string>{
public:
    explicit TicTacTocAIPlayer(const string& symbol);
    ~TicTacTocAIPlayer() ;
    void getmove(int& x, int& y) override;

private:
    int calculateMinMax(string s, bool isMaximize);
    pair<int, int> BestMove();

};
#endif
