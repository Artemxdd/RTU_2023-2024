#include <string>

class Decryptor {
public:
  void decrypt(const std::string& encryptedTxt);
  const std::string& getDecryptedTxt() const;

private:
  std::string decryptedTxt_;
};