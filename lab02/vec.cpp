#include "vec.h"

#include <algorithm>

/********** NEW STUFF ***************************************/

// FІXΜЕ: implement this method
Vec::~Vec() {
  // delete[] our array
  delete[] arr;
}

// FІXΜЕ: implement this method
Vec::Vec(const Vec& other) {
  // make a new array the same capacity as other's
  // set our current capacity/numItems to other's capacity/numItems
  // copy the contents of other's array into our own array
  arr = new int[other.capacity];
  capacity = other.capacity;
  numItems = other.numItems;
  for(int i = 0; i < numItems; i++){
    arr[i] = other.arr[i];
  }

}

// FІXΜЕ: implement this method
Vec& Vec::operator=(const Vec& other) noexcept {
  // delete our current array
  // make a new array the same capacity as other's
  // set our current capacity/numItems to other's capacity/numItems
  // copy the contents of other's array into our own array
  // return a reference to ourselves
  delete[] arr;
  arr = new int[other.capacity];
  capacity = other.capacity;
  numItems = other.numItems;
  for(int i = 0; i < numItems; i++){
    arr[i] = other.arr[i];
  }

  return *this ;static_cast<Vec*>(nullptr); //may need to replace the ";" in front of static_cast with "*"
}

/********* OLD STUFF ***************************************/
// FІXΜЕ: copy all your method implementations from the previous lab

Vec::Vec() {
  capacity = 1;
  arr = new int[capacity];
  numItems = 0;
}

// doubles the array capacity
void Vec::resize() {
  capacity = capacity * 2;
  int* arr2 = new int[capacity];
  for(int i = 0 ; i < numItems; i++){
    arr2[i] = arr[i];
  }
  delete[] arr;
  arr = arr2;
}

void Vec::push_back(int x) {
    if(numItems < capacity){
    arr[numItems] = x;
    }else{
       this->resize(); 
       arr[numItems] = x;
    }
    numItems = numItems + 1;
}

// return the number of items in the Vec
int Vec::size() const {
   return numItems;
}

// return the element at index i
// (it's a reference so that it can potentially be changed)
int& Vec::at(int i) {
  return arr[i];
}

void Vec::sort() {
  // sort the inner array using std::sort in <algorithm>
  std::sort(arr, arr + numItems);
}

