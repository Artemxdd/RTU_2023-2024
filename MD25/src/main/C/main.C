#include <iostream>
#include <string>
#include "../h/Reader.h"
#include "../h/Saver.h"
#include "../h/Line.h"
#include "../h/Decryptor.h"

int main() {
  Reader reader{};
  std::cout << reader.readFile("/home/artyom/Projects/RTU_2023-2024/MD25/encoded_file_1.txt") << "\n";
  std::vector<std::string> text{ reader.getText() };

  Decryptor decryptor{};
  for (size_t i{ 0 }; i < text.size(); i++) {
    decryptor.decrypt(text[i], "TopSecret!");
  }

  Saver saver{};
  // saver.saveFile("/home/artyom/Projects/RTU_2023-2024/MD25/encoded_file_1_new.txt", decryptor.getDecryptedTxt());
} 
