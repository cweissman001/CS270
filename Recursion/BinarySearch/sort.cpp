#include <vector>
#include <iostream>
#include "gtest/gtest.h"

//From 2 individually sorted vectors create a new sorted vector that contains all of the 
//elements from both orginal inputs
std::vector<int> merge(std::vector<int>& a, std::vector<int>& b) { //O(n) operation
	std::vector<int> result;
	int current_a = 0, current_b = 0;
	while(current_a != a.size() && current_b !=b.size()) {
		if(a[current_a] >= b[current_b]){
			result.push_back(b[current_b]);
			current_b++;
		} else{
			result.push_back(a[current_a]);
			current_a++;
	}
	}
	
	if(current_b != b.size()){
		for(int i = current_b; i <b.size(); i++){
			result.push_back(b[i]);
		}
	} else {
		for(int i = current_a; i <a.size(); i++){
			result.push_back(a[i]);
		}
	}
	return result;
}

std::vector<int> sort(std::vector<int>& in) {
	//In total this is a O(n*logn) algorithm which is
	//mush better than O(n^2). This is the fastest
	//sorting algorithm without cheating(extra assumptions)
	
	//Base case, zero or one element
	if(in.size() <= 1){
		return in;
	}
	//Recursive case: actually need to srt thing
	
	
	//Split input vector into two parts
	std::vector<int> thing_one;
	for(int i = 0; i<in.size()/2; i++){
		thing_one.push_back(in[i]);
	}
	std::vector<int> thing_two;
	for(int i = in.size()/2; i<in.size(); i++){
		thing_two.push_back(in[i]);
	}
	thing_one = sort(thing_one);
	thing_two = sort(thing_two);
	
	std::vector<int> result = merge(thing_one, thing_two);
	return result;
}

TEST(SAS, sort) {
  std::vector<int> v;

  v.push_back(5);
  v.push_back(1);
  v.push_back(2);
  v.push_back(9);
  v.push_back(20);
  v.push_back(42);
  v.push_back(-6);
  v.push_back(5);

  v.push_back(5);
  v.push_back(3);
  v.push_back(25);
  v.push_back(10);
  v.push_back(90);
  v.push_back(100);
  v.push_back(1000000);
  v.push_back(6);

  std::vector<int> sorted = sort(v);

  for (std::vector<int>::iterator it = sorted.begin(); it+1 != sorted.end(); ++it) {
    //std::cout << *it << ", ";
    EXPECT_TRUE(*it <= *(it+1));
  }
  std::cout << std::endl;
} 

TEST(SAS, merge) {
  std::vector<int> v1;
  std::vector<int> v2;
  v1.push_back(2);
  v1.push_back(2);
  v1.push_back(3);
  v1.push_back(8);
  v1.push_back(20);
  v1.push_back(42);
  v2.push_back(-6);
  v2.push_back(1);
  v2.push_back(3);
  v2.push_back(5);
  v2.push_back(25);
  v2.push_back(90);
  v2.push_back(100);
  v2.push_back(10000000);

  std::vector<int> merged = merge(v1, v2);
  for (std::vector<int>::iterator it = merged.begin(); it+1 != merged.end(); ++it) {
    //std::cout << *it << ", ";
    EXPECT_TRUE(*it <= *(it+1));
  }
  ASSERT_EQ(merged.size(), v1.size() +  v2.size());
  std::cout << std::endl;
}


/*
TEST(SAS, search) {
  std::vector<int> a;
  a.push_back(5);
  a.push_back(10);
  a.push_back(21);
  a.push_back(50);
  a.push_back(91);
  a.push_back(109);
  a.push_back(124);
  a.push_back(133);
  a.push_back(152);

  ASSERT_EQ(0, binary_search(a, 5));
  ASSERT_EQ(6, binary_search(a, 124));
  ASSERT_EQ(-1, binary_search(a, 42));

  //ASSERT_EQ(0, binary_searchR(a, 0, a.size(), 5));
  //ASSERT_EQ(6, binary_searchR(a, 0, a.size(), 124));
  //ASSERT_EQ(-1, binary_searchR(a, 0, a.size(), 42));
} */

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}











