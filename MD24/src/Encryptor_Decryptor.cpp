#include "Encryptor_Decryptor.h"

Encryptor_Decryptor::Encryptor_Decryptor(const std::string& text, const bool& isTextEncrypted) {
  if (isTextEncrypted) 
    this->encryptedText_ = text;
  else 
    this->text_ = text;
}

std::string Encryptor_Decryptor::getText() const {
  return this->text_;
}

std::string Encryptor_Decryptor::getEncryptedText() const {
  return this->encryptedText_;
}

void Encryptor_Decryptor::encrypt() {

}

void Encryptor_Decryptor::decrypt() {

}
