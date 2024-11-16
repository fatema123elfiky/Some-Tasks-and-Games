#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cctype> // For isdigit
using namespace std;

// Function to validate that input is a positive integer
int get_positive_integer(const string &prompt) {
    string input;
    int value;
    while (true) {
        cout << prompt;
        cin >> input;

        // Check if input is all digits
        bool valid = !input.empty() && all_of(input.begin(), input.end(), ::isdigit);
        if (valid) {
            value = stoi(input);
            break;
        } else {
            cout << "Invalid input. Please enter a positive integer.\n";
        }
    }
    return value;
}

// Check if the cell is within bounds
bool valid(int row, int column, int R, int C) {
    return row >= 0 && row < R && column >= 0 && column < C;
}

class Universe {
private:
    vector<vector<char>> grid;
    int rows, cols;

    // Count the number of alive neighbors for a given cell
    int count_neighbors(int row, int column) {
        vector<int> dRow{-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dCol{-1, 0, 1, 1, 1, 0, -1, -1};
        int alive = 0;

        for (int i = 0; i < 8; ++i) {
            int newRow = row + dRow[i];
            int newCol = column + dCol[i];
            if (valid(newRow, newCol, rows, cols) && grid[newRow][newCol] == '*') {
                alive++;
            }
        }
        return alive;
    }

public:
    //. --> dead, * --> alive
    Universe(int row, int column) : rows(row), cols(column), grid(row, vector<char>(column, '.')) {}

    // Initialize grid with a starting layout
    void initialize(const vector<pair<int, int>> &liveCells) {
        for (auto &[r, c] : liveCells) {
            if (valid(r, c, rows, cols)) {
                grid[r][c] = '*';
            }
        }
    }

    // Reset all cells to dead
    void reset() {
        for (auto &row : grid) {
            fill(row.begin(), row.end(), '.');
        }
    }

    // Display the current state of the grid
    void display() {
        for (const auto &row : grid) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }

    // Update the grid for the next generation
    void next_generation() {
        vector<vector<char>> newGrid = grid;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int aliveNeighbors = count_neighbors(i, j);

                if (grid[i][j] == '*' && (aliveNeighbors < 2 || aliveNeighbors > 3)) {
                    newGrid[i][j] = '.'; // Cell dies
                } else if (grid[i][j] == '.' && aliveNeighbors == 3) {
                    newGrid[i][j] = '*'; // Cell becomes alive
                }
                // Else, state remains the same
            }
        }
        grid = newGrid; // Update grid with new state
    }

    // Run the game for a certain number of generations
    void run() {
        int generations = get_positive_integer("Enter the number of generations to run: ");

        for (int i = 0; i < generations; ++i) {
            cout << "Generation " << i + 1 << ":\n";
            next_generation();
            display();
        }
    }
};

int main() {
    int rows = get_positive_integer("Enter the number of rows: ");
    int cols = get_positive_integer("Enter the number of columns: ");

    Universe u(rows, cols);

    int numCells = get_positive_integer("Enter the number of initial live cells: ");

    vector<pair<int, int>> liveCells;
    cout << "Enter the coordinates of the live cells (row and column, 0-based indexing):\n";
    for (int i = 0; i < numCells; ++i) {
        int r = get_positive_integer("  Row: ");
        int c = get_positive_integer("  Column: ");
        liveCells.emplace_back(r, c);
    }

    u.initialize(liveCells);
    cout << "Initial State:\n";
    u.display();

    char continueGame = 'y';
    while (continueGame == 'y' || continueGame == 'Y') {
        u.run();
        cout << "Do you want to continue? (y/n): ";
        cin >> continueGame;
    }

    cout << "Game Over. Thanks for playing!\n";
    return 0;
}
