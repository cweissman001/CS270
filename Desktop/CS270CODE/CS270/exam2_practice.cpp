#include <cstddef>
#include <iostream>
using namespace std;

template<class Item>
class Node {
 public:
  Node() : val('\0') {}
  //Initializer list
  Node(Item c) : val(c), next(NULL) {}
  //Assignment-based constructor
  /*
  Card(char c) {
    val = c;
    next = NULL;
  }*/
  void set_next(Node* n) {
    next = n;
  }
  Node* get_next() { return next; }
  Item get_val() { return val; }

 public:
  Item val;
  Node* next;
};

//Starting with a particular card, print the entire chain of cards beginning with that one
template<class Item> //need to define again since this is not a method of the class
void printChain(Node<Item>* start) { //only works for nodes--object of this class type but any version
	NODE* current = start; //here NODE* is refereing to the template peramiter could be named anything
	while(current != nullptr) //checking if not= to null{
		cout << current ->get_val() << endl;
		current = current->get_next();
}
}

int main() {
  //Create a small card chain
  Node<char> c24('A'); //want to tell compiler the type
  Node<char> c19(' ');
  Node<char> c17('L');
  Node<char> c11('i');
  Node<char> c03('s');
  Node<char> c08('t');

  Node<string> test(" A string");
	
  //Equivalent to: c24.next = &c19;
  c24.set_next(&c19);
  c19.set_next(&c17);
  c17.set_next(&c11);
  c11.set_next(&c03);
  c03.set_next(&c08);
  c08.set_next(NULL);  //Optional if the Node constructor already initializes next to NULL
  printChain(&c24);
}
