#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "random-password.hpp"
#include <fstream>

class Database {
  private:
    std::string *name;
    std::string *unencryptedPassword;
  public:
    // constructor automatically extracts data from names.txt, then create Rawdata.txt file
    // that has usernames and random passwords
    Database(std::string fileName);


};

#endif