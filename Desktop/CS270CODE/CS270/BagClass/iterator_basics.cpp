#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main() {
  //vector<int> vec = {10, 15, 42, 38};
  list<int> list = {10, 15, 42, 38};

  /*
  for (int i = 0 ; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
  */

  //for (std::vector<int>::iterator it
  for (auto it = list.begin(); it != list.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}










