#ifndef PASSWORD_ENCRYPTION_HPP
#define PASSWORD_ENCRYPTION_HPP

#include <string>
#include <iostream>

class PasswordEncrypt {
  private:
    // V Cypher algorithm
    char vCypher(int i, char passwordChar);
  public:
    // default constructor
    PasswordEncrypt();

    // encrypts and returns
    std::string encryptPassword(std::string userName, std::string password); 

    // encrypts and returns for testing purposes
    std::string encryptPassword(std::string password);

};

#endif