

#ifndef MISERETICTACTOC_H
#define MISERETICTACTOC_H
#include <iostream>
#include "../../src/BoardGame_Classes.h"


class MisereTicTacToc : public Board<string> {

public:
    MisereTicTacToc();

    ~MisereTicTacToc() override;

    bool update_board(int x, int y, string symbol) override;

    void display_board() override;

    bool is_win() override;

    bool is_draw() override;

    bool game_is_over() override;

};

class MisereTicTacTocPlayer final : public Player<string>{
public:
    void getmove(int& x, int& y) override;
};

class MisereTicTacTocRandomPlayer : public RandomPlayer<string>{
public:
    void getmove(int& x, int& y) override;
};



#endif