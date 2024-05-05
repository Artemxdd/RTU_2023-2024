#include <string>
#include <set>
#include <iostream>

const short LONGEST_PASSWORD_SIZE{ 10 };

class PasswordsGenerator {
public:
  void generate1Letter();
  
  const std::set<std::string>& getPasswords() const { return passwords_; };
  void clear() { passwords_.clear(); };
private:
  std::set<std::string> passwords_;
};
