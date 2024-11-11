#include <iostream>
#include <vector>
#include <algorithm>
#include "TaskList/TaskList.h"
using namespace std;

string menuCheck(const string& Menu, vector<string>& choices) {
    string choice;
    while (true) {
        cout << Menu;
        getline(cin, choice);

        // Check if the input is one of the valid choices
        if (find(choices.begin(), choices.end(), choice) != choices.end())
            break;
        cout << "Invalid choice. Please try again.\n";
    }
    return choice;
}
void startTaskManger(){
    TaskList TaskManger;
    while (true){
        TaskManger.displayAllProcesses();
        string taskMenu = """# ====== Task Menu ====== #\nTasks:\n1) Add Task List\n2) Sort Tasks according to Name\n3) Sort Tasks according to ID\n4) Sort Tasks according to Memory Usage\nYour Choice:";
        vector<string> choices = {"1", "2", "3", "4", "5"};
        string choice = menuCheck(taskMenu, choices);
        if (choice == "1")
            TaskManger.addProcess();
        else if (choice == "2")
            TaskManger.sortByName();
        else if (choice == "3")
            TaskManger.sortByID();
        else if (choice == "4")
            TaskManger.sortByMemoryUsage();
        else
            break;
    }
}

int main(){
    string MainMenu = """# ====== Welcome To TaskManger ====== #\nMain Menu:\n1) Start Program\n2) Exit Program\nYour Choice:";
    vector<string> choices = {"1", "2"};
    string choice = menuCheck(MainMenu, choices);
    if (choice == "1")
        startTaskManger();
    cout << "Thanks For Using our Program\n";
    return 0;
}
