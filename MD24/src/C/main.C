#include <iostream>
#include "../h/Decryptor.h"
#include "../h/Encryptor.h"

int main() {
  std::cout << "Enter your string! String = ";
  std::string text; std::getline(std::cin, text);
  std::cout << "Do you want to decrypt or encrypt string? (d or e) ";
  char action; std::cin >> action;

  if (action == 'd') {
    Decryptor d{};
    d.decrypt(text);
    std::cout << d.getDecryptedTxt() << "\n";
  }
  else if (action == 'e') {
    Encryptor e{};
    e.encrypt(text);
    std::cout << e.getEncryptedTxt() << "\n";
  }

} 
