#include <iostream>
#include <string>
#include "../../FilesHandlingLib/files_handling.h"
#include "../h/Line.h"
#include "../h/Decryptor.h"

int main() {
  Reader reader{};
  if (!reader.readFile("/home/artyom/Projects/RTU_2023-2024/MD25/encoded_file_1.txt")) {
    std::cout << "Error with reading file!" << "\n";
    return 1;
  }
  std::vector<std::string> text{ reader.getText() };

  Decryptor decryptor{};
  for (size_t i{ 0 }; i < text.size(); i++)
    decryptor.decrypt(text[i], "TopSecret!");

  std::cout << "Is text? " << decryptor.isText() << "\n";

  Saver saver{ "/home/artyom/Projects/RTU_2023-2024/MD25/encoded_file_1_new.txt" };
  saver.overrideFile(decryptor.getDecryptedTxt());
} 
