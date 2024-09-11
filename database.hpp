#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "random-password.hpp"
#include <fstream>
#include <exception>
#include <iostream>
#include <string>
#include <vector>


class Database {
  private:
    std::vector<std::string> userNameAndPassword;
  public:
    // default constructor
    Database();

    // extract data
    void dataExtraction(std::string fileName);
};

#endif