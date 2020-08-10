#include "poem.h"
#include "haiku.h"

#include <string>
#include <iostream>
#include <list>

using namespace std;

int main() {
  vector<string> apoem; 
  apoem.push_back("References, Pointers");
  apoem.push_back("Who invented this language");
  apoem.push_back("Genius or crazy");


  std::vector<PoemBase*> collection;
  collection.push_back(new Poem(apoem, "Someone", "C++"));
  collection.push_back(new Haiku(apoem[0], apoem[1], apoem[2], "Someone", "C++"));

  for (int i = 0; i < collection.size(); i++) {
    collection[i]->print();
  }

  /*
  Haiku* h = new Haiku(apoem[0], apoem[1], apoem[2], "Someone", "C++");
  h->print();
  //collection.push_back(h);

  PoemBase* pb = new Haiku(apoem[0], apoem[1], apoem[2], "Someone", "C++");
  PoemBase* pb2 = new Poem(apoem, "Someone", "C++");

  pb->print();
  pb2->print();
  */

}






