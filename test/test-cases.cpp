#include "../random-password.hpp"
#include <iostream>
#include <cassert>
#include <string>
#include <exception>

void test_random_password() {
  RandomPassword passwordGenerator;
  std::string password = passwordGenerator.randomPassword();

  assert(password.size() == 9);
  throw std::runtime_error("password size is not 9");

  std::cout << password << std::endl;
}

int main() {
  test_random_password();
}