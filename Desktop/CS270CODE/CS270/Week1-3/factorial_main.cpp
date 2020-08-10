#include <iostream>
/*#include "factorial.cpp" //includes that file (copy and paste this file at top) */
#include "factorial.h" //includes header file
using namespace std;



int main() {
    // ask user to enter an int, until they do
    // use cin.fail() to check whether the read was successful 
    // remeber to flush the input between prompts to clear bad input
    
    int n; /*makes sure it is pos because you cant factorial a negative number*/
    
    do  {
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << "Enter an integer: ";
        cin >> n;
    } while(cin.fail() || n < 0);
    

  cout << "The factorial of " << n << " is " << fact(n) << endl; 
    
}