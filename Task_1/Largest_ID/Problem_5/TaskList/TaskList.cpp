#include "TaskList.h"

bool TaskList::NumberValidation(const string &number){
     for(const char &i : number){
          if(!isdigit(i))
               return false;
     }
     return true;
}

void TaskList::GetDigit(const string &WhatToPrint,long long &varible){
    string temp;
    while (true){
        cout << WhatToPrint ;
        getline(cin, temp);
        if(NumberValidation(temp))
            break;
        cout << "Enter a Valid option: \n";
    }
    varible = stoll(temp);
}

void TaskList::addProcess() {
    string name, sessionName, status;
    long long PID, MemoryUsage, SessionID;

    cout << "Enter Name of Processing File: " ;
    getline(cin, name);

    cout << "Enter Session Name of Processing File: " ;
    getline(cin, sessionName);

    GetDigit("Enter Processing ID of File: ",PID);
    GetDigit("Enter Memory Usage of File: ", MemoryUsage);
    GetDigit("Enter Session ID of File: ", SessionID);

    while(true){
        long long number;
        GetDigit("What is the status of the program?\n1) Running\n2) Suspended\nYour Choice: ", number);
        if(number == 1){
            status = "Running";
            break;
        }
        if (number == 2){
            status = "Suspended";
            break;
        }
        cout << "Enter a Valid option\n" ;
    }

    Process var(name, sessionName, status, PID, MemoryUsage, SessionID);
    ProcessList.push_back(var);
}

void TaskList::displayAllProcesses(){
    if(ProcessList.empty()){
        cout << "IT is empty add first !\n";
        return;
    }
    // Schedule header
    cout << "---------------------------------------------------------------------------------------------------\n";
    cout << "|    Process Name    |   Session Name   |  Status  |   PID   | Memory Usage | Session ID |\n";
    cout << "---------------------------------------------------------------------------------------------------\n";

    // Display each process like a row in a schedule
    for (auto& process : ProcessList) {
        cout << "| " << left << setw(18) << process.GetImageName()
             << "| " << setw(17) << process.GetSessionName()
             << "| " << setw(8) << process.GetStatus()
             << "| " << setw(7) << process.GetPid()
             << "| " << setw(12) << process.GetMemoryUsage()
             << "K | " << setw(10) << process.GetSessionID() << " |\n";
        cout << "---------------------------------------------------------------------------------------------------\n";
    }
}

void TaskList::sortByName() {
    sort(ProcessList.begin(), ProcessList.end(), [](Process& a, Process& b) {
        return a.GetImageName() < b.GetImageName();
    });
}

void TaskList::sortByID() {
    sort(ProcessList.begin(), ProcessList.end(), [](Process& a, Process& b) {
        return a.GetPid() < b.GetPid();
    });
}

void TaskList::sortByMemoryUsage() {
    sort(ProcessList.begin(), ProcessList.end(), [](Process& a, Process& b) {
        return a.GetMemoryUsage() < b.GetMemoryUsage();
    });
}
