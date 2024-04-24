#include <string>

class Encryptor {
public:
  void encrypt(const std::string& decryptedTxt);
  const std::string& getEncryptedTxt() const;

private:
  std::string encryptedTxt_;
};