//implementation file
#include "mystring.h"
#include "iostream"

namespace CS270 {

string::string(const char other[]) { //constructor for a const array of chars-- a string literal
  //constructor that turns an array into the string object 

		int n = 0; //int for length
		while(other[n] != '\0') { //looping to find length and stopping before null/ending char
			n++;
		}
		currLen = n; //assignment of length variable
		mystring = new char[currLen]; //creation of array
		
  		for(int i = 0; i<currLen; i++){ //assinging the values of the input to the string object
			mystring[i] = other[i];
  }
}
	
string::string(const string& copy){ //constructor for taking in another object and copying it
	currLen = copy.currLen;
	mystring = new char[currLen];
	for(int i = 0; i<currLen; i++){ //assinging the values of the copy to the new string object
			this->mystring[i] = copy.mystring[i];
}
}

 int string::length(){
  //returns the length of the string, the numbers of characters in object 
  return currLen; 
}

 char& string::operator[](int index) {
//makes it so that the user can index the string using []
	 char nu = '\0'; //creating a char variable that is set to null
	 if(index > currLen){
		 return nu; //returns null if the index is outside of bounds instead of the program not running properly
		 //making sure user cannot misuse the function
	 } else{
		 return mystring[index]; //returning when index is found since we know it must be in bounds of the array
	 }

}  
	
string string::operator+(const string& first) {
//operator overlaoding to concantenate two string together
	int newlen = ((this->currLen + first.currLen)); //creating an int to temporarily store the length of the two string combined
	char *temp = new char[newlen+1];//creation of a new string object with the temporary length interger
	for(int i = 0; i< this->currLen; i++){ //looping through to add all the values of the current/this object to the array
		temp[i] = this->mystring[i]; //assingment with deferencing
	}
	int k = 0; //variable to track the index of first
	for(int j = this->currLen; j<newlen; j++){ //lopping though to add all of the values of the other/first object to the second half of the array
		temp[j] = first.mystring[k]; //assignment
		k++; //incrementing the index of first
	}
	temp[newlen] = '\0';
	string result(temp);
	result.currLen = newlen;
	delete temp;
return result; //returning the result which is now the two strings together
} 

string& string::operator=(const string& other){
//makes it so you can make one string equal another with out making a reference but rather copying it
	delete mystring; //delete to array of the object to prevent loss of memory space
	currLen = other.currLen; //get the length of the object being copied and set it to new current length
	mystring = new char[currLen]; //create a new object
		for(int i = 0; i< currLen; i++){ //loop through to assign new object to the same values of the inputted object
			this->mystring[i] = other.mystring[i];
		}
return *this;	//returning new current object
} 


string::~string(){
  //deletes string when memory is being dynamically allocated
  delete [ ] mystring;
}
}

