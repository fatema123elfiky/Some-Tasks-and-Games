#include <iostream>
#include <limits>

#include "pyramic_Tic.h"
//#include "Pyramic_Ai.h"

using namespace std;

void playgame1() {
    int choice;
    Player<char>* players[2];
    Pyramic_Board<char>* B = new Pyramic_Board<char>();
    string playerXName, player2Name;

    cout << "Welcome to Pyramic Tic_Tac_Toe Game. ^_^\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;
    while(choice < 1 || choice > 3) {
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        cout << "Invalid Choice. Try Again.\n";
        cout << "Enter choice (1-3): ";
        cin >> choice;
    }
    switch(choice) {
        case 1:
            players[0] = new Pyramic_Player<char>(playerXName,'X');
            break;
        case 2:
            players[0] = new Pyramic_Random_Player<char>('X');
            break;
        case 3:
           // players[0] = new Word_MinMax_Player<char>('X');
            players[0]->setBoard(B);
            break;

    }

    // Set up player 2
    cout << "Enter Player O name: ";
    cin >> player2Name;
    cout << "Choose Player O type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    cin >> choice;
    while(choice < 1 || choice > 3) {
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        cout << "Invalid Choice. Try Again.\n";
        cout << "Enter choice (1-3): ";
        cin >> choice;
    }
    switch(choice) {
        case 1:
            players[1] = new Pyramic_Player<char>(player2Name,'O');
            break;
        case 2:
            players[1] = new Pyramic_Random_Player<char>('O');
            break;
        case 3:
    //        players[1] = new Word_MinMax_Player<char>('O');
      //      players[1]->setBoard(B);
            break;

    }

    // Create the game manager and run the game
    GameManager<char> Pyramic_game(B, players);
    Pyramic_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

  //  return ;
}
