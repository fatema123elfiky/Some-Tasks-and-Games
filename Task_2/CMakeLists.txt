cmake_minimum_required(VERSION 3.28)
project(Task_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task_2 main.cpp
        Games/Game_2/Four_in_a_row.cpp
        Games/Game_2/Four_in_a_row.h
        Games/Game_5/Math_Tic_Tac_Teo.cpp
        Games/Game_3/TicTacToc_Size5.h
        Games/Game_3/TicTacToc_Size5.cpp
        Games/Game_6/MisereTicTacToc.h
        Games/Game_6/MisereTicTacToc.cpp
        Games/Game_8/Tic_Tac_Toe_9x9.h
        Games/Game_8/Tic_Tac_Toe_9x9.cpp
        Games/Game_8/Tic_Tac_Toe_3x3.cpp
        Games/Game_7/TIcTacTocSize4.h
        Games/Game_7/TIcTacTocSize4.cpp
        UI.cpp
        UI.h
        Games/Game_8/Tic_Tactoe_9x9.cpp
        Games/Game_8/Tic_Tac_Toe_9x9.h
        Games/Game_5/Math_Tic_Tac_Teo.h
        Games/Game_4/word_tic.h
        Games/Game_4/word_tic.cpp
        Games/Game_3/TicTacToc_Size5.h
        Games/Game_2/Four_in_a_row.h
        Games/Game_1/pyramic_Tic.h
        Games/Game_1/pyramic_Tic.cpp
)
