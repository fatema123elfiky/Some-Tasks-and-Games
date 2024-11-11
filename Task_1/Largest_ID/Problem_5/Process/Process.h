#ifndef PROCESS_H
#define PROCESS_H
#include <string>
using namespace std;

class Process {
private:
    string ImageName, sessionName, status;
    long long PID = 0, memoryUsage = 0 , sessionID = 0;
public:
    Process(const string& name, const string& session_name, const string& status,
        long long pid = 0, long long memory_usage = 0, long long session_id){}

    string GetStatus();

    string GetImageName();

    string GetSessionName();

    long long GetPid();

    long long GetMemoryUsage();

    long long GetSessionID();

    void SetStatus(const string& status);


    void SetMemoryUsage(long long memory_usage);
};

#endif
