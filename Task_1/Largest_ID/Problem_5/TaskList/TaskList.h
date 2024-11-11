#ifndef TASKLIST_H
#define TASKLIST_H
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include "../Process/Process.h"


using namespace std;

class TaskList {
private:
    vector<Process> ProcessList;

    static bool NumberValidation(const string &number);

    static void GetDigit(const string &WhatToPrint,long long &varible);
public:
    void addProcess();

    void displayAllProcesses();

    void sortByName();
    
    void sortByID();
    
    void sortByMemoryUsage();
};


#endif
