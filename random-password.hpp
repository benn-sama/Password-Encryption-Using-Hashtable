#ifndef RANDOM_PASSWORD_HPP
#define RANDOM_PASSWORD_HPP

#include <random>
#include <string>

class RandomPassword {
  public:
    // default constructor
    RandomPassword() {}

    // returns random password using Mersenne Twister random number generator
    std::string randomPassword() {
      std::string newPassword = "";
      int addingIntoChar = 0;

      // random generator declaration
      std::random_device random;
      std::mt19937 gen(random());
      std::uniform_int_distribution<> dis(0, 93);

      // adds a char into newPassword 9 times
      for (int i = 0; i < 9; ++i) {
        char passwordIndex = '!';
        addingIntoChar = dis(gen);

        // checks if passwords are consecutive. 
        // if sequential, randomize password index until otherwise
        if (i != 0) {
          char previousChar = newPassword[i - 1];

          while (std::abs(addingIntoChar - (previousChar - '!')) == 1) {
            addingIntoChar = dis(gen);
          }
        }

        passwordIndex += addingIntoChar;
        newPassword.append(1, passwordIndex);
      }

      return newPassword;
    }
};

#endif