#include <iostream>
#include <queue>
using namespace std;

int main() {
  // For the rest of this file, print out each value on a line by
  // itself. For example, if a comment says to print 5, you should
  // write:
  //   cout << 5 << endl;

  // Use the following page as a reference:
  // http://www.cplusplus.com/reference/queue/priority_queue/

  //  Another name for a priority queue is a "heap"

  // FІXΜЕ: create a priority queue that holds ints
    priority_queue<int> numbers;
  // FІXΜЕ: push {1, -2, 3, -4, ..., 49, -50} onto the priority queue,
  //        in that order
    int altNum = 1;
    for(int i = 0; i < 50; i++){
      numbers.push(altNum);
      if(altNum > 0){
        altNum = (altNum + 1) * -1;
      }
      else if(altNum < 0){
        altNum = (altNum - 1) * -1;
      }
    }
  // FІXΜЕ: in a loop, do the following while the priority queue isn't
  //        empty:
  //          1. print the top of the priority queue
  //          2. pop the priority queue
   while(!numbers.empty()){
      cout << numbers.top() << endl;
      numbers.pop();
   } 


  return 0;
}