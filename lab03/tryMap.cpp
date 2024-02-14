#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  // For the rest of this file, print out each value on a line by
  // itself. For example, if a comment says to print 5, you should
  // write:
  //   cout << 5 << endl;

  // Use the following page as a reference:
  // http://www.cplusplus.com/reference/map/map/map/

  // FІXΜЕ: create a map that goes from string keys to int values
    map<string, int> myMap;
  // FІXΜЕ: add an entry using the .emplace() function that maps
  //        "Lawton" to 8675309
    myMap.emplace("Lawton", 8675309);      
  // FІXΜЕ: add an entry using the .emplace() function that maps
  //        "Jacqui" to 2123487
    myMap.emplace("Jacqui", 2123487);      
  // FІXΜЕ: add an entry using the .emplace() function that maps
  //        "Surya" to 3097643
    myMap.emplace("Surya", 3097643);      
  // FІXΜЕ: add an entry using the .emplace() function that maps
  //        "Victoria" to 5397475
    myMap.emplace("Victoria", 5397475);        
  // FІXΜЕ: add an entry using the .emplace() function that maps
  //        "Antonio" to 3473987
    myMap.emplace("Antonio", 3473987);        
  // FІXΜЕ: lookup the entry for "Jacqui" using the .at() function and
  //        print the result
    cout << myMap.at("Jacqui") << endl;     
  // FІXΜЕ: lookup the entry for "Surya" using the .at() function and
  //        print the result
    cout << myMap.at("Surya") << endl;
  // FІXΜЕ: iterate through the map from beginning to end (look up how
  //        to use .begin() and .end()) and print out each element's
  //        key, a colon, a space, and then the element's value (i.e.,
  //        you want to print lines that look like "Tom: 5555555")
//   map<string, int> goThru;
    for(auto goThru = myMap.begin(); goThru != myMap.end(); goThru++){
      cout << goThru->first << ": " << goThru->second << endl;
    }
 

  return 0;
}
