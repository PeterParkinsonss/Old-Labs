#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
  // For the rest of this file, print out each value on a line by
  // itself. For example, if a comment says to print 5, you should
  // write:
  //   cout << 5 << endl;

  // Use the following page as a reference:
  // http://www.cplusplus.com/reference/list/list/

  // FІXΜЕ: create a list that holds strings
    list<string> words{};
  // FІXΜЕ: push "cat" onto the end of the list
    words.push_back("cat");
  // FІXΜЕ: push "dog" onto the front of the list
    words.push_front("dog");
  // FІXΜЕ: push "bird" onto the end of the list
    words.push_back("bird");
  // FІXΜЕ: push "horse" onto the front of the list
    words.push_front("horse");
  // FІXΜЕ: print the size of the list
    cout << words.size() << endl;
  // FІXΜЕ: iterate through the list from beginning to end (look up 
  //        how to use .begin() and .end()) and print out each
  //        element's value
    for(auto i = words.begin(); i != words.end(); i++){
      cout << *i << endl;
    }
  

  return 0;
}
