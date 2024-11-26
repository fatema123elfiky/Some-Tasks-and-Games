#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;
// to add colors in the console
const std::string CYAN = "\033[96m";
const std::string RESET = "\033[0m";
const std::string YELLOW = "\033[93m";
const std::string BRIGHT_RED = "\033[1;31m";
const std::string UNDERLINE = "\033[4m";

class Student {
    int ID;
    string name;
public:
    Student(string name = "none", int ID = 0) {
        this->ID = ID;
        this->name = name;
    }
    int getID() {
        return ID;
    }
    string getname() {
        return name;
    }
    friend  ostream& operator<<(ostream& os, const Student& s);
    bool operator==(const Student& s) 
    {
        if (this->getID() == s.ID && this->getname() == s.name) 
        {
            return true;
        }
        return false;
    }

};
ostream& operator<<(ostream& os, const Student& s) {
    os << CYAN << '{' << s.name << ',' << s.ID << '}' << RESET;
    return os;
}



//template to make the vector take any data type
template <typename T>
// my set class
class Set1 {

    vector <T> myset;
    int size;
public:

    Set1() {
        size = 0;

    }
    //operator overloadin for [] as a practice for me
    T& operator[](size_t index) {

        return myset[index];
    }
    // get size knowing that i can simply return myset.size() but as a practice for me
    int getSize() {
        return size;
    }
    //bool to check if the element is existed to use it again in push and to print if it is existed or not  
    bool check(const T& n) {
        for (int i = 0;i<myset.size();i++) {
            if (myset[i] == n) {
                return true;
            }
        }
        return false;
    }
    //print if the element is existed by using check function
    void existed(T n) {
        if (check(n))
        {
            cout <<CYAN << n << " is existed\n" << RESET;
        }
        else {
            cout << YELLOW << n << " doesnot  exist\n"<<RESET;
        }

    }
    //if the element is not existed then add it in the vector and increase the size by one
    void push(T n) {

        if (!(check(n))) {
            myset.push_back(n);
            size++;
        }
    }
    // delete the element if it is existed after checking if the vector is empty or not
    // if the element does not exist then print the element is not existed 
    void pop(T n)
    {
        if (size)
        {
            int i;
            bool check = false;
            for (i = 0; i < size; ++i)
            {
                if (myset[i] == n)
                {
                    check = true;
                    break;
                }
            }
            if (check)
            {
                myset.erase(myset.begin() + i);
                size--;
            }
            else {
                cout << n << "already is not existed in the set\n";
            }
        }
        else {
            cout << "Set is empty, cannot remove \n";
        }
    }
    //allocation as a dynamic array
    T* allocate() {
        T* array = new T[myset.size()];
        for (int i = 0; i < myset.size(); ++i) {
            array[i] = myset[i];
        }
        return array;
    }

    template <typename U>
    friend ostream& operator<<(ostream& os, const Set1<U>& vec);


};
//operator overloading to print the object as a practice for me
template <typename T>
ostream& operator<<(ostream& os, const Set1<T>& vec) {

    if (vec.size > 0) {
        for (int i = 0; i < vec.size; i++) {
            if (i == 0) {
                os << CYAN<<'{' << vec.myset[i] << ',';
            }
            else if (i == vec.size - 1) {
                os << CYAN << vec.myset[i] << '}' << endl;
            }
            else {
                os << CYAN << vec.myset[i] << ',';
            }

        }
        cout << RESET;
    }
    else {
        os << "The set is empty.\n";
    }
    return os; 
}

