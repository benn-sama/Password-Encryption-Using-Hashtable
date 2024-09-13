#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <string>
#include <iostream>
#include <list>

class Hash {
  private: 
    static const int groupAmount = 20;
    std::list<std::pair<int, std::string>> hashTable[groupAmount];
  
  public:
    //checks if a group is empty
    bool isEmpty() const;

    // algorithm for the hash function
    int hashFunction(int key);

    // inserts item to the group
    void insertItem(int key, std::string value);

    // removes an item from the group
    void removeItem(int key);

    // searches for an item
    std::string searchItem(int key);
};

#endif