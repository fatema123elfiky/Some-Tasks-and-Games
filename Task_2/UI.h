//
// Created by Fatma on 12/13/2024.
//

#ifndef GAMES_UI_H
#define GAMES_UI_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Games/Game_1/pyramic_Tic.h"
#include "Games/Game_2/Four_in_a_row.h"
#include "Games/Game_3/TicTacToc_Size5.h"
#include "Games/Game_4/word_tic.h"
#include "Games/Game_5/Math_Tic_Tac_Teo.h"
#include "Games/Game_6/MisereTicTacToc.h"
#include "Games/Game_7/TicTacTocSize4.h"
#include "Games/Game_8/New_tic_tac_toe_9x9.h"

using namespace std;


class UI {
public:
    static string check_menu(const string& menuText , vector<string>choices);

    static int display_main_menu();

    static int display_menu_players(string choice);

    static void Connect_4(Player<char>*player1,Player<char>*player2,Board<char>*board,int type);

    static void Pyramic(Player<char>*player1,Player<char>*player2,Board<char>*board,int type);

    static void TicSize5(Player<string>*player1,Player<string>*player2,Board<string>*board,int type);

    static void wordTic(Player<char>*player1,Player<char>*player2,Board<char>*board,int type);

    static void MathTic(Player<int>*player1,Player<int>*player2,Board<int>*board,int type);

    static void Misere(Player<string>*player1,Player<string>*player2,Board<string>*board,int type_2);

    static void TicSize4(Player<string>*player1,Player<string>*player2,Board<string>*board,int type);

    static void Tic9x9(Player<char>*player1,Player<char>*player2,Board<char>*board,int type);

};


#endif //GAMES_UI_H
