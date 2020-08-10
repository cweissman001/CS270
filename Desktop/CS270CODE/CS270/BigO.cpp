#include <cstdlib>
#include <cmath>

const int DATASIZE   = 1000000; // processing that many elements
const int WINDOWSIZE =      10;
const float PI = 3.14159265;

float data[DATASIZE]; //global arrays
float result[DATASIZE-WINDOWSIZE];


void initdata() { //don't need to worry about
  for (int i = 0; i < DATASIZE; i++) {
    data[i] = 15*cos(2*PI*(i%WINDOWSIZE)) + 75 - 30*(i/float(DATASIZE));
  }
}
//O(count) -- does work depending on count value
float average(int i, int count) {
	float result = 0.0;
	for (int offset = 0; offset < count; offset++) {
		result += data[i];
	}
	return result / float(count);
}

void smooth(int count) {
	//Result[i] = average(data[i], data[i+1], data[i+2])
	//O(DATASIZE - count) iterations, total O(count*(DATASIZE-count))
	float previous_average = average(0, count); //worst case O(N)
	result[0] = previous_average; //O(1) -- constant
	for (int i = 1; i < DATASIZE-count; i++) { //O(N) iterations
		//O(1) per loop iteration -- composite of elementary operations
		previous_average = ((previous_average*count) - data[i-1] + data[i+count -1])/count;
		result[i] = previous_average;
		//Asymptotic runtime of new smoothing algorithum: O(N) total because O(N) + O(N) + O(1) = O(N)
		
		//O(count) since you are calling average func
		//result[i] = average(i, count);
	}
}
//Asymptotic runtime of old smoothing algorithum: O(DATASIZE-count) = O(N) if WINDOWSIZE is a fixed constant
//But if WINDOWSIZE is user input then count is not defined so worst case scenerio WINDOWSIZE when  close to DATASIZE but not the same
//If count = 1 O(N) or count = N
//count = N/2 then O(n^2)

int main() {
  initdata(); // O(N)
  smooth(WINDOWSIZE); // O(N)
  return 0;
  return 0;
}

// now it is basically linear even thought it isnt quite if you try
