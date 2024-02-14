#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <list>
#include <string>
#include <functional>

// The HashMap class maps keys of type K to values of type V.
// Precondition: The function:
//   unsigned int Hash(const K& k);
// exists for the type K. We will use that function to figure out
// which bucket to put the key k into.
template <class K, class V>
class HashMap {
public:
  HashMap(int tableSize);
  void insert(const K& key, const V& val);
  V* search(const K& key);

private:
  // our (key, value) pair type is HashTableItem
  // we hide this type from the user by putting it inside our class
  // and setting its visibility to private
  struct HashTableItem {
    K key;
    V val;
  };

  // our hash table is a vector of lists of HashTableItems
  std::vector<std::list<HashTableItem>> table;
};



// The non-templated Hash functions below really should be implemented
// outside of this .h file, but we're gonna break the rules for simplicity

unsigned int Hash(const int& i) {
  // FІXΜЕ: implement a hash function for ints here
  // How can you turn an int into an int? :)
  unsigned int x = i; 
  return x;
}

// FІXΜЕ: implement a hash function for chars here
// How can you turn a char into an int?
unsigned int Hash(const char& i){
 unsigned int x = int(i);
 return x;
}
// FІXΜЕ: implement a hash function for std::strings here
// How can you turn a string into an int?
// Hint: combine your char hashes
unsigned int Hash(const std::string& i){
  unsigned int sum = 0;
  for(int j = 0; j < i.length(); j++){
    sum = sum + int(i[j]);
  }
  return sum;
}
// FІXΜЕ: implement a hash function for doubles here
// How can you turn a double into an int?
// Hint: one method is to convert the double to a string
unsigned int Hash(const double& i){
  std::string s = std::to_string(i);
  unsigned int num = Hash(s);
  return num;
}


// FІXΜЕ: implement the constructor
  // Use the constructor's tableSize parameter to initialize the table
  // vector to have size tableSize.
  // Hint: you can call one of vector's constructors to do this
template <class K, class V>
HashMap<K, V>::HashMap(int tableSize) {
  table.resize(tableSize);
}

// FІXΜЕ: implement the insert method
  // use the Hash() function that we assume exists for Ks to figure
  // out where this key should go. Remember that the hash is not
  // itself an index into the table yet, so you'll need to shrink down
  // the result you get back.
template <class K, class V>
void HashMap<K, V>::insert(const K& key, const V& val){
  int index = Hash(key) % table.capacity(); 
  bool keyExists = false;
  int i = 0;
  while(keyExists = false){
    if(std::table.at(index).key == key){
      std::table.at(index).val = val;
      keyExists = true;
    }else{
      std::table.at(index).key = key;
      std::table.at(index).val = val;
      keyExists = true;
    }
  }
}


  // Check if the key already exists in the table. If it does, just update the
  // value there. If not, add a brand new HashTableItem to the list.


// FІXΜЕ: implement the search method
  // return a pointer to the value for a given key, or nullptr if the key doesn't exist
template <class K, class V>
V* HashMap<K, V>::search(const K& key){
  int index = Hash(key) % std::table.capacity();
  if(std::table.at(index).key == key){
    return *std::table.at(index).val;
  }else{
    return null;
  }
}



#endif /* HASHMAP_H */
