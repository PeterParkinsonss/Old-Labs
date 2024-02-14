#ifndef DEQUE_H
#define DEQUE_H

#include <list>

// a deque using a std::list

template <class T>
class Deque {
public:
  void push_front(const T& item);
  void push_back(const T& item);
  void pop_front();
  void pop_back();
  T& peek_front(); // gets the front element
  T& peek_back();  // gets the back element
  bool empty() const;
  int size() const;
private:
  std::list<T> l;
};

// FІXΜЕ: implement the member functions (implement them below)
// Remember that we can't use a .cpp file for templates

// here's everything except the body of the push_front function
template <class T>
void Deque<T>::push_front(const T& item) {
  // FІXΜЕ
  l.push_front(item);
}

// add in the rest
template <class T>
void Deque<T>::push_back(const T& item){
  l.push_back(item);
}

template <class T>
void Deque<T>::pop_front(){
  l.pop_front();
}

template <class T>
void Deque<T>::pop_back(){
  l.pop_back();
}

template <class T>
T& Deque<T>::peek_front(){ //T& may need to be rearranged
  return l.front();
}

template <class T>
T& Deque<T>::peek_back(){
  return l.back();
}

template <class T>
bool Deque<T>::empty() const{
  return l.empty();
}

template <class T>
int Deque<T>::size() const{
  return l.size();
}
#endif /* DEQUE_H */
