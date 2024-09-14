#include "hashtable.hpp"

int Hash::hashFunction(int key) {
  return key % groupSize;
}

void Hash::insertItem(int key, std::string value) {
  int index = hashFunction(key);

  // inserts key value pair into the hash table
  hashTable[index].push_back(std::make_pair(key, value));
}

std::string Hash::searchItem(int key) {
  int index = hashFunction(key);

  // iterate through the list to find the key
  // auto is used instead of std::list<std::pair<int, std::string>>::iterator for readablity
  for (auto it = hashTable[index].begin(); it != hashTable[index].end(); it++) {
    if (it->first == key) {
      return it->second;
    }
  }
  return "Key not found";
}