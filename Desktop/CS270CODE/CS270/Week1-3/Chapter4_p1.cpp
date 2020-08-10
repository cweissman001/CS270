#include <iostream>
#include <vectors> /*works just like an array but it has nice methods you are used to*/
using namespace std;

int main() {
    int i = 5; //i++ or ++i is the same as i = i+1
    int next_i = i++; // sets next_i to old i, 5, i to 6
    int next_next_i = ++i; // i set to 7. sets next_next_i to 7 also
    cout << i << ", " << next_i << ", " << next_next_i << endl;
    i += 1; //short for i = i + 1, works for all basic arimetic ops
    
    int data[6]; /* you must declare data type for arrays and the values will be intionalized to whatever that space in memory was used for before */
    
    data[0] = 5;
    data[1] = data[0];
    data[7]; // Undefined behavior, language says nothing about  what happens
    
    string s = "value"; // smart version of char array
    s[0]; = 'c'; //all data types are mutable 
    string strings[6]; // every individual string will have a null char at the end
    //C-string is a null-terminated array of characters 
    char str[6] = "value"; // creates a char array with 6 characters -- dumb version of string
    //you need 6 values for the thing with only 5 spaces because you need space for null char
    char words[6][7]; // array of 6 words each with 7 characters
    
    const int s = 5; /* this int variable has been declared as immutable -if you try to change you will get an array */
    
    for(init; cond; update) {
        

    }
    init;
    while(cond){
        //stuff
        //update
    }
    
}
