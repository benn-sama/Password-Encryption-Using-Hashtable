#include "password-encryption.hpp"

PasswordEncrypt::PasswordEncrypt() {
  // default constructor
}

std::string PasswordEncrypt::encryptPassword(std::string userName, std::string password) {
  std::string encryptedPassword = "";
  char passwordChar;

  for (int i = 0; i < password.length(); i++) {
    passwordChar = this->vCypher(i, password[i]);

    encryptedPassword += passwordChar;
  }
  
  return userName + " " + encryptedPassword;
}

char PasswordEncrypt::vCypher(int index, char passwordChar) {
  passwordChar = passwordChar % 97;

  // vCypher algorithm
  if (index % 5 == 0) {
    passwordChar = passwordChar + 9;
  }
  if (index % 5 == 1) {
    passwordChar = passwordChar + 14;
  }
  if (index % 5 == 2) {
    passwordChar = passwordChar + 13;
  }
  if (index % 5 == 3) {
    passwordChar = passwordChar + 4;
  }
  if (index % 5 == 4) {
    passwordChar = passwordChar + 18;
  }

  passwordChar = passwordChar % 27;
  passwordChar = passwordChar + 97;

  return passwordChar;
}