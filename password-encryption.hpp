#ifndef PASSWORD_ENCRYPTION_HPP
#define PASSWORD_ENCRYPTION_HPP

#include <string>

class PasswordEncrypt {
  public:
    // default constructor
    PasswordEncrypt();

    // encrypts and returns
    std::string encryptPassword(std::string userName, std::string password); 
};

#endif