#include "../h/Reader.h"

bool Reader::readFile(const char* filePath) {
  std::ifstream fin{ filePath };
  if (!fin.is_open()) return false;

  
  
  fin.close();
  return true;
}

bool Reader::readFile(const std::string& filePath) {
  std::ifstream fin{ filePath };
  if (!fin.is_open()) return false;



  fin.close();
  return true;
}
