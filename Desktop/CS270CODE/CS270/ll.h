#include <cstddef>

namespace CS270 {
template<class T>
class forward_list {
 private:
  class Node {
   public:
    T val;
    Node* next;
    Node(const T& v) : val(v), next(NULL) {}
  };

  Node* head;
  //Prevent copy and assignment by declaring private functions (implementations not needed)
  forward_list(forward_list& other);
  forward_list& operator=(forward_list& other);

 public:
  forward_list() : head(NULL) { }

  //Insert an item at the beginning of the list
  void push_front(const T& v) {
    Node *newnode = new Node(v);
    newnode->next = head;
    head = newnode;
  }

  //Returns the value at the head of the list
  T& front() { return head->val; }

  //Remove the first item from the list
  void pop_front() {
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
  }

  //Is the list empty?
  bool empty() { return head == NULL; }

  //Remove items matching val from the list
  void remove(const T& val) {
    Node* previous = NULL;
    Node* current = head;
    while (current != NULL) {
      if (current->val == val) {
        previous->next = current->next;
      } else {
        previous = current;
      }
      current = current->next;
    }
  }

};

}