#include <iostream>
#include "commonchars.h"
using namespace std;

int main() {
  /*Each Test case below is followed by a comment indicating what characters should be printed. The characters in the result string do not need to be in any particular order */

  cout << commonchars("tea", "a") << endl; //a 
  cout << commonchars("tea", "teach") << endl; //a, e, t
  cout << commonchars("tea", "tape") << endl; //a, e, t 
  cout << commonchars("tea", "zoo") << endl; //nothing
  cout << commonchars("tea", "teeth") << endl; //e, t
  cout << commonchars("teeth", "tea") << endl; //e, t 





return 0;
}