#include "../h/Encryptor.h"

void Encryptor::encrypt(const std::string& decryptedTxt) {
  for (size_t i{ 0 }; i < decryptedTxt.size(); i += 3) {
    int decr1{ decryptedTxt[i] }, decr2{ decryptedTxt[i + 1] }, decr3{ decryptedTxt[i + 2] };

    int encr1{ (decr1 & 0b10000000) >> 1 | 1 << 5 | (decr2 & 0b1000000) >> 2 | (decr3 & 0b100000) >> 2 | 
      (decr1 & 0b1000) >> 1 | (decr2 & 0b100) >> 1 | (decr3 & 0b10) >> 1 };
    int encr2{ (decr2 & 0b10000000) >> 1 | 1 << 5 | (decr3 & 0b1000000) >> 2 | (decr1 & 0b10000) >> 1 |
      (decr2 & 0b1000) >> 1 | (decr3 & 0b100) >> 1 | decr1 & 0b1 };
    int encr3{ (decr3 & 0b10000000) >> 1 | 1 << 5 | (decr1 & 0b100000) >> 1 | (decr2 & 0b10000) >> 1 |
      (decr3 & 0b1000) >> 1 | decr1 & 0b10 | decr2 & 0b1 };
    int encr4{ decr1 & 0b1000000 | 1 << 5 | (decr2 & 0b100000) >> 1 | (decr3 & 0b10000) >> 1 | decr1 & 0b100 |
      decr2 & 0b10 | decr3 & 0b1 };

    this->encryptedTxt_.push_back(encr1);
    this->encryptedTxt_.push_back(encr2);
    this->encryptedTxt_.push_back(encr3);
    this->encryptedTxt_.push_back(encr4);
  }
}

const std::string& Encryptor::getEncryptedTxt() const {
  return this->encryptedTxt_;
}
