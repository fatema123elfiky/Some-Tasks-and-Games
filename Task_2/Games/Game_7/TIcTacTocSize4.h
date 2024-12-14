
#ifndef TICTACTOCSIZE4_H
#define TICTACTOCSIZE4_H
#include "../../src/BoardGame_Classes.h"


class TicTacTocSize4Board : public Board<string> {
private:
    int primaryX, primaryY;
public:
    TicTacTocSize4Board();

    ~TicTacTocSize4Board() ;

    bool update_board(int x, int y, string symbol) override;

    void display_board() override;

    bool is_win() override;

    bool is_draw() override;

    bool game_is_over() override;

};

class TicTacTocSize4Player : public Player<string>{
public:
    TicTacTocSize4Player(const string& n, const string& symbol) : Player<string>(n, symbol) {}
    ~TicTacTocSize4Player() ;

    void getmove(int& x, int& y) override;
};


class TicTacTocSize4RandomPlayer : public RandomPlayer<string>{
    explicit TicTacTocSize4RandomPlayer(const string& symbol) : RandomPlayer<string>(symbol) {}

    void getmove(int& x, int& y) override;
};



#endif
