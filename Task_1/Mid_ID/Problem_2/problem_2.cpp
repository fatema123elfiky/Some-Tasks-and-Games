#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

class StringSet{

private:
    vector<string>strings;

    string ValidationFile(string name){

        while (true){
            ifstream files(name);
            try {
                if (files.is_open())
                    break;
                else {
                    throw runtime_error("please enter again \n");
                }

            }catch(exception & e){//exception is parent to the runtime error //"class"
                cout<<"Please try again !!\n\n Enter a Valid File : ";
                getline(cin,name);

            }

        }
        return name;

    }
    bool IsFound(string document){
        for (int i = 0; i < strings.size(); ++i) {
            if(document==strings[i])
                return true;
        }
        return false;
    }


public:
    StringSet(string name , string option){

        if(option=="1"){//1 --> for file

         name= ValidationFile(name);
         ifstream file (name);
         string ins;

         while (!file.eof()){
         x: 
                file>>ins;
                if(ins.empty())
                    goto x;
                string store;
                for(auto & c :ins){

                   if(!ispunct(c)){
                       store.push_back(tolower(c));
                   }

               }

             if(!IsFound(store)&&!store.empty())
             {
                 strings.push_back(store);
             }

            }

        }

        else{// --> for string

            string store;
            for (int i = 0; i < name.size(); ++i) {
                if(!ispunct(name[i])&&name[i]!=' '){
                    store.push_back(tolower(name[i]));
                }else{

                    if(!IsFound(store)&&!store.empty()){ strings.push_back(store); }
                    store.clear();

                }
            }

            if(!store.empty()){
                if(!IsFound(store)){ strings.push_back(store); }
            }

        }

    }//done

    void add (string added)
    {
        //adding a string seeking weather there is a punctuation or not to remove it and add it to the query
        string store;
        for (int i = 0; i < added.size(); ++i) {
            if(!ispunct(added[i])&&added[i]!=' '){
                store.push_back(tolower(added[i]));
            }else{

                if(!IsFound(store)&&!store.empty()){ strings.push_back(store); }
                store.clear();

            }
        }

        if(!store.empty()){
            if(!IsFound(store)){ strings.push_back(store); }
        }

    }//done

    void remove(string removed){

        //to lower the word
        for(auto & c: removed){
            c= tolower(c);
        }

        // search for the word in the query or not to remove
        for (int i = 0; i < strings.size(); ++i) {
            if(strings[i]==removed)
                strings.erase(strings.begin()+i);
        }
    }//done

    void clear(){
       strings.clear();
    }//done

    int NumberOfStrings(){
        return strings.size();
    }//done

    StringSet operator+(StringSet document){

        StringSet NewSet("","2");
        NewSet.clear();

        //add first query the object who called
        for (int i = 0; i < strings.size(); ++i) {
            NewSet.add(strings[i]);
        }

        //add the second query without any repeating to the new query
        for (int i = 0; i < document.NumberOfStrings(); ++i) {

            if(!IsFound(document.strings[i])){ NewSet.add(document.strings[i]); }

        }

        return NewSet;


    }//done

    StringSet operator*(StringSet document){
        StringSet New(" ","2");
        New.clear();
        for (int i = 0; i < strings.size() ; ++i) {

            for (int j = 0; j < document.strings.size(); ++j) {
                if(document.strings[j]==strings[i]){

                    New.add(document.strings[j]);
                    break;

                }
            }

        }
        return New;

    }//done

    double Similarity(StringSet target ){ //test return

        double common_size=0;
        for (int i = 0; i < target.strings.size(); ++i) {
            for (int j = 0; j < strings.size(); ++j) {
                if(target.strings[i]==strings[j])
                    common_size++;
            }
        }
        return (common_size) / ( pow(strings.size(),0.5) * pow( target.strings.size(),0.5) ) ;

    }

    void display(){

        cout<<'['<<' ';
        for (int i = 0; i < strings.size()-1; ++i) {
            cout<<strings[i]<<',';
        }
        cout<<strings[strings.size()-1]<<' ';
        cout<<']'<<'\n';
        
    }//done

};

