#include "WordsFromFile.h"

WordsFromFile::WordsFromFile(const str& filePath) {
	this->filePath = filePath;

    std::ifstream fin(this->filePath);
    if (!fin.is_open()) return;

    char chr;
    str word{ "" };
    while (fin.get(chr)) {
        if (chr < 0) continue;
        if (std::isalpha(chr)) word += std::tolower(chr);
        else if (!word.empty()) {
            this->words[word] += 1;
            word.clear();
        }
    }

}

mapstrint WordsFromFile::getWords() {
    return this->words;
}
