#include "binary_tree.h"
#include <iostream>
#include <string>

using namespace std;
typedef BinaryTree<string>::Node TNode; //so you dont have to write out
	//the long header -- also can use auto*

void printTree(TNode* current){
	//pre-order: do something to the root/current node before children
	cout<< current->getVal() << endl;
	if(! current->isLeaf()){
		printTree(current->getLeft()); //recursive call to func
		
	}
	//inorder:do something to the current in between left and right
		//cout<< current->getVal() << endl;
	if(! current->isLeaf()){
	printTree(current->getRight());
	
	}
	//post-order:do something to the root/current node after children
	//cout<< current->getVal() << endl; //putting this at the end makes it 
	//print backwards so the root prints last
}
//consistency of left being no and right yes is important
char usRes(){
	char answer;
	cin >> answer;
	return answer;
}

void play(TNode* root){ //O(n) which is related to height of tree
	//Base case: leaf - make a final guess
	if(root->isLeaf()){
		cout << "Were you thinking of a " << root->getVal() << "?" << endl;
	//Ask the user yes or no, and print appropriate response
		char answer = usRes();
	if(answer == 'Y'){
		cout << "congrats" << endl;
	}
	else{
		cout << "bummer" << endl;
		return;
	}
	}
		cout<< root->getVal() << endl;
		char response = usRes();
		if(response == 'Y'){
			play(root->getRight());
		}
		else{
			play(root->getLeft());
		}
		
	//Ask the user the current question
	//Get the user response(Y/N)
	//recursively call function on apprioate child given user ans
	
}


int main() {
  BinaryTree<string> tree("Is it alive?");
  

  TNode* root = tree.getRoot();
  auto* moving = root->insertRight("Does it move?");
  auto* polar_bear = moving->insertRight("Polar Bear");
  auto* grass = moving->insertLeft("Grass");

  BinaryTree<string>::Node* rock = root->insertLeft("Rock");
	
	//printTree(tree.getRoot());
	
	play(tree.getRoot());
	

}
