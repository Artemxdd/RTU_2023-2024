#include <cstdint>
#include <string>

class Encryptor_Decryptor {
public:
  Encryptor_Decryptor(const std::string& text, const bool& isTextEncrypted = false);

  std::string getText() const;
  std::string getEncryptedText() const;

private:
  std::string text_;
  std::string encryptedText_;

  void encrypt();
  void decrypt();
};