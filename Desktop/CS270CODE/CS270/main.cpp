#include <cstddef>
#include <iostream>
using namespace std;

class Card {
 public:
  Card(char c) : val(c) {}
  void set_next(Card* n) {
    next = n;
  }
  Card* get_next() { return next; }
  char get_val() { return val; }

 private:
  //label
  char val;
  Card* next;
};

//Starting with a particular card, print the entire chain of cards beginning with that one
void printChain(Card* start) {

}

int main() {
  //Create a small card chain
}
