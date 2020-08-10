//#include <iostream>

template<class Item>
Bag<Item>::Bag(int max_size) {
  length = 0;
  max_capacity = max_size;
  beads = new Item[max_size];
}

template<class Item>
Bag<Item>::~Bag() {
  //std::cout << "Destructor called" << std::endl;
  delete[] beads;
}

template<class Item>
Bag<Item>::Bag(const Bag<Item>& other) {
  length = other.length;
  max_capacity = other.max_capacity;
  beads = new Item[other.max_capacity];
}

template<class Item>
void Bag<Item>::add(Item bead) {
  //Algorithm:
  beads[length] = bead;
  length++;
}

template<class Item>
Item Bag<Item>::operator[](int index) const{
	return beads[index];
}

template<class Item>
void Bag<Item>::remove(Item bead) {
  //Algorithm:
  //  until bead is found, check next location
  int index = 0;
  //Short-circuit, check validity before checking element
  //O(n) search loop
  while (index < length && beads[index] != bead) {
    index++;
  }
  if (index < length) {
    /* O(n) removal 
    while (index < length - 1) {
      beads[index] = beads[index+1];
      index++;
    }*/
    // O(1) removal
    beads[index] = beads[length-1];
    length--;
  }
}

template<class Item>
void Bag<Item>::removeAll(Item bead) {
  //Ideal software engineering - code reuse
  int toRemove = count(bead); //O(n)
  for (int x = 0; x < toRemove; x++) {
    remove(bead);
  }
}

template<class Item>
typename Bag<Item>::iterator Bag<Item>::begin() {
  return iterator(*this, 0);
}

template<class Item>
typename Bag<Item>::iterator Bag<Item>::end() {
  return iterator(*this, length);
}

