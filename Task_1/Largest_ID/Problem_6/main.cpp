#include <iostream>
#include <vector>
#include <string>

#include "Universe.h"

using namespace std;

/**
 * @brief Displays the rules for the Game of Life.
 *
 * @details prints a brief introduction
 * to the Game of Life, followed by the rules governing cell survival
 * and reproduction in the game.
 */
void Help() {
    cout << "Welcome to the Game of Life!\n";
    cout << "Rules:\n";
    cout << "- Any live cell with fewer than two live neighbors dies, as if by underpopulation.\n";
    cout << "- Any live cell with two or three live neighbors lives on to the next generation.\n";
    cout << "- Any live cell with more than three live neighbors dies, as if by overpopulation.\n";
    cout << "- Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.\n";
}

/**
 * @brief Prompts the user to select the grid dimensions for the game.
 *
 * This function displays a menu to the user, allowing them to either choose from
 * a set of predefined grid sizes (fixed dimensions) or enter custom dimensions
 * (number of rows and columns). The selected dimensions are used to initialize
 * and return a new `Universe` object with the specified grid size.
 *
 * The fixed dimensions available are:
 *  - 20 x 50
 *  - 20 x 20
 *  - 30 x 30
 *
 * The user also has the option to manually input custom dimensions.
 *
 * @return Universe A new `Universe` object initialized with the chosen grid dimensions.
 */
Universe GetDimintion(){
    // Display a menu to make user choose fixed dimensions or enter it from a file
    string menu = "What do you want?\n1) Fixed dimensions\n2) Custom dimensions\nYour Choice: ";
    vector<string> choices = {"1","2"};
    string choice = Universe::checkMenu(menu, choices);
    int rows, cols;

    if(choice == "1"){
        string FixedDimensionMenu = "Choose one of them:\n1) 20 x 50\n2) 20 x 20\n3) 30 x 30\nYour Choice: ";
        vector<string> fixedDimensions = {"1", "2", "3"};
        string fixedDimension = Universe::checkMenu(FixedDimensionMenu, fixedDimensions);
        if(fixedDimension == "1")
            rows = 20, cols = 50;
        else if(fixedDimension == "2")
            rows = 20, cols = 20;
        else
            rows = 30, cols = 30;
    }
    else{
        rows = Universe::getCorrectNumber("Enter No. of rows:");
        cols = Universe::getCorrectNumber("Enter No. of columns:");
    }

    Universe Game(rows, cols);
    return Game;
}


int main() {
    // Define the main menu text and the valid choices for the user.
    string menu = "# === Welcome to life Game === #\n1) Start the game\n2) Vogel’s Approximation ModelHelp\n3) Exit\nYour choice:";
    vector<string> choices{"1", "2", "3"};

    while (true) {
        // Display the main menu and get the user's choice.
        string choice = Universe::checkMenu(menu, choices);

        if (choice == "1") {
            Universe Game = GetDimintion();
            Game.play();
        }
        else if (choice == "2") {
            // Display the help menu with the game rules.
            Help();
            continue;
        }
        else{
            cout << "Thanks for using our game!";
            break;

        }


        // After the game session ends, ask the user if they want to play again.
        string EndMenu = "DO you want to Play again (Y/N)? : ";
        vector<string> EndChoice = {"Y", "N", "n", "y"};
        string endChoice = Universe::checkMenu(EndMenu, EndChoice);

        if (endChoice == "N" || endChoice == "n") {
            cout << "Thanks for playing!\n";
            break;
        }
    }

    return 0;
}
