

#ifndef MISERETICTACTOC_H
#define MISERETICTACTOC_H

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

class MisereTicTacTocPlayer final : public Player<string> {
public:
    MisereTicTacTocPlayer(const string& n, const string& symbol) : Player<string>(n, symbol) {}
    explicit MisereTicTacTocPlayer(const string& symbol) : Player<string>(symbol) {}

    void getmove(int& x, int& y) override;
};

class MisereTicTacTocRandomPlayer final : public RandomPlayer<string> {
public:
    explicit MisereTicTacTocRandomPlayer(const string& symbol): RandomPlayer<string>(symbol){}

    void getmove(int& x, int& y) override;
};



#endif