template<class Item>
Bag<Item>::Bag() {
  length = 0;
  head = nullptr;
}

template<class Item>
void Bag<Item>::add(Item bead) {
  //assume list is empty
  Node* toAdd = new Node(bead);
  toAdd->set_next(head); //setting the new object to the new head 
  head = toAdd;
  length++;
}

template<class Item>
void Bag<Item>::remove(Item bead) {
//piece of code to find the node in ll
//want to use Node* instead of int since an int doesn't mean anything
Node* previous = nullptr; //NULL is same as nullptr but has no type unlike nullptr
for(Node *current = head; current != nullptr; current = current->get_next()){
	if(current->get_val() == bead){
		if(previous != nullptr) {
			previous->set_next(current->get_next());
		} 	else{
		  	head = current->get_next();
		}
		delete current;
		current = nullptr; //good to do to prevent issues
		length --;
		return;
	}
	previous = current;
 }
}

template<class Item>
int Bag<Item>::count(Item color) const{
int count = 0;
for(Node* current = head; current != nullptr; current = current->get_next()){
	if(current->get_val() == color){
		count++;
	}
}
return count;
}


template<class Item>
void Bag<Item>::removeAll(Item bead) { 
	/*this is O(n^2) so quite slow even if short --fine if n is always small or don't care about preformance
	for(int toRemove = count(bead); toRemove > 0; toRemove--){
	remove(bead);
	} */
	//how could we remove in less than O(n^2)
	Node* previous = nullptr; //NULL is same as nullptr but has no type unlike nullptr
	for(Node *current = head; current != nullptr; current = current->get_next()){
		if(current->get_val() == bead){
			if(previous != nullptr) {
				previous->set_next(current->get_next());
			} else{
		  	head = current->get_next();
		}
		Node* nextNode = current->get_next();
		delete current;
		current = nextNode;
		length --;
	}
	previous = current;
 }
}










