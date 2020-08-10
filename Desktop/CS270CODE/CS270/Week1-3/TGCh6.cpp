// Chapter 6 examples 
#include <iostream>
using namespace std;

int main() {
   
    string in;
    cin >> in; //reads one word from input
     string in2;
    getline(cin, in2); /*Reads one entire line from input gets overridden--same as ignore*/
    getline(cin, in2); //Read one line from input
    cout << "In: " << in << endl << "In2: " << in2 << endl;
    
    
}