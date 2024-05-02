#include <string>

class Decryptor {
public:
  void decrypt(const std::string& encryptedTxt, const std::string& password);
  bool isText() const;
  const std::string& getDecryptedTxt() const;

  void clear() { decryptedTxt_.clear(); };

private:
  std::string decryptedTxt_;
};
