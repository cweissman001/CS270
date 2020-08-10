#ifndef CS270_BINARY_SEARCH_TREE
#define CS270_BINARY_SEARCH_TREE

#include <cstddef>

template<class E>
class BinarySearchTree {
 public:
  class Node {
   public:
    Node(const E& v, Node* p) : val(v), parent(p), left(nullptr), right(nullptr) {}

    Node* getRight() { return right; }
    Node* getLeft() { return left; }
    Node* getParent() { return parent; }
    E getVal() { return val; }
    Node* insertRight(const E& newValue) { 
      right = new Node(newValue, this);
      return right;
    }
    Node* insertLeft(const E& newValue) {
      left = new Node(newValue, this);
      return left;
    }
    bool isLeaf() { return left == nullptr && right == nullptr; }
    bool isRoot() { return parent == nullptr; }

   private:
    E val;
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