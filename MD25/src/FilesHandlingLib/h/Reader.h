#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

class Reader {
public:
  bool readFile(const std::string& filePath);  // False - if there is an error

  const std::vector<std::string>& getText() const{ return text_; };
  
private:
  std::vector<std::string> text_;
};
