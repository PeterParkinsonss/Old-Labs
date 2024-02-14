#ifndef STACK_H
#define STACK_H

#include "Deque.h"

// we'll make a Stack class using our Deque class

template <class T>
class Stack {
public:
  void push(const T& item);
  // for pop, you will also return a copy of the value you pop
  T pop();
  // "peek" means "top"--I think it's a silly name, but we might as well 
  // be consistent with your textbook
  T& peek(); 
  bool empty() const;
  int size() const;
private:
  Deque<T> d;
};

// FІXΜЕ: implement the member functions
template <class T>
void Stack<T>::push(const T& item){
  d.push_front(item);
}

template <class T>
T Stack<T>::pop(){
  T temp = d.peek_front();
  d.pop_front();
  return temp;
}

template <class T>
T& Stack<T>::peek(){
  return d.peek_front();
}

template <class T>
bool Stack<T>::empty() const{
  return d.empty();
}

template <class T>
int Stack<T>::size() const{
  return d.size();
}

#endif /* STACK_H */
