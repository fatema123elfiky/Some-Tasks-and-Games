#include "Universe.h"


bool Universe::valid(const int &row, const int &column, const int & R, const int &C) {
    return row >= 0 && row < R && column >= 0 && column < C;
}

int Universe::count_neighbors(int row, int column) const{
    static vector<int> dRow{-1, -1, -1, 0, 1, 1, 1, 0};
    static vector<int> dCol{-1, 0, 1, 1, 1, 0, -1, -1};
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

string Universe::checkMenu(const string& menu, vector<string>& choices) {
    string choice;
    while (true) {
        cout << menu;
        getline(cin, choice);
        if (find(choices.begin(), choices.end(), choice) != choices.end())
            return choice;
        cout << "Invalid choice. Please try again.\n";

    }
}

int Universe::getCorrectNumber(const string &prompt){
    string input;
    int value;
    while (true) {
        cout << prompt;
        getline(cin, input);

        // Check if input is all digits
        if (!input.empty() && all_of(input.begin(), input.end(), ::isdigit)) {
            value = stoi(input);
            break;
        }
        cout << "Invalid input. Please enter a positive integer.\n";
    }
    return value;
}

void Universe::initialize(const vector<string> &cells) {
    for(int i = 0; i < cells.size();i++){
        for(int j = 0; j < cells[0].size();j++)
            grid[i][j] = cells[i][j];
    }
}


void Universe::reset() {
    for (auto &row : grid) {
        fill(row.begin(), row.end(), '.');
    }
}

void Universe::display() {
    for (const auto &row : grid) {
        for (char cell : row)
            cout << cell << " ";
        cout << '\n';
    }
    cout << '\n';
}

void Universe::next_generation(){
    vector<vector<char>> newGrid = grid;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int aliveNeighbors = count_neighbors(i, j);

            if (grid[i][j] == '*' && (aliveNeighbors < 2 || aliveNeighbors > 3)) {
                newGrid[i][j] = '.'; // Cell dies
            } else if (grid[i][j] == '.' && aliveNeighbors == 3) {
                newGrid[i][j] = '*'; // Cell becomes alive
            }
        }
    }
    grid = newGrid; // Update grid with new state
}


void Universe::run() {
    int generations = getCorrectNumber("Enter the number of generations to run: ");
    for (int i = 0; i < generations; ++i) {
        cout << "Generation " << i + 1 << ":\n";
        next_generation();
        display();
    }
}

void Universe::uploadFromFile() {
    string filename;
    vector<string> temp;
    fstream file;

    while (true) {
        // Prompt user to enter a file name
        cout << "Enter the name of the file (Note: the diagram should use '*' for live, '.' for dead): ";
        getline(cin, filename);
        file.open(filename, ios::in);

        if (file.is_open()) {
            string line;
            temp.clear(); // Clear temp to handle repeated attempts with incorrect files
            bool isValid = true;

            // Read file line by line
            while (getline(file, line)) {
                // Check if the line length matches the number of columns in the grid
                if (line.length() != grid[0].size()) {
                    cout << "Format is incorrect. Each line must match the grid's column size (" << grid[0].size() << ").\n";
                    isValid = false;
                    break;
                }

                // Check if all characters in the line are valid ('*' or '.')
                for (char c : line) {
                    if (c != '.' && c != '*') {
                        cout << "Format is incorrect. Only '*' and '.' are allowed.\n";
                        isValid = false;
                        break;
                    }
                }

                if (!isValid) break; // Exit loop on error
                temp.push_back(line); // Add valid line to temp
            }

            // Check if the number of rows matches the grid's row size
            if (temp.size() != grid.size() && isValid) {
                cout << "Format is incorrect. The number of lines must match the grid's row size (" << grid.size() << ").\n";
                isValid = false;
            }

            file.close(); // Close the file

            if (isValid) {
                break; // Exit the loop if everything is valid
            }
        } else {
            cout << "File not found. Please try again.\n";
        }
    }

    // Initialize the grid with the validated data
    initialize(temp);
}


void Universe::setManually(){
    for(int i = 0 ; i < grid.size() ; i++){
        for(int j = 0 ; j < grid[0].size() ; j++){
            while(true){
                cout << "Row: " << i << "column: " << j << endl;
                string word;
                cout << "Enter '.' or '*' for live or dead cell: ";
                getline(cin, word);
                if(word.length() == 1 && (word[0] == '.' || word[0] == '*')){
                    grid[i][j] = word[0];
                    break;
                }
                cout << "Invalid input. Please enter '.' or '*'.\n";
            }
        }
    }
}


void Universe::play(){
    string setGameMenu = "How do you want to set your Game? \n1) Upload from file\n2) Manually\nYour choice: ";
    vector<string> setGameChoices = {"1", "2"};
    string setGameChoice = checkMenu(setGameMenu, setGameChoices);

    if (setGameChoice == "1")
        uploadFromFile();
    else if (setGameChoice == "2")
        setManually();

    run();
}
