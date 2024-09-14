#include "hashtable.hpp"

// hash function
int Hash::hashFunction(const std::string &key) {
  int hash = 0;
  int index = 0;

  for (int i = 0; i < key.length(); i++) {
    hash += (int)key[i];
  }

  index = hash % groupSize;

  return index;
}

// inserts a key value pair into the hash table
void Hash::insertItem(const std::string& key, const std::string& value) {
  int index = hashFunction(key);
  std::pair<std::string, std::string> pair(key, value);

  hashTable[index].push_back(pair);
}

// searches for a key in the hash table
std::string Hash::searchItem(const std::string key) {
  int index = hashFunction(key);
  std::list<std::pair<std::string, std::string>>::iterator it;
  std::string value = "";

  for (it = hashTable[index].begin(); it != hashTable[index].end(); it++) {
    if (it->first == key) {
      value = it->second;
    }
  }

  return value;
}

