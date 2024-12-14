#include <iostream>

#include "UI.h"
using namespace std;



int main() {
    cout<<"##### Welcome to Our Games ##### :) !!\n\n";

    int on=1;
    while(on){
       on=UI::display_main_menu();
    }
    cout << "Thanks for Playing! :)" << endl;
    return 0;
}


