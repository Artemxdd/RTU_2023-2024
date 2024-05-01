#include <string>

class Encryptor {
public:
  void encrypt(const std::string& decryptedTxt);
  const std::string& getEncryptedTxt() const;

  void clear() { encryptedTxt_.clear(); };

private:
  std::string encryptedTxt_;
};
