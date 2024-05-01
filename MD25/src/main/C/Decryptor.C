#include "../h/Decryptor.h"

void Decryptor::decrypt(const std::string& encryptedTxt, const std::string& password) {
  size_t passwordIndex{ 0 };  
  for (size_t i{ 0 }; i < encryptedTxt.size(); i += 4) {
    if (passwordIndex == password.size())
      passwordIndex = 0;
   
    int encr1{ encryptedTxt[i] }, encr2{ encryptedTxt[i + 1] }, 
      encr3{ encryptedTxt[i + 2] }, encr4{ encryptedTxt[i + 3] };
    
    int decr1{ (encr1 & 0b1000000) << 1 | encr4 & 0b1000000 | (encr3 & 0b10000) << 1 | (encr2 & 0b1000) << 1 |
      (encr1 & 0b100) << 1 | encr4 & 0b100 | encr3 & 0b10 | encr2 & 0b1 };
    int decr2{ (encr2 & 0b1000000) << 1 | (encr1 & 0b10000) << 2 | (encr4 & 0b10000) << 1 | (encr3 & 0b1000) << 1 |
      (encr2 & 0b100) << 1 | (encr1 & 0b10) << 1 | encr4 & 0b10 | encr3 & 0b1 };
    int decr3{ (encr3 & 0b1000000) << 1 | (encr2 & 0b10000) << 2 | (encr1 & 0b1000) << 2 | (encr4 & 0b1000) << 1 |
      (encr3 & 0b100) << 1 | (encr2 & 0b10) << 1 | (encr1 & 0b1) << 1 | encr4 & 0b1 };

    decr1 ^= password[passwordIndex++];
    decr2 ^= password[passwordIndex++];
    decr3 ^= password[passwordIndex++];
    
    this->decryptedTxt_.push_back(decr1);
    this->decryptedTxt_.push_back(decr2);
    this->decryptedTxt_.push_back(decr3);
  }
}

const std::string& Decryptor::getDecryptedTxt() const {
  return this->decryptedTxt_;
}
