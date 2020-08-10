#ifndef CS270_STRING
#define CS270_STRING
#include <iostream>

namespace CS270 {
/*
Constructing a string from an const array of characters (e.g. a string literal)
Constructing a string as a copy of another string
A method length() which must return the number of characters in the string
Indexed element access operator (square-brackets access, like mystring[0]), which must support both read and write capabilities
Support for using the plus operator (+) as a concatenation operation, which will create a new string that combines the characters from the two operands.
A destructor that will responsibly free any memory held by the object before the object itself is discarded.
*/

	class string {
  //Public methods of a string, including operators, construtors, 
  // destructor, and other methods
 	public:
  		string(const char other[]);
		string(const string& copy);
  		int length();
  		char& operator[](int index); //indexing
  		string operator+(const string& other); //combining
  		string& operator=(const string& other) ; //assigning
  		~string();

  	private:
  //Empty constructor is a useful way to declare local string objects 
  // you plan to initialize immediately in other class functions (like operator+), 
  // but making it private prevents other code from creating an uninitialized string.
  //By declaring assignment private, we prevent anyone from doing it, which 
  //  could cause problems if not implemented correctly (which is not part
  //  of this assignment.
  	string();
		
  	char *mystring;
  	int currLen;
};
	
}

#endif //define CS270_STRING