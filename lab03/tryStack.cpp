#include <iostream>
#include <stack>
using namespace std;

int main() {
  // For the rest of this file, print out each value on a line by
  // itself. For example, if a comment says to print 5, you should
  // write:
  //   cout << 5 << endl;

  // Use the following page as a reference:
  // http://www.cplusplus.com/reference/stack/stack/

  // FІXΜЕ: create a stack that holds ints
    stack<int> numbers;
  // FІXΜЕ: push 5 onto the stack
    numbers.push(5);
  // FІXΜЕ: print the top of the stack
    cout << numbers.top() << endl;
  // FІXΜЕ: push 7 onto the stack
    numbers.push(7);
  // FІXΜЕ: print the top of the stack
    cout << numbers.top() << endl;  
  // FІXΜЕ: push 3 onto the stack
    numbers.push(3);
  // FІXΜЕ: print the top of the stack
    cout << numbers.top() << endl; 
  // FІXΜЕ: print the size of the stack
    cout << numbers.size() << endl;
  // FІXΜЕ: pop the stack
    numbers.pop();
  // FІXΜЕ: print the top of the stack
    cout << numbers.top() << endl;
  // FІXΜЕ: print the size of the stack
    cout << numbers.size() << endl;
  // FІXΜЕ: pop the stack
    numbers.pop();
  // FІXΜЕ: print the top of the stack
    cout << numbers.top() << endl;
  // FІXΜЕ: pop the stack
    numbers.pop();
  // FІXΜЕ: print the size of the stack
    cout << numbers.size() << endl;

  return 0;
}
