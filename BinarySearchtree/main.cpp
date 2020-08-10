#include "bst.h"
#include <iostream>
#include <string>

using namespace std;
typedef BinarySearchTree<int>::Node TNode;
//post-order traversal for setting heights of the nodes

void printTree(TNode* current) {
  //Pre-order - do something to the root/current node before children
  cout << current->getVal() << endl;
  if (current->getLeft() != nullptr) {
    printTree(current->getLeft());
  }
  //In-order - do something to the root/current node in betweeen 
  //  the left and right children.
  //cout << current->getVal() << endl;

  if (current->getRight() != nullptr) {
    printTree(current->getRight());
  }
  //Post-order - do something to the root/current node after children
  //cout << current->getVal() << endl;
}

int main() {
  BinarySearchTree<int> tree(1);

  printTree(tree.getRoot());

}
