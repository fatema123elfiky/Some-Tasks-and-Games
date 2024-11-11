#include "Process.h"

Process::Process(const string& name, const string& session_name, const string& status,
    long long pid, long long memory_usage, long long session_id) {
    this->ImageName = name;
    this->sessionName = session_name;
    this->status = status;
    this->PID = pid;
    this->memoryUsage = memory_usage;
    this->sessionID = session_id;
}


string Process::GetImageName(){
    return this->ImageName;
}
string Process::GetSessionName(){
    return this->sessionName;
}
string Process::GetStatus(){
    return this->status;
}

long long Process::GetPid() const{
    return this->PID;
}

long long Process::GetMemoryUsage() const{
    return this->memoryUsage;
}

long long Process::GetSessionID() const{
    return this->sessionID;
}

void Process::SetStatus(const string& status){
    this->status = status;
}

void Process::SetMemoryUsage(long long memory_usage){
    this->memoryUsage = memory_usage;
}
