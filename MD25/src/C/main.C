#include <iostream>
#include "../h/Reader.h"
#include "../h/Line.h"

int main() {
  Reader reader{};
  reader.readFile("/home/artyom/Projects/RTU_2023-2024/MD25/encoded_file_1.txt");

  Line line{};
  line.push_back('a');
  line.push_back('b');
  line.push_back('n');
  //line.pop_back();

  for(int i{ 0 }; i < line.size(); i++) {
    //    std::cout << line.front()[i];
  }
  std::cout << line.size() << "\n";
  std::cout << line.data() << "\n";
} 
