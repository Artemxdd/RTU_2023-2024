#include "../h/Reader.h"

bool Reader::readFile(const std::string& filePath) {
  std::ifstream fin{ filePath };
  if (!fin.is_open()) return false;

  std::string buffer;
  while (!fin.eof()) {
    std::getline(fin, buffer);
    text_.push_back(buffer);
  }
    
  fin.close();
  return true;
}
