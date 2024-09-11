#include "../random-password.hpp"
#include <iostream>
#include <cassert>
#include <string>
#include <exception>

void test_random_password() {
  RandomPassword passwordGenerator;
  std::string password = passwordGenerator.randomPassword();

  if (password.size() != 9) {
    throw std::runtime_error("password size is not 9, password size is " + std::to_string(password.size()));
  }

  std::cout << "----------test_random_password passed----------" << std::endl;
}

int main() {
  test_random_password();
}