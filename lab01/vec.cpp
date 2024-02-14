#include "vec.h"

#include <algorithm>

#include <iostream> //only here for debugging

Vec::Vec() {
  // FІXΜЕ: implement this method
  // make arr a size 1 array to start with
  // so, capacity is 1 because the array can hold 1 thing
  // there's nothing in the Vec yet so the numItems is 0
  capacity = 1;
  arr = new int[capacity];
  numItems = 0;
}

// doubles the array capacity
void Vec::resize() {
  // FІXΜЕ: implement this method
  
  // Double the current capacity. This means we need to make a new
  // array on the heap and copy all the existing stuff into it.

  // remember to delete[] the old array and increase the capacity
  // memeber variable appropriately!
 // int oldCap = capacity; removing to check something
  capacity = capacity * 2;
  int* arr2 = new int[capacity];
  for(int i = 0 ; i < numItems; i++){
    arr2[i] = arr[i];
  }
  delete[] arr;
  arr = arr2;
}

void Vec::push_back(int x) {
  // FІXΜЕ: implement this method
  // If we have enough space, just add to the next available location.
  // If not, use the resize function to double the space and then add 
  // to the next available location.
 
//  std::cout << numItems << std::endl;// for debugging

  if(numItems < capacity){
    arr[numItems] = x;

    //    std::cout << arr[numItems] << std::endl;

   // numItems = numItems + 1; taking it out to check something
  }else{
    this->resize(); //might need to be some kind of arr resize
    arr[numItems] = x;

      //   std::cout << arr[numItems] << std::endl;


    //numItems = numItems + 1; taking out to check something
  }

    numItems = numItems + 1;

}

// return the number of items in the Vec
int Vec::size() const {
  // FІXΜЕ: implement this method

   //  std::cout << numItems << std::endl; for debugging

    return numItems;
}

// return the element at index i
// (it's a reference so that it can potentially be changed)
int& Vec::at(int i) {
  // FІXΜЕ: implement this method
  return arr[i];
}

void Vec::sort() {
  // sort the inner array using std::sort in <algorithm>
  std::sort(arr, arr + numItems);
}
