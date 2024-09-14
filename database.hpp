#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "random-password.hpp"
#include "password-encryption.hpp"
#include "hashtable.hpp"
#include <fstream>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>


class Database {
  private:
    std::vector<std::string> userNameAndPassword;
    Hash hashTable;

    // inputs data into file & exclusive to the class
    void dataInput(std::string fileName);
  public:
    // default constructor
    Database();

    // handles data transeferring and encryption
    void dataMaster();

    // extract data
    void dataExtraction();

    // handles data encryption
    void dataEncryption();

    // extract usernames and passwords from file
    void userAndPassExtraction(std::string);

    // search for a key in the hash table
    std::string searchUser(std::string);
};

#endif