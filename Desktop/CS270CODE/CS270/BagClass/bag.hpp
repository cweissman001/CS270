
#ifndef CS270_BAG_TEMPLATE
#define CS270_BAG_TEMPLATE
#include <string>


namespace ArrayBag {
//Bag of "beads" - where a bead is a string describing its color
template<class Item>
class Bag {
 public:
 	iterator(Bag& bag, int i = 0) : index(i), theBag(bag) {}
    Item operator*() { return theBag[index]; } //Get item at this location
    void operator++() { index++; } //Advance to the next item
    bool operator==(const iterator& other) const {  //Iterator comparisons
      return &theBag == &(other.theBag) && index == other.index; /*if two &(references) are == they must point to the same object */
    } /*in above you need to check index and check to see if both reference the same bag make sure that both iterators are in the same bag*/
    bool operator!=(const iterator& other) const { 
      return !((*this) == other); 
    } 
   private:
    int index;
    Bag& theBag;
  };
  // Constructor
  Bag(int max_size);
  //Actually implement these methods
  Bag(const Bag& other); //Copy constructor
  //Destructor
  ~Bag();
  //Assignment Operator
  //void operator=(const Bag<Item>& other);
  // Comparison to find beads in common
  //int numMatchingColors(const Bag& other);
  // Total bead count
  int get_length() const { return length; }
  // add(string) - add one bead of the given color to the bag
  void add(Item bead);
  // remove(string) - remove one copy of the given color from the bag
  void remove(Item bead);
  // removeAll(string) - remove all copies of the given color from the bag
  void removeAll(Item bead);
  // count(string) - count the number of copies of that color in the bag
  int count(Item color);
  // select() - randomly select a bead
  Item select();
  // "concatenation" of two bags, or "union"
  Item operator[](int index) const;

 //Iterator methods
  iterator begin();
  iterator end();

  
 private:
  Item *beads; //Pointer to an array of items
  int length;
  int max_capacity;
};


#include "bag_impl.hpp"
}
#endif
