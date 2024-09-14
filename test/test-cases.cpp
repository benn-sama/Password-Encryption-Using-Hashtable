#include "../database.hpp"
#include "../random-password.hpp"
#include "../password-encryption.hpp"
#include <iostream>
#include <cassert>
#include <string>
#include <exception>
#include <vector>

// test random password
void test_random_password() {
  RandomPassword passwordGenerator;
  std::vector<std::string> stringVector;
  std::string password = "";

  // tests password values 
  std::cout << "Testing password values in an array..." << std::endl;
  for (int i = 0; i < 5; ++i) {
    password = passwordGenerator.randomPassword();
    stringVector.push_back(password);

    if (stringVector.at(i).size() != 9) {
      throw std::runtime_error("Password " + std::to_string(i) + " is not of size!\n" 
                             + "Password: " + stringVector.at(i));
    }

    std::cout << "Password " << i + 1 << ": " << stringVector.at(i) << std::endl;
  }

  std::cout << std::endl << "Password values are sufficent!" << std::endl << std::endl;

  std::cout << "----------test_random_password passed----------" << std::endl << std::endl;

}

// test database extraction
void test_database_extraction() {
  Database database;

  database.dataExtraction();

  std::cout << "----------test_database_extraction passed----------" << std::endl << std::endl;
}


// test password encryption
void test_password_encryption() {
  PasswordEncrypt passwordEncrypt;

  std::string encryptedPassword = passwordEncrypt.encryptPassword("ben", "datum");

  if (encryptedPassword != "ben mogye") {
    std::cout << "Encrypted password: " << encryptedPassword << std::endl;
    throw std::runtime_error("Encrypted password: is incorrect");
  }

  std::cout << "----------test_password_encryption passed----------" << std::endl << std::endl;
}

// test database
void test_database() {
  Database dataBase;
  std::string illegalUser = "ben";
  std::string legalUser = "SMITH";
  std::string legalPassword = "";

  dataBase.dataMaster();

  if (dataBase.searchUser(illegalUser) != "") {
    throw std::runtime_error("Illegal user was found in the database!");
  }

  legalPassword = dataBase.searchUser(legalUser);
  if (dataBase.searchUser(legalUser) != legalPassword) {
    throw std::runtime_error("Legal user was not found in the database!");
  }

  // manual check entry in the database file because password changes every time the program is executed
  std::cout << "Legal user: " << legalUser << " Password: " << legalPassword << std::endl;


  std::cout << "----------test_database passed----------" << std::endl << std::endl;
}

int main() {
  test_random_password();
  test_database_extraction();
  test_password_encryption();
  test_database();

  return 1;
}