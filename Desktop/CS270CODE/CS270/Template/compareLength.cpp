#include <string>
#include <iostream>
#include <vector>

using namespace std;

//Write a function called "shorter" that will return the shorter of two collections
//Step 1: write a version that works for strings only
//Step 2: rewrite it as a templated function that works for strings or vectors
string shorter(string s1, string s2){
	string s3;
	if(s1.length() < s2.length()) {
		s3 = s1;
	}
	else{
		s3 = s2;
	}
	return s3;
}

template<class TBD>
TBD shorter(TBD x, TBD y){
	TBD result;
	if(x.size() < y.size()){
		result = x;
	}
	else{
		result = y;
	}
	return result;
}
	
int main() {
  //Starting example, nontemplated function for strings
  string s1 = "Correct";
  string s2 = "Incorrect";
  cout << shorter(s1, s2) << endl;

  vector<int> v1(4, 0); //A vector with four copies of the number 0
  vector<int> v2(3, 1); //A vector with three copies of the number 1
  //vector<int> v = v1;//Placeholder until the template function works
  vector<int> v = shorter(v1, v2);  //What we want to be able to do
  
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i != v.size()-1) {
      cout << ", ";
    }
  }
 
  cout << endl;

  return 0;
}
