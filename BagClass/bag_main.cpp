#include "bag.hpp"
#include "list_bag.hpp"
#include <iostream>

using namespace std;
using namespace ArrayBag;
//using namespace ListBag;

template<class Bag>
void printIndexableBag(const Bag& theBag) {
	for(typename Bag::iterator i = theBag.begin(); i != theBag.end(); i++){
	cout << *i << ", ";  /*printing the dereferenced iterator so it is a item due to operator overloading */
	}
 cout << endl;
}

int main() {
  Bag<string> mine(100);
  //Write additional code to operate on the bag declared, and declare new 
  //  bag objects as needed to test other methods.
  cout << mine.get_length() << std::endl;

  mine.add("R");
  mine.add("G");
  mine.add("B");
    printIndexableBag(mine);
  mine.remove("R");
	printindexableBag(mine);
//cout << mine.get_length() << std::endl;
	


}




