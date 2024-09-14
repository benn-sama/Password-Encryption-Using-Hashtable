#include "database.hpp"

Database::Database() {
  // default constructor for instance
}

// handles data transeferring and encryption
void Database::dataMaster() {
  std::istringstream iss;
  std::string user = "";
  std:: string password = "";

  this->dataExtraction();
  this->dataEncryption();
  this->userAndPassExtraction("encrypteddata.txt");

  // inserts data into hash table
  for (int i = 0; i < userNameAndPassword.size(); i++) {
    iss.str(userNameAndPassword[i]);
    iss >> user;
    iss >> password;
    
    hashTable.insertItem(user, password);
    iss.clear();
  }
}

void Database::dataExtraction() {
  std::ifstream inputFile("names.txt");
  RandomPassword randomPassword;
  PasswordEncrypt passwordEncrypt;
  std::string line = "";
  std::string name = "";

  // checks if file was successfully opened
  while (!inputFile.is_open()) {
    std::cout << "File: \"names.txt\" failed to open." << std::endl;
    exit(1);
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
}

void Database::dataEncryption() {
  std::ifstream inputFile("rawdata.txt");
  RandomPassword randomPassword;
  PasswordEncrypt passwordEncrypt;
  std::string line = "";
  std::string name = "";

  // checks if file was successfully opened
    if (!inputFile.is_open()) {
    std::cout << "File: \"rawdata.txt\" failed to open." << std::endl;
    exit(1);
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

  // inputs encrypted data into encrypteddata.txt file
  this->dataInput("encrypteddata.txt");

  inputFile.close();

}

// extracts usernames and passwords from file
void Database::userAndPassExtraction(std::string filename) {
  std::ifstream inputFile("encrypteddata.txt");
  PasswordEncrypt passwordEncrypt;
  std::string line = "";
  std::string name = "";

  // checks if file was successfully opened
  while (!inputFile.is_open()) {
    std::cout << "File: \"encrypteddata.txt\" failed to open." << std::endl;
    exit(1);
  }

  // extracts data from file and appends random password to the end of the name
  while (getline(inputFile, line)) {
    std::istringstream iss(line);
    std::string name = "";
    std::string password = "";
    std::string combine = "";

    iss >> name;
    iss >> password;
    combine = name + " " + password;

    userNameAndPassword.push_back(combine);
  }

  inputFile.close();
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

