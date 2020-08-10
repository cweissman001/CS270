#include <cstddef>
#include <iostream>
using namespace std;

class Card {
 public:
  Card() : val('\0') {}
	//Initializer list --syntax is only for constructors 
  Card(char c) : val(c), next(NULL) {} /*must use for references so there is never a reference that refers to nothing before entering brackets of the constructor which is illegal in c++ */
  void set_next(Card* n) {
    next = n;
  }
  Card* get_next() { return next; }
  char get_val() { return val; }

 public:
  char val;
  Card* next;
};

//Starting with a particular card, print the entire chain of cards beginning with that one
void printChain(Card* start) {
	cout << start->get_val() << endl;
	// -> is a shortcut for defererening 
	cout << start->get_next()->get_val() << endl;
	
	
	//int index;
	//for(int i = 0; i< ??, i++)
	//print 1 char of chain
	//print 2nd char of chain
}

int main() {
  //Create a small card chain
	Card c24('A');
	Card c19(' ');
	Card c17('L');
	Card c11('i');
	Card c03('s');
	Card c08('t');
  c24.set_next(&c19); //&gets pointer of the object and not object since that is what func takes
	c19.set_next(&c17);
	c17.set_next(&c11);
	c11.set_next(&c03);
	c03.set_next(&c08);
	c08.set_next(NULL);
  //Equivalent to:c19.set_next(NULL);
  c24.next = &c19;
	
	printChain(&c24);
}
