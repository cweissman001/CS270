// First C++ program!
// Compling will start at the beginning and read down
#include <iostream> //C++ of version of asking for access to a library
using namespace std; //need to ask for any part of standard library and everything is accessed with std

int gcd(int u, int v) { //beginning of the declaration of a function 
    /* We will use Euclid's algorithm for computing GCD */
  int r;
  while (v != 0){ //not equal to zero
    r = u % v; //compute remainder
    u = v;
    v = r;
  }
  return u;
}

int main() { /*Where the execution begins because there must be a function called main 
for the program to function. Anything used inside main must be defined above it */
    int a, b;
    cout << "First Value: ";
    cin >> a;
    cout << "Second Value: ";
    cin >> b;
    cout << "gcd: " << gcd(a,b) << endl; // you can chain things together such that many things of different types will print together 
    return 0;
}