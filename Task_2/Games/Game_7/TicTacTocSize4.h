
#ifndef TICTACTOCSIZE4_H
#define TICTACTOCSIZE4_H
#include "../../src/BoardGame_Classes.h"


class TicTacTocSize4Board : public Board<string> {
private:
    int primaryX = 0, primaryY = 0;
public:
    TicTacTocSize4Board();

    ~TicTacTocSize4Board();

    bool update_board(int x, int y, string symbol) override;

    void display_board() override;

    bool is_win() override;

    bool is_draw() override;

    bool game_is_over() override;

};

class TicTacTocSize4Player : public Player<string>{
public:
    TicTacTocSize4Player(const string& n, const string& symbol);
    ~TicTacTocSize4Player();

    void getmove(int& x, int& y) override;
};


class TicTacTocSize4RandomPlayer : public Player<string>{
public:
    explicit TicTacTocSize4RandomPlayer(string symbol);
    ~TicTacTocSize4RandomPlayer();

    void getmove(int& x, int& y) override;
};




#endif
