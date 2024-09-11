#include "database.hpp"

Database::Database() {
  
}

void Database::dataExtraction(std::string fileName) {
  std::ifstream inputFile(fileName);
  std::string line = "";
  std::string name = "";


  while (!inputFile.is_open()) {
    std::cout << "File: \"" << fileName << "\" failed to open." << std::endl;
    std::cout << "File name: ";
    std::getline(std::cin, fileName);
    inputFile.open(fileName);
  }

  std::cout << "File: \"" << fileName << "\" successfully opened..." << std::endl;
  while (getline(inputFile, line)) {
  
  }

}