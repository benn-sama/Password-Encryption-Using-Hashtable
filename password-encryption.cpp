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

std::string PasswordEncrypt::encryptPassword(std::string password) {
  std::string encryptedPassword = "";
  char passwordChar;

  for (int i = 0; i < password.length(); i++) {
    passwordChar = this->vCypher(i, password[i]);

    encryptedPassword += passwordChar;
  }
  
  return encryptedPassword;
}

char PasswordEncrypt::vCypher(int index, char passwordChar) {
passwordChar = passwordChar - 'a'; // Normalize to 0-25 range

// vCypher algorithm
switch (index % 5) {
  case 0:
    passwordChar = (passwordChar + 9) % 26;
    break;
  case 1:
    passwordChar = (passwordChar + 14) % 26;
    break;
  case 2:
    passwordChar = (passwordChar + 13) % 26;
    break;
  case 3:
    passwordChar = (passwordChar + 4) % 26;
    break;
  case 4:
    passwordChar = (passwordChar + 18) % 26;
    break;
}

passwordChar = (passwordChar + 'a'); // Convert back to ASCII

return passwordChar;
}

