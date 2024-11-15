#include <iostream>
#include <limits>
#include <fstream>
using namespace std;
#define ll long long


/*
 * @File      : A1_T1_S23_20231109.cpp
 * @brief     : This Program contains Different Problems/Games that serve different Tasks
 * @auther    : Alaa Tarek Mohamed Salah Mohamed El-Den Ahmed
 * @ID        : 20230064
 * @Section   : S23
 * @date      : 15 Nov 2024
 * @Details   : This program contains Problems 1 :
 */


//validation for integer inputs
ll  validation (ll &x,string message="please enter a positive intger number")
{
    cin>>x;
    //validation of the input
    while(cin.fail()||x<0)
    {
        cout<<message<<endl;
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cin>>x;
    }
    return x;
}
//Base class
class LabelGenerator{
protected:
    ll number;
   string name;
public:
    LabelGenerator(){
        number=0;
    }
   LabelGenerator(string n,ll num){
       name=n;
       number=num;
   }
virtual string nextLabel()
   {
       number++;
        return name+' '+to_string(number-1);
   }
};

// Derived class
class FileLabelGenerator : public LabelGenerator {
    string filename;
    ll start;
public:

    FileLabelGenerator(string n,ll num,string file_name ){
        name=n;
        number=num;
        start=number;
        filename=file_name;
    }
    string nextLabel()
    {
        number++;
fstream file;
file.open(filename);
string input,line;
        ll i;
        for ( i = 0; i <= (number-1)-start||file.eof(); ++i) {
            getline(file,input);
            if (i==(number-1)-start){
                line=input;
                break;
            }
        }
if (line.empty()) {
    return name+' '+to_string(number-1)+" no caption ";
}
        file.close();
        return name+' '+to_string(number-1)+' '+line;
    }
};





// implemntation

int main () {
    //input for the first label to be generated
string label1 , label2 , label3;
ll n1 , n2 , n3 , loops;

cout<<"enter the name of the first label you want:\n";

 cin>>label1;

cout<<"enter the number you want to start from :\n";

n1=validation(n1);
    // object of label1
LabelGenerator figureNumbers(label1,n1);
    //input for the second label to be generated
cout<<"enter the name of the seconed label you want:\n";

cin>>label2;

cout<<"enter the number you want to start from :\n";
    //validation of the start number to be just numbers are allowed
n2=validation(n2);
    // object of label2
LabelGenerator pointNumbers(label2, n2);
    cout<<"choose the number of "<<label1<<" labels you want :\n";
    loops=validation(loops);

    cout << label1<<" numbers: ";

    for (int i = 0; i < loops; i++) {
        if (i==loops-1) {
            cout << figureNumbers.nextLabel();
        }else
            {
            cout << figureNumbers.nextLabel() << ", ";
            }
    }
    cout<<"\nchoose the number of "<<label2<<" labels you want :\n";
    loops=validation(loops);

    cout << endl <<label2<< " numbers: ";
    for (int i = 0; i < loops; i++) {
        if (i==loops-1)
            {
            cout << pointNumbers.nextLabel();
            }else
            {
            cout << pointNumbers.nextLabel() << ", ";
            }
    }

    cout<<"\nchoose the number of extra "<<label1<<" labels you want :\n";
    loops=validation(loops);
    cout << endl << "More  "<<label1<<" : ";
    for (int i = 0; i < loops; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl;

    //the file section :
    cout<<"enter the name of the third label you want:\n";
    cin>>label3;
    cout<<"enter the number you want to start from :\n";
    n3=validation(n3);
string Filename;
    cout<<"enter the name of caption file:\n";
    cin>>Filename;
    fstream file;
    file.open(Filename);
    while(!file){
        cout<<"the file name is incorrect please try again \n";
        cin>>Filename;
        file.clear(); // Clear the previous fail state
        file.open(Filename);
    }
    file.close();
 FileLabelGenerator figureLabels (label3, n3, Filename);
    cout<<"choose the number of labels  you want :\n";
    loops=validation(loops);
    cout << label3<<" labels: \n";
    for (int i = 0; i < loops; i++) {
        cout << figureLabels.nextLabel() << endl;

    }
    return 0;
}
