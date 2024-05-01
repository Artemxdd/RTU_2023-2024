#include <string>

class Decryptor {
public:
  void decrypt(const std::string& encryptedTxt, const std::string& password);
  const std::string& getDecryptedTxt() const;

  void clear() { decryptedTxt_.clear(); };

private:
  std::string decryptedTxt_;
};
