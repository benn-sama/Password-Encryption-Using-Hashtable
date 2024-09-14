#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <string>
#include <iostream>
#include <list>

// simple hash function to map values to key
class Hash {
  private: 
    static const int groupSize = 15;
    std::list<std::pair<int, std::string>> hashTable[groupSize];
    
    // Hash function to map values to key
    int hashFunction(int key);
  public:
    // inserts a key-value pair into the hash table
    void insertItem(int key, std::string value);

    // searches for a key in the hash table
    std::string searchItem(int key);
};

#endif