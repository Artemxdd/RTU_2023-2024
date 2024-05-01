#include "../h/Saver.h"

bool Saver::overrideFile(const std::vector<std::string>& text) const {
  std::ofstream fout{ filePath_, std::ofstream::out };
  if (!fout.is_open())
    return false;

  for (auto it{ text.begin() }; it != text.end(); ++it)
    appendText(fout, *it + '\n');

  fout.close();
  return true;
}

bool Saver::overrideFile(const std::string& text) const {
  std::ofstream fout{ filePath_, std::ofstream::out };
  if (!fout.is_open())
    return false;

  appendText(fout, text + '\n');

  fout.close();
  return true;
}

bool Saver::appendToFile(const std::vector<std::string>& text) const {
  std::ofstream fout{ filePath_, std::ofstream::app };
  if (!fout.is_open())
    return false;

  for (auto it{ text.begin() }; it != text.end(); ++it)
    appendText(fout, *it + '\n');

  fout.close();
  return true;
}

bool Saver::appendToFile(const char& chr) const {
  std::ofstream fout{ filePath_, std::ofstream::app };
  if (!fout.is_open())
    return false;

  appendChar(fout, chr);

  fout.close();
  return true;
}

bool Saver::appendChar(const std::ofstream& fout, const char& chr) const {
  fout.put(chr);
  return true;
}

bool Saver::appendText(const std::ofstream& fout, const std::string& text) const {
  fout.write(text.c_str(), text.size());
  //  fout << text;
  return true;
}