void Demo_1(StringSet * set1,StringSet * set2){
    //That demo for trying all simple methods
    string add;
    cout<<"The first query before adding : ";
    set1->display();

   cout<<"Enter what you want to add to the first query : ";
   getline(cin,add);
   set1->add(add);

    cout<<"The first query after adding : ";
    set1->display();

    cout<<"The second query before adding : ";
    set2->display();

    cout<<"Enter what you want to add to the Second query : ";
    getline(cin,add);
    set2->add(add);

    cout<<"The second query after adding : ";
    set2->display();

    cout<<"first query before clear its size is : "<<set1->NumberOfStrings()<<'\n';
    set1->clear();
    cout<<"first query after clear its size is : "<<set1->NumberOfStrings()<<'\n';

    cout<<"Enter the word you want to remove from the second query : ";
    cin>>add;cin.ignore();

    set2->remove(add);
    cout<<"The size of the second query after deleting : "<<set2->NumberOfStrings()<<'\n';

}

void Demo_2(StringSet * set1,StringSet * set2){

    // That Demo trying the overloaded operators (+,*)
    cout<<"The first query before adding the two queries : \n";
    set1->display();

    cout<<"The second query before adding the two queries : \n";
    set2->display();

    StringSet NewOne("","");
    NewOne.clear();

    NewOne=*(set1) + *(set2);

    cout<<"The new query : \n";
    NewOne.display();
    cout<<"its size : "<<NewOne.NumberOfStrings()<<'\n';

    cout<<"Now , we will get the common between the two sets !\n";

    StringSet common("","");
    common.clear();

    common=*(set1) * *(set2);

    cout<<"The new query : \n";
    if(common.NumberOfStrings()!=0){ common.display(); }
    else{cout<<"There is nothing is common between the two queries \n";}
    cout<<"its size : "<<common.NumberOfStrings()<<'\n';


}

void Demo_3(StringSet * set1,StringSet * set2){
    //That Demo try the function of similarity
    cout<<"The first query looks like : \n";
    set1->display();

    cout<<"The second query looks like : \n";
    set2->display();

    double coefficient=set1->Similarity(*(set2));
    if(coefficient==0 ){
        cout<<"The two files are not similar \n";
    }else
        cout<<"They are similar and the coefficient of similarity = "<<coefficient<<'\n';


}


int main(){

    cout<<" #### Welcome to the document similarity #### \n\n";

    while (true){
        vector<StringSet * >sets(2);
        string choice;
        cout<<"Choose from the menu for the first query: \n\n1.form new query by adding file \n"
            << "2.form new query by adding string\n3.Exit\n";

        cout<<"Enter your choice : ";
        cin>>choice;
        while(choice!="1"&&choice!="2"&&choice!="3"){
            cout<<"Enter a valid choice : ";
            cin>>choice;
        }
        cin.ignore();

        if(choice=="1"){
            cout<<"Enter the name of the file : ";
            string name;
            getline(cin,name);
            sets[0]=new StringSet(name,"1");

        }else if(choice=="2"){
            cout<<"Enter the string : ";
            string enter;
            getline(cin,enter);
            sets[0]=new StringSet(enter,"2");
        }else{
            cout<<"### Thanks for using the app ###\n";
            break;
        }


        cout<<"Choose from the menu for the second query: \n\n1.form new query by adding file \n"
            << "2.form new query by adding string\n3.Exit\n";

        cout<<"Enter your choice : ";
        cin>>choice;
        while(choice!="1"&&choice!="2"&&choice!="3"){
            cout<<"Enter a valid choice : ";
            cin>>choice;
        }
        cin.ignore();


        if(choice=="1"){
            cout<<"Enter the name of the file : ";
            string name;
            getline(cin,name);
            sets[1]=new StringSet(name,"1");

        }else if(choice=="2"){
            cout<<"Enter the string : ";
            string enter;
            getline(cin,enter);
            sets[1]=new StringSet(enter,"2");
        }else{
            cout<<"### Thanks for using the app ###\n";
            break;
        }


        cout <<"Choose from the menu which one to implement:\n"
        <<"1.Demo_1\n"<<"2.Demo_2\n3.Demo_3\n4.Exit\n";

        cout<<"Enter your choice : ";
        cin>>choice;
        while(choice!="1"&&choice!="2"&&choice!="3"&&choice!="4"){
            cout<<"Enter a valid choice : ";
            cin>>choice;
        }
        cin.ignore();

        if(choice=="1"){
            Demo_1(sets[0],sets[1]);
        }else if(choice=="2"){
            Demo_2(sets[0],sets[1]);
        }else if(choice=="3"){
            Demo_3(sets[0],sets[1]);
        }else{
            cout<<"### Thanks for using the app ###\n";
            break;
        }


      delete sets[0];
      delete sets[1];

    }



}