//implementaion of the class Set1
int main() {

    cout <<BRIGHT_RED <<"*************************welcome to problem 4 ^_^*************************\n"<<RESET;

    while (true)
    {
        double choice;
        cout << YELLOW <<"choose from the menu the kind of data type of the set\n"
            << "1-string\n"
            << "2-double\n"
            << "3-integer\n"
            << "4-char\n"
            << "5-class of student\n"
            << "6-exit\n "
            <<RESET
            << UNDERLINE << "your choice is"<<RESET <<" : ";
        cin >> choice;
        cout << "\n";
        //validation for choice
        while (cin.fail() || trunc(choice) != choice || (choice <= 0 || choice >6))
        {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a valid integer from 1 to 5.\n";
            cin >> choice;
        }
        if (choice == 1)
        {

            Set1<string> stringSet;
            stringSet.push("Apple");
            stringSet.push("Banana");
            stringSet.push("Banana");
            stringSet.push("ice cream");
            
            cout << "string set after adding 2 of Banana and apple and ice cream\n";
            cout << "Set of strings:\n" << stringSet;
            cout << "the number of the set :" << CYAN<<stringSet.getSize()<<RESET<<endl;
            stringSet.pop("Banana");
            cout << "Set of strings after deleting item Banana:\n" << stringSet;
            cout << "the number of the set after deleting :" << CYAN << stringSet.getSize() << RESET << endl;
            stringSet.existed("Banana");
            stringSet.existed("ice cream");

            cout << UNDERLINE << "print the set after allocating string set in it as a dynamic array" << RESET << "\n";
            string* set = stringSet.allocate();
            int size = stringSet.getSize();
            for (int i = 0;i<size;i++) {
                if (i==0)
                {
                    cout << CYAN<<'{' << set[i] << ',';
                }else if(i == size-1)
                {
                    cout <<   set[i] << '}'<<endl;
                }else
                {
                    cout << set[i] << ',';
                }
                
               
            }
            delete[] set;
            cout << RESET;
            cout << "\n\n";
        }
        else if (choice == 2)
        {
            Set1<double> doubleSet;
            doubleSet.push(1.23);
            doubleSet.push(3.14);
            doubleSet.push(3.14);
            doubleSet.push(3.15);
            cout << "Double set after adding 2 of the number 3.14 and 1.23 and 3.15\n";
            cout << "Set of doubles:\n" << doubleSet;
            cout << "the number of the set :" << CYAN << doubleSet.getSize() << RESET << endl;
            doubleSet.pop(3.14);
            cout << "Set of Doubles after deleting item 3.14:\n" << doubleSet;
            cout << "the number of the set after deleting :" << CYAN << doubleSet.getSize() << RESET << endl;
            doubleSet.existed(3.14);
            doubleSet.existed(3.15);
            
            cout << UNDERLINE << "print the set after allocating double set in it as a dynamic array" << RESET << "\n";
            double* set = doubleSet.allocate();
            int size = doubleSet.getSize();
            for (int i = 0; i < size; i++) {
                if (i == 0)
                {
                    cout << CYAN << '{' << set[i] << ',';
                }
                else if (i == size - 1)
                {
                    cout << set[i] << '}' << endl;
                }
                else
                {
                    cout << set[i] << ',';
                }


            }
            delete[] set;
            cout << RESET;
            cout << "\n\n";
        }
        else if (choice == 3)
        {
            Set1<int> intSet;
            intSet.push(1);
            intSet.push(2);
            intSet.push(2);
            intSet.push(3);
            cout << "after adding 2 of the number 2 and 1 and 3\n";
            cout << "Set of integers: " << intSet;
            cout << "the number of the set :" << CYAN << intSet.getSize() << RESET << endl;
            intSet.pop(2);
            cout << "Set of integers after deleting number 2: " << intSet;
            cout << "the number of the set after deleting :" << CYAN << intSet.getSize() << RESET << endl;
            intSet.existed(2);
            intSet.existed(3);

            cout << UNDERLINE << "print the set after allocating integers set in it as a dynamic array" << RESET << "\n";
            int* set = intSet.allocate();
            int size = intSet.getSize();
            for (int i = 0; i < size; i++) {
                if (i == 0)
                {
                    cout << CYAN << '{' << set[i] << ',';
                }
                else if (i == size - 1)
                {
                    cout << set[i] << '}' << endl;
                }
                else
                {
                    cout << set[i] << ',';
                }


            }
            delete[] set;
            cout << RESET;
            cout << "\n\n";
        }
        else if (choice == 4)
        {
            Set1<char> charSet;
            charSet.push('a');
            charSet.push('b');
            charSet.push('b');
            charSet.push('c');
            cout << "after adding 2 of char b and char c and char a \n";
            cout << "Set of chars: " << charSet;
            cout << "the number of the set :" << CYAN << charSet.getSize() << RESET << endl;
            charSet.pop('b');
            cout << "Set of chars after deleting char b : " << charSet;
            cout << "the number of the set after deleting:" << CYAN << charSet.getSize() << RESET << endl;
            charSet.existed('b');
            charSet.existed('c');

            cout << UNDERLINE << "print the set after allocating chars set in it as a dynamic array" << RESET << "\n";
            char* set = charSet.allocate();
            int size = charSet.getSize();
            for (int i = 0; i < size; i++) {
                if (i == 0)
                {
                    cout << CYAN << '{' << set[i] << ',';
                }
                else if (i == size - 1)
                {
                    cout << set[i] << '}' << endl;
                }
                else
                {
                    cout << set[i] << ',';
                }


            }
            delete[] set;
            cout << RESET;
            cout << "\n\n";
        }
        else if(choice==5)
        {
            Set1<Student> objset;
            Student s1("alaa", 20230064);
            Student s2("tarek", 20230065);
            Student s3("mohamed", 20230066);
            objset.push(s1);
            objset.push(s2);
            objset.push(s2);
            objset.push(s3);
            

            cout << "after adding 2 of student tarek and alaa and moahemd \n";
            cout << "Set of students: " << objset;
            cout << "the number of the set :" << CYAN << objset.getSize() << RESET << endl;
            objset.pop(s2);
            cout << "Set of students after deleting student tarek : " << objset;
            cout << "the number of the set after deleting:" << CYAN << objset.getSize() << RESET << endl;
            objset.existed(s2);
            objset.existed(s3);

            cout << UNDERLINE << "print the set after allocating student set in it as a dynamic array" << RESET << "\n";
            Student* set = objset.allocate();
            int size = objset.getSize();
            for (int i = 0; i < size; i++) {
                if (i == 0)
                {
                    cout << CYAN << '{' << set[i] << ',';
                }
                else if (i == size - 1)
                {
                    cout << set[i] << '}' << endl;
                }
                else
                {
                    cout << set[i] << ',';
                }


            }
            delete[] set;
            cout << RESET;
            cout << "\n\n";


        }else

        {
            cout<< BRIGHT_RED<< "thanks for using the program ^_^\n"<<RESET;
            break;
        }

    }
    return 0;
}




