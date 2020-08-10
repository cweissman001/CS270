#include <string>

const int MAX_SIZE = 10000;

//Bag of "beads" - where a bead is a string descrbing color 
template<class Item>
class Bag{
 public:
	//Constructor
	Bag();
	// Comparison to find beads in common
	int numMatchingColors(const Bag& other);
	//Total Bead count
	int get_length() {return length; }
	
	//add one bead of given color to bag
	void add(Item bead);
	
	//remove all copies of given color from bag
	void removeAll(Item bead);
	
	//remove one copy of given color from bag
	void remove(Item bead);
	
	//count the numer of copies of given color
	int count(Item color);
	
	//randomly select a bead
	std::string select();
	
	//"concatenation" of 2 bags, or "union"
	
 private:
	Item beads[MAX_SIZE];
	int length;

};

#include "bag_impl.hpp"
#endif
	
	
	