#include "CorrectTxtInFile.h"

CorrectTxtInFile::CorrectTxtInFile(const str& filePath, const str& dictPath) {
	this->filePath = filePath;
	this->dictPath = dictPath;

	std::ifstream fin(this->filePath);
	if (!fin.is_open()) throw std::exception{ "Error with file" };

	str line;
	while (!fin.eof()) {
		std::getline(fin, line);
		if (!line.empty()) this->txt.push_back(line);
	}

	fin.close();
}

void CorrectTxtInFile::highligtWrongWordsAndOutToCons() const {
	WordSpellingChecker spellingChecker{ this->dictPath };
	mapstrbool words;
	str word;

	for (const str& line : this->txt) {

		if (!line.empty()) {
			word = "";
			for (const char& chr : line) {
				if (std::isalpha(chr)) word += std::tolower(chr);
				else if (!word.empty()) {
					if (spellingChecker.checkIfWordIsCorrect(word)) std::cout << word << chr;
					else std::cout << "\x1b[31m" << word << "\x1b[0m" << chr;
					word.clear();
				}
				else if (!std::isalpha(chr)) std::cout << chr;
			}
			if (!word.empty()) {
				if (spellingChecker.checkIfWordIsCorrect(word)) std::cout << word;
				else std::cout << "\x1b[31m" << word << "\x1b[0m";
				word.clear();
			}
		}

		std::cout << "\n";
	}
}

void CorrectTxtInFile::correctWrongWordsAndSaveToFile() const {
	str filePath{ this->filePath };
	size_t index{ filePath.size() - 1 };

	while (filePath[index] != '.') filePath.erase(filePath.begin() + index--);
	filePath.erase(filePath.begin() + index);

	std::ofstream fout(filePath + "_fixed.txt");
	if (!fout.is_open()) return;

	str word, correctWord, correctLine;
	WordSpellingChecker spellingChecker{ this->dictPath };

	for (const str& line : this->txt) {

		if (line.empty()) fout << "\n";
		else {
			word = "", correctWord = "";
			for (const char& chr : line) {
				if (std::isalpha(chr)) word += std::tolower(chr);
				else if (!word.empty()) {
					correctWord = spellingChecker.checkForWrongLetter(word);
					if (correctWord == word) correctWord = spellingChecker.checkForMissingLetter(word);
					if (correctWord == word) correctWord = spellingChecker.checkForExtraLetter(word);
					correctLine += correctWord + chr;
					word.clear();
				}
				else if (!std::isalpha(chr)) correctLine += chr;
			}
			if (!word.empty()) {
				str correctWord = spellingChecker.checkForWrongLetter(word);
				if (correctWord == word) correctWord = spellingChecker.checkForMissingLetter(word);
				if (correctWord == word) correctWord = spellingChecker.checkForExtraLetter(word);
				correctLine += correctWord;
				word.clear();
			}
		}

		fout << correctLine << "\n";
		correctLine.clear();
	}

	fout.close();
}