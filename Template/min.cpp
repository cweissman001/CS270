#include "min.hpp"

using namespace std;


/* int minimum(int x, int y) {
  int result = y;
  if (x < y) {
    result = x;
  }
  return result;
}
*/
int main() {
  int a = 10, b = -1;

 string s1 = "Hello", s2 = "Test";

  cout << minimum<int>(a, b) << endl;
  cout << minimum<string>(s1, s2) << endl;//<string> not needed since compliler will guess that you want min of two types
	//stops working if you put two different data types 
}
