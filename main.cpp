#include "database.hpp"
#include "password-encryption.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <thread> // Include the thread library
#include <chrono> // Include the chrono library

void loadEncryptedPasswords(std::vector<std::string>& encryptedPasswords) {
    std::ifstream inputFile("encrypteddata.txt");
    std::string line;
    std::string name;
    std::string password;

    for (int i = 0; i < 9; ++i) {
        getline(inputFile, line);
        std::istringstream iss(line);
        iss >> name;
        iss >> password;
        encryptedPasswords.push_back(password);
    }

    inputFile.close();
}

void loadPasswords(std::vector<std::string>& passwords) {
    std::ifstream inputFile("rawdata.txt");
    std::string line;
    std::string name;
    std::string password;

    for (int i = 0; i < 9; ++i) {
        getline(inputFile, line);
        std::istringstream iss(line);
        iss >> name;
        iss >> password;
        passwords.push_back(password);
    }

    inputFile.close();
}

int main() {
    Database dataBase;
    std::vector<std::string> encryptedPasswords;
    std::vector<std::string> passwords;
    PasswordEncrypt passwordEncrypt;

    dataBase.dataMaster();

    // Pause the program for 3 seconds to let program files load
    std::cout << "Waiting for 3 seconds for files to load..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Create threads to load encrypted passwords and passwords (threading for fun learned over the summer lol)
    std::thread encryptedThread(loadEncryptedPasswords, std::ref(encryptedPasswords));
    std::thread passwordsThread(loadPasswords, std::ref(passwords));

    // Wait for the threads to complete
    encryptedThread.join();
    passwordsThread.join();


    // proves that the encrypted passwords match the passwords in the table
    std::cout << "Legal:" << std::endl;
    std::cout << "Userid      Password(file)      Password(table/un)      Result" << std::endl;
    std::cout << "SMITH        " << encryptedPasswords[0] << "           " << dataBase.searchUser("SMITH") << "               " << (encryptedPasswords[0] == dataBase.searchUser("SMITH") ? "match" : "non match") << std::endl;
    std::cout << "WILLIAMS     " << encryptedPasswords[2] << "           " << dataBase.searchUser("WILLIAMS") << "               " << (encryptedPasswords[2] == dataBase.searchUser("WILLIAMS") ? "match" : "non match") << std::endl;
    std::cout << "BROWN        " << encryptedPasswords[4] << "           " << dataBase.searchUser("BROWN") << "               " << (encryptedPasswords[4] == dataBase.searchUser("BROWN") ? "match" : "non match") << std::endl;
    std::cout << "MILLER       " << encryptedPasswords[6] << "           " << dataBase.searchUser("MILLER") << "               " << (encryptedPasswords[6] == dataBase.searchUser("MILLER") ? "match" : "non match") << std::endl;
    std::cout << "MOORE        " << encryptedPasswords[8] << "           " << dataBase.searchUser("MOORE") << "               " << (encryptedPasswords[8] == dataBase.searchUser("MOORE") ? "match" : "non match") << std::endl;

    for (int i = 0; i < passwords.size(); ++i) {
      passwords[i].at(0) = 'z';
      passwords[i] = passwordEncrypt.encryptPassword(passwords[i]);
    }

    // changes passwords to prove illegal will not match
    std::cout << std::endl << "Illegal:" << std::endl;
    std::cout << "Userid          Password(file)      Password(table/un)      Result" << std::endl;
    std::cout << "SMITH           " << passwords[0] << "           " << dataBase.searchUser("SMITH") << "                " << (passwords[0] == dataBase.searchUser("SMITH") ? "match" : "non match") << std::endl;
    std::cout << "WILLIAMS        " << passwords[2] << "           " << dataBase.searchUser("WILLIAMS") << "                " << (passwords[2] == dataBase.searchUser("WILLIAMS") ? "match" : "non match") << std::endl;
    std::cout << "BROWN           " << passwords[4] << "           " << dataBase.searchUser("BROWN") << "                " << (passwords[4] == dataBase.searchUser("BROWN") ? "match" : "non match") << std::endl;
    std::cout << "MILLER          " << passwords[6] << "           " << dataBase.searchUser("MILLER") << "                " << (passwords[6] == dataBase.searchUser("MILLER") ? "match" : "non match") << std::endl;
    std::cout << "MOORE           " << passwords[8] << "           " << dataBase.searchUser("MOORE") << "                " << (passwords[8] == dataBase.searchUser("MOORE") ? "match" : "non match") << std::endl;
}