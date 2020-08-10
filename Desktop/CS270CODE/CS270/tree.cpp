#include <iostream>
#include <string>
#include <list>
using namespace std;

template<class T>
class Tree {
 public:
  class Node {
   public:
     Node(T v, Node* p) : val(v), parent(p) {}
     bool isRoot() { return parent == NULL; }
     bool isLeaf() { return children.empty(); }
     
     //usage: Node& city = state.addChild("Walla Walla");
     Node& addChild(T item) {
       Node newNode(item, this);
       children.push_back(newNode);
       return children.back();
     }

     int height; //maximum distance from this node down to a leaf
     int depth; //distance from this node down to the root
     T val;
     list<Node> children;
     Node* parent;
  };

  Node& getRoot() { return *root; }
	
private: //user cannot access
  void print(Node* root) {
	  //print the current node
	  cout << root->val << endl;
	  //auto is c++ way of saying I dont know what type but figure it out for me
	  for(auto it = root->children.begin(); it != root->children.end(); ++it){
		  Node* nextChild = &(*it); //need the pointer to the node 
		  print(nextChild);
	  }
  }
public:
  Tree(T r) : root(new Node(r, NULL)) {}

//helper interface --- a function that is not recursive to let the public use that will call the recursive function
  void printAllNodes() {
    print(root);
  }

 private:
  Node* root;

};


int main() {
  //Address tree structure
  //Format: state/province, city, street, name
  Tree<string> addresses("Washington");

  // Create a shortcut for a name
  typedef Tree<string>::Node TNode; //node that belongs to a tree is TNode 
	//so this is a shortcut for a node that belongs to a tree of string

  Tree<string>::Node& state = addresses.getRoot(); //same as below jsut TNode is quicker
  TNode& city = state.addChild("Walla Walla");

  city.addChild("Fairmont");
  city.addChild("Issacs");
  city.addChild("Boyer");
  city.addChild("Rose");
  TNode& street = city.addChild("Boyer");
  street.addChild("280");

  addresses.printAllNodes();

}
