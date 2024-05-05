#include "../h/PasswordsGenerator.h"

void PasswordsGenerator::generate1Letter() {
  passwords_.clear();
  for (char chr{ 'a' }; chr <= 'z'; chr++)
    passwords_.insert(std::string{ chr });
}

