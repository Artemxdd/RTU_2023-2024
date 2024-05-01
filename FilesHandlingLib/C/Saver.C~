#include "../h/Saver.h"

bool Saver::saveFile(const std::string& filePath, const std::vector<std::string>& text) {
  std::ofstream fout{ filePath, std::ofstream::out };
  if (!fout.is_open())
    return false;

  for (auto it{ text.begin() }; it != text.end(); ++it) {
    fout << *it;
    fout << '\n';
  }

  fout.close();
  return true;
}
