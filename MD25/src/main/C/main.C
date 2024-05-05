#include <iostream>
#include <string>
#include "../../FilesHandlingLib/files_handling.h"
#include "../h/Line.h"
#include "../h/Decryptor.h"
#include "../h/PasswordsGenerator.h"
#include <boost/program_options.hpp>

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

  Saver saver{ "/home/artyom/Projects/RTU_2023-2024/MD25/encoded_file_1_new.txt" };
  saver.overrideFile(decryptor.getDecryptedTxt());

  decryptor.clear();
  reader.clear();

  reader.readFile("/home/artyom/Projects/RTU_2023-2024/MD25/text_B.encoded");
  text = reader.getText();

  PasswordsGenerator generator{};
  generator.generate1Letter();
  std::set<std::string> passwords{ generator.getPasswords() };
  for (const std::string& password : passwords) {
    for (size_t i{ 0 }; i < text.size(); i++)
      decryptor.decrypt(text[i], password);
    if (decryptor.isText()) {
      std::cout << password << "\n" << decryptor.getDecryptedTxt() << "\n\n\n-------------------------------\n\n\n";
    }
  }
} 
