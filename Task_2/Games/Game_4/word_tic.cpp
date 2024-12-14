#include <iostream>
#include "word_tic.h"
//#include "MinMaxPlayer.h"

using namespace std;

void playgame4() {
    int choice;
    Player<char>* players[2];
    Word_Board<char>* B = new Word_Board<char>();

    string playerXName, player2Name;

    cout << "Welcome to Word Tic Tac Toe Game. ^_^\n";

    // Set up player 1
    cout << "Enter Player 1 name: ";
    cin >> playerXName;
    cout << "Choose Player 1 type:\n";
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
            players[0] = new Word_Player<char>(playerXName);
        break;
        case 2:
            players[0] = new Word_Random_Player<char>();
        break;
        case 3:
            //players[0] = new Word_MinMax_Player<char>(' ');
                //players[0]->setBoard(B);
                    break;

    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
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
            players[1] = new Word_Player<char>(player2Name);
        break;
        case 2:
            players[1] = new Word_Random_Player<char>();
        break;
        case 3:
            //        players[1] = new Word_MinMax_Player<char>('O');
                //      players[1]->setBoard(B);
                    break;

    }

    // Create the game manager and run the game
    GameManager<char> Word_game(B, players);
    Word_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    //  return ;
}
