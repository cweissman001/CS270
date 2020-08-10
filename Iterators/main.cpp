#include <iostream>
#include <forward_list>
#include <vector>
#include <algorithm>

using namespace std;
/*reason to have iterators is to enable templating at a larger rate--need a consistent way to iterate through a class in a consistent way --template functions that work on multiple different classes */
template<class C>
int sum(C& collection) {
  int result = 0;
  //compile error because templates
	//just need typename to prevent compile error 
  for (typename C::const_iterator it = collection.begin(); 
       it != collection.end(); ++it ) {
    result = result + *it; //need to dereference the iterator to get the current item
  }
  return result;
}
/* .end() is kinda like length--it is one past the last valid entry so it will still include last item of collection since it goes one past the last valid item */

/*the goal of an iterator is to let you access locations of items no matter the type in the example above */

// DONT USE <, > with iterators, just use =, !=

template<class C>
void print(C& collection) {
	for(typename C::const_iterator it = collection.begin(); it != collection.end(); ++it) {
		cout << *it << endl;
	}
	cout << endl;
}

int main() {
  forward_list<int> myList;
  myList.push_front(5); //adding items to front of list
  myList.push_front(3);
  myList.push_front(42);
  std::cout << "Sum1: " << sum(myList) << std::endl;
	
	print(myList);
	
	//Print the smallest item
	std::cout << (*std::min_element(myList.begin(), myList.end()))<< endl;

  vector<int> v;
  v.push_back(5); //add items to end of array
  v.push_back(3);
  v.push_back(42);
  std::cout << "Sum2: " << sum(v) << std::endl;

	print(v);
	
}
