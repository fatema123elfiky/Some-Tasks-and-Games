
#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;

/**
 * @class Universe
 * @brief A class representing the grid for the Game of Life simulation.
 *
 * This class handles the creation, initialization, and manipulation of a grid for the Game of Life.
 * The grid contains cells that can either be alive ('*') or dead ('.'). It provides functionality for
 * setting up the grid manually or by loading it from a file, displaying the grid, and evolving it through
 * generations according to the rules of Conway's Game of Life.
 */
class Universe {
private:
    vector<vector<char>> grid; ///< The 2D grid representing the universe.
    int rows, cols; ///< The number of rows and columns in the grid.

    /**
     * @brief Validates whether a given row and column are within the grid boundaries.
     *
     * @param row The row index.
     * @param column The column index.
     * @param R The total number of rows in the grid.
     * @param C The total number of columns in the grid.
     * @return true if the row and column are valid, false otherwise.
     */
    static bool valid(const int &row, const int &column, const int & R, const int &C);

    /**
     * @brief Counts the number of live neighbors for a given cell.
     *
     * @param row The row index of the cell.
     * @param column The column index of the cell.
     * @return The number of live neighbors of the cell.
     */
    int count_neighbors(int row, int column) const;

    /**
     * @brief Uploads the initial state of the grid from a file.
     *
     * The file should contain a grid representation, with '*' for live cells and '.' for dead cells.
     * The file format must match the grid dimensions.
     */
    void uploadFromFile();

    /**
     * @brief Allows the user to manually set the grid's initial state.
     *
     * The user is prompted to input each cell's state (either '.' or '*') for each cell in the grid.
     */
    void setManually();

public:
    /**
     * @brief Constructor for initializing the grid.
     *
     * Initializes the grid with given row and column sizes, setting all cells to dead ('.').
     *
     * @param row The number of rows in the grid.
     * @param column The number of columns in the grid.
     */
    Universe(const int &row, const int &column) :
            grid(row, vector<char>(column, '.')),
            rows(row),
            cols(column)
            {}

    /**
     * @brief Displays a menu and returns the user's valid choice.
     *
     * @param menu The menu string to display to the user.
     * @param choices A vector containing valid choices the user can make.
     * @return The valid choice entered by the user.
     */
    static string checkMenu(const string& menu, vector<string>& choices);

    /**
     * @brief Prompts the user for a valid positive integer input.
     *
     * Repeats until the user enters a valid integer.
     *
     * @param prompt The prompt message to display to the user.
     * @return The valid integer entered by the user.
     */
    static int getCorrectNumber(const string &prompt);

    /**
     * @brief Initializes the grid with the given cell data.
     *
     * @param cells A vector of strings representing the initial state of the grid.
     */
    void initialize(const vector<string> &cells);

    /**
     * @brief Resets the grid, setting all cells to dead ('.').
     */
    void reset();

    /**
     * @brief Displays the current state of the grid.
     *
     * This function prints the grid to the console with each cell represented by '.' or '*' for dead or alive, respectively.
     */
    void display();

    /**
     * @brief Advances the simulation by one generation.
     *
     * This function applies the Game of Life rules to each cell and updates the grid accordingly.
     */
    void next_generation();

    /**
     * @brief Runs the Game of Life for a specified number of generations.
     *
     * The user is prompted for the number of generations, and the grid is updated and displayed after each generation.
     */
    void run();

    /**
     * @brief Starts the game and allows the user to choose how to set up the grid.
     *
     * The user can either upload an initial configuration from a file or set it manually by providing input for each cell.
     * After setting up the grid, the game proceeds by running the simulation.
     */
    void play();
};

#endif //UNIVERSE_H
