#include "bag.hpp"
#include <iostream>

using namespace std;

void afunction(Bag<int> abag) {
	abag.add(15);
	abag.add(12);
	abag.add(25);
	cout << abag.get_length() << endl;
	return;
}

int main() {
	Bag<int> mine(100);
  //Write additional code to operate on the bag declared, and declare new 
  //  bag objects as needed to test other methods.

	cout << mine.get_length() << endl;
	
	Bag<int> another(100);
	//another = mine;
	
	another.add(10);
	mine.add(15);

	afunction(mine);
	
	int len1 = mine.get_length(); //should be 4?
	int len2 = another.get_length(); //should be 1

	cout << endl << "Length of mine: " << len1 << endl;
	cout << "Length of another: " << len2 << endl;
	
	int con1 = mine.count(15); //should be 2
	int con2 = another.count(15); //should be 0

	cout << "Number of 15s in mine: " << con1 << endl;
	cout << "Number of 15s in another: " << con2 << endl;
	
	
return 0; //expect destrucor to be called here
}




