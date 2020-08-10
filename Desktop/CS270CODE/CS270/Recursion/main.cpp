#include <vector>
#include <iostream>
using namespace std;


/*int sum_of_entries(std::vector<int>& v, int up_to){
	int result = 0;
	for(vector<int>::iterator it = v.begin(); it != v.begin() + up_to; ++it){
		result += (*it);
	}
return result;
} */

int sum_of_entries(std::vector<int>& v, int up_to){
//Base case: version of the problem so simple, we
//don't even need recurison to solve it	
if (up_to ==0 ){ //simple base case
	return 0;
}
//Recursive case: implicit else case(not base case)
// What is a slightly smaller version of exactly the 
//same problem that would help find the solution?
int result = sum_of_entries(v, up_to-1) + v[up_to-1];
	//function is calling itself multiple times
	//everything inside the instance of the function
	//is just constant time so O(1) + the amount of 
	//times you are doing it(O(n)) so it is O(n)
return result;
}


int main() {
	std::vector<int> toSum = {10, 5, 4, 10, -3, 5};
	
	cout << sum_of_entries(toSum, toSum.size()-2) << endl;
	
	return 0;
}