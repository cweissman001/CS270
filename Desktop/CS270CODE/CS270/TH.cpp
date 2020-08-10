#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest.h>
//Write your code here: a SINGLE function contentsEQ
// Inputs: two indexable collections of equivalent type
// Output: a boolean indicating whether the contents of the two collections 
//         are equivalent (i.e. each item at each index compares as equal)
bool contentsEQ(std::string one, std::string other) {
  return true;
}
TEST(ContentsEQ, manytypes) {
  std::vector<char> L = {'5', '4', '3', '2', '1'};
  std::vector<char> L2 = {'5', '4', '3', '2', '1'};
  std::vector<char> L3 = {'5', '1', '3', '2', '1'};
  std::string s("54321");
  std::string s2("5432");
  std::string s3("54332");
  std::vector<int> Li = {5, 4, 3, 2, 1};
  std::vector<int> Li2 = Li;
  std::vector<int> Li3 = Li;
  Li3[2] = 42;
  //Test 1 - contentsEQ on strings
  ASSERT_TRUE(contentsEQ(s,s));
  ASSERT_FALSE(contentsEQ(s,s2));
  ASSERT_FALSE(contentsEQ(s2,s));
  ASSERT_FALSE(contentsEQ(s,s3));
  //Test 2 - contentsEQ on vectors of chars
  //ASSERT_TRUE(contentsEQ(L,L2));
  //Test 3 - contentsEQ on vectors of ints
  //ASSERT_TRUE(contentsEQ(Li,Li2));
  //ASSERT_FALSE(contentsEQ(Li,Li3));
  //Extra credit: +1 point if you can make your function 
  //also work to compare a string and a vector of chars
  //(Look to the pair class described in the textbook for inspiration)
  //ASSERT_TRUE(contentsEQ(s,L));
  //ASSERT_FALSE(contentsEQ(L,s2));
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}