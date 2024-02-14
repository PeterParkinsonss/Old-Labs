#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <vector>

// #include <iostream>

template <class T>
class PriorityQueue {
 public:
  void push(const T& x);
  T pop();
  const T& peek() const;
  bool isEmpty() const;
  int getLength() const;

 private:
  int leftChildIndex(int index) const;
  int rightChildIndex(int index) const;
  int parentIndex(int index) const;

  // the underlying "array" that holds the heap nodes
  std::vector<T> heapArray;
};

// FІXΜЕ: calculate the left child index, given a node's index
template <class T>
int PriorityQueue<T>::leftChildIndex(int index) const {
  return (index * 2 + 1);
}

// FІXΜЕ: calculate the right child index, given a node's index
template <class T>
int PriorityQueue<T>::rightChildIndex(int index) const {
  return (index * 2 + 2);
}

// FІXΜЕ: calculate the parent index, given a node's index
template <class T>
int PriorityQueue<T>::parentIndex(int index) const {
  if(index <= 0){
    return 0;
  }

  return ((index - 1)/2);
}

// FІXΜЕ: implement the push method to add a new node into the heap
template <class T>
void PriorityQueue<T>::push(const T& x){
  heapArray.push_back(x);
  int i = 0;
  while(heapArray.at(i) != x){
    i++;
  }
  T tempNode;
  while(i != 0 && heapArray.at(i) < heapArray.at(parentIndex(i))){
      tempNode = heapArray.at(parentIndex(i));
      heapArray.at(parentIndex(i)) = heapArray.at(i);
      heapArray.at(i) = tempNode;
      
      i = parentIndex(i);
 //     std::cout << "GOOOOOOOOOOOOOOOOOOG" << std::endl;
      if(i == 0){
        break;
      }
  }

//  std::cout << "--------------" << heapArray.at(0) << std::endl;

} 
// FІXΜЕ: implement the remove method
// Remove the min element, and also return a copy of it
template <class T>
T PriorityQueue<T>::pop() {
  // replace the root with the bottommost, rightmost node
  // we will return the node you just "popped" at the very end of this method
  int length = heapArray.size();
  int i = 0;

/*  for(int k = 0; k < 10; k++){
  std::cout << "zzzzzzzzzz" << heapArray.at(k) << std::endl;
  }
*/
  T rootNode = heapArray.at(0);
  T tempNode;
  heapArray.at(0) = heapArray.at(length - 1);
  heapArray.pop_back();
  // remove the bottommost, rightmost node
/*  while(heapArray.at(i) > leftChildIndex(i) || heapArray.at(i) > rightChildIndex(i)){
    if()
  } */
  T value = heapArray.at(i);

//  std::cout << "~~~~~~~~" << value << std::endl;

  while(leftChildIndex(i) < length){
    T minValue = value;
    int minIndex = -1;
    for(int j = 0; j < 2 && (j + leftChildIndex(i)) < length; j++){
      if(heapArray.at(j + leftChildIndex(i)) < minValue){
      
//  std::cout << leftChildIndex(i) << "_________________" << std::endl;

 //        minValue = heapArray.at(j + leftChildIndex(i));
       
  //      std::cout << "ITs HAPPENIGN AGAINNNN!" << j <<  std::endl;

        minIndex = j + leftChildIndex(i);
      }

    //  std::cout << "ONE MORE TIME!!" << std::endl; 
   
    }

    if(minValue == value){
      break;
    }else{
      tempNode = heapArray.at(i);
      heapArray.at(i) = heapArray.at(minIndex);
      heapArray.at(minIndex) = tempNode;

      i = minIndex;
    }
  }

  // bubble the new root down to where it needs to be

  // return a copy of the value you removed
  return rootNode;
}

// FІXΜЕ: implement the peek method to return a reference to the current min
template<class T>
const T& PriorityQueue<T>::peek() const{
 // T rootNode = heapArray.at(0);
return heapArray.at(0); 
}
// FІXΜЕ: implement the isEmpty method to return whether the heap is empty
template<class T>
bool PriorityQueue<T>::isEmpty() const{

return heapArray.empty(); //temp just checking something
}
// FІXΜЕ: implement the getLength method to get the size of the heap
template<class T>
int PriorityQueue<T>::getLength() const{
  int length = heapArray.size();
return length; 
}
// The following is not a method--you'll *use* the PriorityQueue class
// FІXΜЕ: sort the input vector (from smallest to biggest) using a
// PriorityQueue<T>
template <class T>
std::vector<T> heapSort(const std::vector<T>& v) {
  std::vector<T> result;

  return result;
}

#endif /* HEAP_H */
