#ifndef TASKLIST_H
#define TASKLIST_H
#include <vector>

#include "../Process/Process.h"
using namespace std;

class TaskList {
private:
    vector<Process> ProcessList;
public:
    static void sortByName();
    static void sortByID();
    static void sortByMemoryUsage();
};


#endif
