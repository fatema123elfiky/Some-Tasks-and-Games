#include <iostream>
#include "Games/Game_6/MisereTicTacToc.h"
#include "Games/Game_3/TicTacToc_Size5.h"
using namespace std;

int main(){
    string choice;
    Player<string>* players[2];
    auto* B = new TicTacToc_Size5();
    string playerXName, player2Name;

    cout << "Welcome to FCAI X-O Game. :)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    getline(cin , playerXName);
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    getline(cin, choice);

    if (choice == "1") {
        players[0] = new TicTacTocPlayer(playerXName, "X");
    } else if (choice == "2") {
        players[0] = new TicTacTocRandomPlayer("X");
    } else if (choice == "3") {
        players[0] = new TicTacTocAIPlayer("X");
    } else {
        std::cout << "Invalid choice for Player 1. Exiting the game.\n";
        return 1;
    }
        players[0]->setBoard(B);


    // Set up player 2
    cout << "Enter Player 2 name: ";
    getline(cin , player2Name);
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cout << "3. Smart Computer (AI)\n";
    getline(cin, choice);

    if (choice == "1") {
        players[1] = new TicTacTocPlayer(playerXName, "O");
    } else if (choice == "2") {
        players[1] = new TicTacTocRandomPlayer("O");
    } else if (choice == "3") {
        players[1] = new TicTacTocAIPlayer("O");
    } else {
        std::cout << "Invalid choice for Player 1. Exiting the game.\n";
        return 1;
    }
    players[1]->setBoard(B);

    // Create the game manager and run the game
    GameManager<string> Game(B, players);
    Game.run();

    return 0;
}



