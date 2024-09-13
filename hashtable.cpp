#include "hashtable.hpp"

bool Hash::isEmpty() const {
  int sum = 0;

  for (int i = 0; i < groupAmount; ++i) {
    sum += hashTable[i].size();
  }

  if (sum == 0) {
    return false;
  }
  return true;
}

