#include <iostream>
using namespace std;

//void function(int *a)

int main() {
	int a = 42;
	int &b = a;
	/* int *p = a; // this causes an error since a pointer is a location and cannot be assigned to a value -- cannot convert an object to a pointer*/
	int *p = &a; /*the & operator here means get the address of the variable is it next to */

	// function(a); --Error because it is not a pointer 
	// function(&a) -- Fine
	// function(p); -- Fine, copies the pointer
	
	cout << a << endl; //prints 42
	cout << b << endl; //prints 42
	cout << p << endl; //Legal but prints the pointer and not value it points to
	cout << *p << endl; //prints the value a pointer points to
	
	
	/* b = &a; //b is a reference so an integer object and that cannot be overwritten with a pointer since that is a location */
	int c = 3141;
	b = c; //assigns b to 3141 which also changes int a since b is a &
	cout << a << endl; 
	
	a = 42;
	//p = c; can't assign a pointer to an integer
	p = &c; // &c is an arrow pointing to c -- so now p points to c
	*p = 15; //c is assigned to 15 because p currently points to c
	cout << a << endl; // prints 42
	cout << c << endl; // prints 15
	cout << *p << endl; //prints 15
	
	int *another_p = &a;
	p = another_p; /* new pointer also points to a  so both p and another_p point to a */
	*p = 3141;
	
	cout << a << endl; // prints 3141
	cout << c << endl; // prints 15
	cout << *p << endl; //prints 3141
	cout << *another_p << endl; //prints 3141
}