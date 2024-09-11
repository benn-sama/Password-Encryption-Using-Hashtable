#include "../random-password.hpp"
#include <iostream>
#include <cassert>
#include <string>
#include <exception>
#include <vector>

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

  std::cout << "----------test_random_password passed----------" << std::endl;

}

int main() {
  test_random_password();
}