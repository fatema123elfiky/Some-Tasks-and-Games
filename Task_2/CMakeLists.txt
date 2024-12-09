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
)
