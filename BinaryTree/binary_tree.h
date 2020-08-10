#ifndef CS270_BINARY_TREE
#define CS270_BINARY_TREE

#include <cstddef>

template<class E>
class BinaryTree {
 public:
  class Node {
   public:
    Node(const E& v, Node* p) : val(v), parent(p), left(NULL), right(NULL) {} //constructor that takesd value and parent pointer

    Node* getRight() { return right; }
    Node* getLeft() { return left; }
    Node* getParent() { return parent; }
	E getVal() {return val; }
    Node* insertRight(const E& newValue){ 
		Node* inserted = new Node(newValue, this);
		right = inserted; //don't have to create inserted--can just set
		//right = to the new node
		return right;
	}
    Node* insertLeft(const E& newValue){ 
		left = new Node(newValue, this); //same as right function
		return left;
	}
    bool isLeaf(){ return left == nullptr && right == nullptr; }
    bool isRoot(){ return parent == nullptr; }
	
	  
   private:
    E val;
	int height;
    Node* left;
    Node* right;
    Node* parent;
  };

  BinaryTree(const E& rootVal) : root(new Node(rootVal, NULL)) {}

  Node* getRoot() {
    return root;
  }

 private:
  Node* root;
};

#endif //CS270_BINARY_TREE