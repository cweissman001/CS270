#include <iostream>
#include "Caesar.h"
using namespace std;
//In this file, use the Ceasar class from the library you just created to 
// interact with the user.  You may reuse code you wrote for the 
// previous assignment here if you think it would be useful, but the 
// current application MUST use the new object-oriented library interface 
// to do encoding and decoding.

int main() {

	
string keyword;
string sentence; 
cout << "Enter a message : ";
getline(cin, sentence);
cout << "Enter a keyword: ";
getline(cin, keyword);

cout << "Would you like to encode or decode the message? 1 for encode and 2 for decode: ";
int code;
cin >> code; 
	
Caesar spy(keyword);
	
string returnCode;
	
if(code == 1) {
	returnCode = spy.decode(keyword);
	cout << "Encoded Message: " << returnCode <<endl;
}
else { 
	returnCode = spy.decode(keyword);	
	cout << "Decoded Message: " << returnCode << endl;

}
return 0;
	
}
