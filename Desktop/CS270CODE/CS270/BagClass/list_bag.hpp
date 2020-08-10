#ifndef CS270_BAG_LIST
#define CS270_BAG_LIST
#include <string>

namespace ListBag {
//Bag of "beads" - where a bead is a string describing its color
template<class Item>
class Bag {
 private:
  class Node {
   public:
    Node(Item c) : val(c), next(NULL) {}
    //Assignment-based constructor
    /*
       Node(char c) {
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


 public:
  // Constructor
  Bag();
  // Comparison to find beads in common
  //int numMatchingColors(const Bag& other);
  // Total bead count
  int get_length() { return length; }
  // add(string) - add one bead of the given color to the bag
  void add(Item bead);
  // remove(string) - remove one copy of the given color from the bag
  void remove(Item bead);
  // removeAll(string) - remove all copies of the given color from the bag
  void removeAll(Item bead);
  // count(string) - count the number of copies of that color in the bag
  int count(Item color) const;
  // select() - randomly select a bead
  Item select();
  // "concatenation" of two bags, or "union"
  

 private:
  Node* head;
  int length;
  };

#include "list_bag_impl.hpp"
}
#endif
