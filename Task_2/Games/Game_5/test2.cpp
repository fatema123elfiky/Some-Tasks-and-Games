//
// Created by Fatma on 12/14/2024.
//
#include "Math_Tic_Tac_Teo.h"

int main()
{
    int choice;
    Player<int>* players[2];
    Board<int>* B = new Math_Tic_Tac_Teo_board();
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
        //cin.clear();
        //cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        cout << "Invalid Choice. Try Again.\n";
        cout << "Enter choice (1-3): ";
        cin >> choice;
    }
    switch(choice) {
        case 1:
            players[0] = new Math_Tic_Tac_Teo_player(playerXName,1);
            break;
        case 2:
            players[0] = new Math_Tic_Tac_Teo_random_player(1);
            break;
        case 3:
             players[0] = new Math_Tic_Tac_Teo_AI_player(1);
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
        //cin.clear();
        //cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        cout << "Invalid Choice. Try Again.\n";
        cout << "Enter choice (1-3): ";
        cin >> choice;
    }
    switch(choice) {
        case 1:
            players[1] = new Math_Tic_Tac_Teo_player(player2Name,2);
            break;
        case 2:
            players[1] = new Math_Tic_Tac_Teo_random_player(2);
            break;
        case 3:
            players[1] = new Math_Tic_Tac_Teo_AI_player(2);
            players[1]->setBoard(B);
            break;

    }

    // Create the game manager and run the game
    GameManager<int> game(B, players);
    game.run();

    // Clean up
    /*delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }*/

}