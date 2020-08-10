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

		BinarySearchTree(const E& rootVal) : root(new Node(rootVal, NULL)) {}


		void add(const E& val){

		}	
	//Returns true if BST contains the value, false otherwise
	//recurisive helper
	private:
		bool conatains_helper(const E& val, Node* root){
			//Base cases - super easy
			//Base case 1 - empty tree/subtree
			if(root == nullptr){
				return false;
			}
			//Base case 2 - current node(root) is what we are looking for
			//never dereference a pointer when you are sure it is not null
			if(root->getVal() == val){
				return true;
			}
			
			//Recursive cases:
			if(root->getVal() < val ){
				return contains_helper(val, root->getRight());
			}
			else{
				return contains_helper(val, root->getLeft());
			}
			
		}
	
	public:
		bool contains(const E& val){
			return contains_helper(val, getRoot());
		}
	
		Node* getRoot() {
		return root;
	}

	private:
		Node* root;
	};

#endif //CS270_BINARY_TREE