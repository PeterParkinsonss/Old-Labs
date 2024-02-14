#include "list.h"

List::List() {
  // FІXΜЕ: implement the constructor
  // make list initially empty
  first = nullptr;
  last = nullptr;
}

// FІXΜЕ: implement List's getFirst method to get the first element
const Node* List::getFirst(){
  return first->data;
}
// FІXΜЕ: implement List's getLast method to get the last element
const Node* List::getLast(){
  return last->data;
}

void List::push_front(Point2D data) {
  // FІXΜЕ: implement this method to add a new Node at the front of the list
  // Watch out for the special case when the list is initially empty!
  Node* frontNode = new Node;
  if(first == nullptr){
    
  }
}

void List::push_back(Point2D data) {
  // FІXΜЕ: implement this method to add a new Node at the end of the list
  // Watch out for the special case when the list is initially empty!
}

void List::pop_front() {
  // FІXΜЕ: implement this method to remove the Node at the front of the list
  // Watch out for the case where you remove the only Node in the list!
}

void List::pop_back() {
  // FІXΜЕ: implement this method to remove the Node at the back of the list
  // Watch out for the case where you remove the only Node in the list!
}

int List::size() {
  // FІXΜЕ: implement this method to return the number of Nodes in the list

  return -1;
}

List::~List() {
  // FІXΜЕ: implement the destructor--it should delete every Node in the list
}

List& List::operator=(const List& other) {
  // FІXΜЕ: implement the copy assignment operator
  return /* FIXME */ *static_cast<List*>(nullptr);
}

List::List(const List& other) {
  // FІXΜЕ: implement the copy constructor
}
