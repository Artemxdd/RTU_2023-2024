#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

const uint8_t  MAX_LINE_SIZE{ 80 };

class Reader {
public:  
  bool readFile(const char* filePath);         // False - if there is an error
  bool readFile(const std::string& filePath);  // False - if there is an error

  const std::vector<std::string>& getText() const{ return this->text_; };
  
private:
  std::vector<std::string> text_;
};
