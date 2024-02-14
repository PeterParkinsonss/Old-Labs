#include <iostream>
#include <queue>
using namespace std;

int main() {
  // For the rest of this file, print out each value on a line by
  // itself. For example, if a comment says to print 5, you should
  // write:
  //   cout << 5 << endl;

  // Use the following page as a reference:
  // http://www.cplusplus.com/reference/queue/queue/

  // FІXΜЕ: create a queue that holds doubles
    queue<double> mcDouble;
  // FІXΜЕ: push 2.4 onto the queue
    mcDouble.push(2.4);
  // FІXΜЕ: print the front of the queue
    cout << mcDouble.front() << endl;
  // FІXΜЕ: push 7.5 onto the queue
    mcDouble.push(7.5);
  // FІXΜЕ: print the front of the queue
    cout << mcDouble.front() << endl;
  // FІXΜЕ: push 3.14 onto the queue
    mcDouble.push(3.14);
  // FІXΜЕ: print the front of the queue
    cout << mcDouble.front() << endl;
  // FІXΜЕ: print the size of the queue
    cout << mcDouble.size() << endl;
  // FІXΜЕ: pop the queue
    mcDouble.pop();
  // FІXΜЕ: print the front of the queue
    cout << mcDouble.front() << endl;
  // FІXΜЕ: print the size of the queue
    cout << mcDouble.size() << endl;
  // FІXΜЕ: pop the queue
    mcDouble.pop();
  // FІXΜЕ: print the front of the queue
    cout << mcDouble.front() << endl;
  // FІXΜЕ: pop the queue
    mcDouble.pop();
  // FІXΜЕ: print the size of the queue
    cout << mcDouble.size() << endl;


  return 0;
}
