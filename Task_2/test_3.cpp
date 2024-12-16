//
// Created by Fatma on 12/14/2024.
//
#include "New_tic_tac_toe_9x9.h"
int main()
{
    int choice;
    Player<char>* players[2];
    Board<char>* B = new Tic_Tac_Toe_9x9_board();
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
            players[0] = new Tic_Tac_Toe_9x9_player(playerXName,'X');
            break;
        case 2:
            players[0] = new Tic_Tac_Toe_9x9_random_player('X');
            break;
        case 3:
            //players[0] = new ('X');
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
            players[1] = new Tic_Tac_Toe_9x9_player(player2Name,'O');
            break;
        case 2:
            players[1] = new Tic_Tac_Toe_9x9_random_player('O');
            break;
        case 3:
            //players[1] = new AI_Player_Connect_Four('O');
            players[1]->setBoard(B);
            break;

    }

    // Create the game manager and run the game
    GameManager<char> game(B, players);
    game.run();

    // Clean up
    /*delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }*/

}