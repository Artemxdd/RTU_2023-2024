#include <vector>
#include <string>
#include <fstream>

class Saver {
public:
  Saver(const std::string& filePath) { filePath_ = filePath; };
  void operator=(const std::string& filePath) { filePath_ = filePath; };
  
  bool overrideFile(const std::vector<std::string>& text) const;
  bool overrideFile(const std::string& text) const;

  bool appendToFile(const std::vector<std::string>& text) const;
  bool appendToFile(const std::string& text) const;
  bool appendToFile(const char& chr) const;
  
private:
  std::string filePath_;

  void appendChar(std::ofstream& fout, const char& chr) const;
  void appendText(std::ofstream& fout, const std::string& text) const;
};
