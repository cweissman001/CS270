#include <vector>
#include <iostream>

using namespace std;

//return the index at which the item toFine can be found in teh array if it exists or -1 
//if it does not.
int find(const vector<int>& data, int toFind, int start = 0, int end = -1){
	//Deal with the intial call
	if(end == -1){
		end = data.size();
	}
//base case 1: window size is empty
	if(start == end) {
		return -1;
	}
//Base case 2: only one item left
	if((end - start) ==1){
		// (data[start] == toFind) ? start : -1; Fancy one liner to do the below
		if(data[start] == toFind){
			return start;
		} else{
			return -1;
		}
		
	}
	int middle = (start+end)/2;
	if(data[middle] == toFind){
		return middle;
	} else if(data[middle] < toFind){
		int result = find(data, toFind, (middle+1), end);
		return result;
	} else{ //data[middle] > toFind
		int result = find(data, toFind, start, middle); //just middle since end point is
		//plus one of what we actually check
		return result;
		
	}
}

int main() {
  vector<int> theData = {-5, 8, 10, 12, 15, 18, 31, 42, 83};

  int location = find(theData, 12); //expect index 3
  int location2 = find(theData, 35); //expect index -1
  cout <<location << endl;
  cout <<location2 << endl;
	
//Is this really faster?
// Calling the function once is O(1) but calling is for the worst case(the item is not 
//in the array) 
//First round N items
// Second round: N/2 items
// Third round N/4 items
//... N/(2^k)
// so n = 2^k and........ k = logn(you can ignore the base of two since it is constant)
//Asymptotic runtime is O(logn) or O(lgn) --specifcally means log base 2
//this is a significant improvement over O(n)----so much faster than the looping because
// it has no loop
	

}
  
