#include <iostream>
#include <cstdlib>
#include <fstream>
#include<vector>
#include<algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

bool Isdigit(string s){
    for(auto c :s){
        if(!isdigit((c))&&c!=',')
            return false;
    }
    return true;
}

class process{
private:
    string name,PID,sessionName,session;
    int  memo;
public:
    process(string name,string PID, int  memo,string session,string sessionName){
        this->name=name;
        this->PID=PID;
        this->memo=memo;
        this->session=session;
        this->sessionName=sessionName;
    }
    string getter_PID()
    {
        return PID;
    }
    string getter_name(){
        return name;
    }
    int getter_memo(){
        return memo;
    }
    string getter_session(){
        return session;
    }
    string getter_sessionName(){
        return sessionName;
    }
};

bool PIDSort(process * PID1 , process * PID2){
    return PID1->getter_PID()<PID2->getter_PID();
}
bool NameSort(process * PID1 , process * PID2){
    return PID1->getter_name()<PID2->getter_name();
}
bool MemoSort(process * PID1 , process * PID2){
    //if()
    return PID1->getter_memo()<PID2->getter_memo();
}

class TaskManager {
private:
    vector<process*>processes;
public:
    TaskManager(){
        int result = system("tasklist > processes.txt");
        ifstream file("processes.txt");
        string names;
        for (int i = 0; i < 3; ++i) {
            getline(file,names);
        }
        names.clear();
        while (!file.eof()){

            getline(file,names);
            if(names.empty())
                continue;
            std::istringstream input(names);
            string s;
            string PID,sessionName,session,name;
            int memo;

            while(!input.eof()){
                input>>s;
                if(!Isdigit(s))
                    name=name+s+' ';
                else
                    break;
            }
            //if(name.e)name.pop_back();
            PID=s;
            input>>s;sessionName=s;
            input>>s;session=s;
            input>>s;/*memo=s;*//*input>>s;memo=memo+s;*/
            for (int i = 0; i < s.size(); ++i) {
                if(s[i]==',')
                    s.erase(i+s.begin());
            }
            memo=stoi(s);
            processes.push_back(new process(name,PID,memo,session,sessionName));
        }
    }
    void display(string option){
        if(option=="1"){
            sort(processes.begin(),processes.end(), PIDSort);
        }else if(option=="2"){
            sort(processes.begin(),processes.end(), NameSort);
        }else{
            sort(processes.begin(),processes.end(), MemoSort);
        }
        cout<<"Image Name                     PID Session Name        Session#    Mem Usage\n"
            <<"========================= ======== ================ =========== ============\n";
        for (int i = 0; i < processes.size(); ++i) {
           /* if(!(processes[i]->getter_memo().empty()&&processes[i]->getter_name().empty()
            &&processes[i]->getter_session().empty()&&processes[i]->getter_sessionName().empty()&&processes[i]->getter_PID().empty()))            {
*/                cout << left << setw(25) << processes[i]->getter_name()<<' ';
                cout <<right<< setw(8)<<processes[i]->getter_PID() << ' ';
                cout << left << setw(16) << processes[i]->getter_sessionName()<<' ';
                cout <<right<<setw(11)<< processes[i]->getter_session() << ' ';
                cout << right << setw(12) << processes[i]->getter_memo() << ' ' << 'k' << '\n';
            //}
        }

    }
~TaskManager(){
    for (int i = 0; i < processes.size(); ++i) {
        delete processes[i];
    }
    }

};



int main(){

    while(true){
        cout << "Welcome to the implemented task manager\n\n";
        cout << "Choose from the following: \n";
        cout << "1.display ordered according to name\n2.display ordered according to PID\n3.display ordered according to memory usage\n4.Exit\n";
        cout<<"\nEnter your choice : ";
        string choice ;cin>>choice;
        while (choice!="1"&&choice!="2"&&choice!="3"&&choice!="4"){
            cout<<"Enter a valid choice : ";
            cin>>choice;
        }
        cin.ignore();
        TaskManager t;
        if(choice=="4")
            break;
        else
            t.display(choice);

    }
}