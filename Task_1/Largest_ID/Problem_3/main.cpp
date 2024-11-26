
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

/**
 * @brief Processes a word to handle punctuation and convert to lowercase.
 *
 * @param word The input string to be processed.
 * @return vector<string> A vector containing processed sub-words (if split by punctuation).
 *
 * @details This function splits the word by punctuation (excluding hyphens),
 * converts all characters to lowercase, and returns the resulting sub-words.
 */
vector<string> checkWord(const string& word) {
    vector<string> temp;
    string tempWord;

    for (int i = 0; i < word.length(); i++) {
        if (ispunct(word[i]) && word[i] != '-') { // Exclude hyphens as valid characters.
            temp.push_back(tempWord);
            tempWord = ""; // Reset temporary word.
        }
        else
            tempWord += tolower(word[i]);
    }

    temp.push_back(tempWord);
    return temp;
}

/**
 * @brief Displays a menu and validates the user's choice.
 *
 * @param menu The menu prompt to display to the user.
 * @param choices A vector of valid choices for the menu.
 * @return string The valid choice selected by the user.
 *
 * @details Loops until the user provides a valid choice. If the input is invalid,
 * it prompts the user to try again.
 */
string checkMenu(const string& menu, vector<string>& choices) {
    string choice;
    while (true) {
        cout << menu;
        getline(cin, choice);
        if (find(choices.begin(), choices.end(), choice) != choices.end())
            return choice;
        cout << "Invalid choice. Please try again.\n";
    }
}

/**
 * @brief Reads and processes words from a file stream.
 *
 * @param in The input file stream to read data from.
 * @return vector<string> A vector containing all processed words from the file.
 *
 * @details Words are read word-by-word, processed using `checkWord`, and
 * filtered to remove empty results.
 */
vector<string> takeFileInput(ifstream in) {
    vector<string> result;
    string word;
    while (in >> word) {
        vector<string> words = checkWord(word);
        for (string& w : words) {
            if (!w.empty())
                result.push_back(w); // Add non-empty words to the result.
        }
    }
    return result;
}

/**
 * @brief Prints or writes the word frequency map based on user choice.
 *
 * @param words A vector of words to calculate frequency.
 *
 * @details The function creates a frequency map of the words, then allows the user
 * to select whether to display the map in the console or write it to a file.
 */
void printWordFrequency(const vector<string>& words) {
    map<string, int> frequencyMap;

    // Calculate word frequencies.
    for (const string& word : words)
        frequencyMap[word]++;


    // Prompt user for output method.
    string Menu = "Do you want input to be in a file or console?\n1) Console\n2) File\nYour Choice: ";
    vector<string> MenuChoice = {"1", "2"};
    string choice = checkMenu(Menu, MenuChoice);

    if (choice == "1") {
        // Print to console.
        for (const auto& pair : frequencyMap)
            cout << pair.first << ": " << pair.second << endl;
    } else {
        // Write to file.
        ofstream file;
        string filename;
        while (true) {
            cout << "Enter the name of the file: ";
            getline(cin, filename);
            file.open(filename);

            if (!file.is_open())
                cout << "Error opening the file. Please try again.\n";
            else
                break;
        }

        for (const auto& pair : frequencyMap)
            file << pair.first << ": " << pair.second << endl;
        file.close();
    }
}

/**
 * @brief The main function to run the word frequency analyzer.
 *
 * @return int Exit status of the program.
 *
 * @details Continuously prompts the user for input files, processes their contents,
 * and allows the user to view or save the word frequency map. The program terminates
 * when the user chooses not to continue.
 */
int main() {
    string filename;
    ifstream in;

    while (true) {
        // Prompt for file name and validate its existence.
        while (true) {
            cout << "Enter the name of the file: ";
            getline(cin, filename);
            in.open(filename);
            if (!in.is_open())
                cout << "Error opening the file. Please try again.\n";
            else
                break;
        }

        // Process file content and calculate word frequencies.
        vector<string> allWords = takeFileInput(move(in));
        printWordFrequency(allWords);
        in.close();

        // Ask user whether to continue.
        string endMenu = "Do you want to continue?(Y/N):";
        vector<string> MenuChoice = {"Y", "N", "n", "y"};
        string choice = checkMenu(endMenu, MenuChoice);
        if (choice == "N" || choice == "n") {
            cout << "Thanks for using our app\n";
            break;
        }
    }
    return 0;
}
