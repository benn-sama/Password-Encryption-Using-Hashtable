#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "random-password.hpp"
#include "password-encryption.hpp"
#include <fstream>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


class Database {
  private:
    std::vector<std::string> userNameAndPassword;

    // inputs data into file & exclusive to the class
    void dataInput(std::string fileName) const;
  public:
    // default constructor
    Database();

    // extract data
    void dataExtraction(std::string fileName);
};

#endif