#include "database.hpp"

Database::Database() {
  // default constructor for instance
}

void Database::dataExtraction(std::string fileName) {
  std::ifstream inputFile(fileName);
  RandomPassword randomPassword;
  PasswordEncrypt passwordEncrypt;
  std::string line = "";
  std::string name = "";

  // checks if file was successfully opened
  while (!inputFile.is_open()) {
    std::cout << "File: \"" << fileName << "\" failed to open." << std::endl;
    std::cout << "File name: ";
    std::getline(std::cin, fileName);
    inputFile.open(fileName);
  }

  // extracts data from file and appends random password to the end of the name
  while (getline(inputFile, line)) {
    std::istringstream iss(line);

    iss >> name;
    name.append(" " + randomPassword.randomPassword());
    userNameAndPassword.push_back(name);
  }

  // calls method that creates a rawdata.txt file and inputs data into it
  this->dataInput("rawdata.txt");

  inputFile.close();

  // opens rawdata.txt file
  inputFile.open("rawdata.txt");
  
  // checks if file was successfully opened
  while (!inputFile.is_open()) {
    std::cout << "File: \"" << fileName << "\" failed to open." << std::endl;
    std::cout << "File name: ";
    std::getline(std::cin, fileName);
    inputFile.open(fileName);
  }

  // encrypts password
  while (getline(inputFile, line)) {
    std::istringstream iss(line);
    std::string name = "";
    std::string password = "";

    iss >> name;
    iss >> password;

    userNameAndPassword.push_back(passwordEncrypt.encryptPassword(name, password));
  }

  this->dataInput("encrypteddata.txt");
}

// inputs data into file & exclusive to the class
void Database::dataInput(std::string filename) {
  std::ofstream outputFile(filename);

  // writes into file all the usernames and passwords and erases them from the vector after 
  while (userNameAndPassword.size() != 0) {
    outputFile << userNameAndPassword.back() << std::endl;
    userNameAndPassword.pop_back();
  }

  std::cout << filename <<  " has been created." << std::endl;
}
