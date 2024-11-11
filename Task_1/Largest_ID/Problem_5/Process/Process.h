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
        long long pid, long long memory_usage, long long session_id);

    string GetImageName();

    string GetSessionName();

    string GetStatus();

    long long GetPid() const;

    long long GetMemoryUsage() const;

    long long GetSessionID() const;

    void SetStatus(const string& status);

    void SetMemoryUsage(long long memory_usage);
};

#endif
