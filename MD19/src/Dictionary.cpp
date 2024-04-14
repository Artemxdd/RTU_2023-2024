#include "Dictionary.h"

Dictionary::Dictionary(const str& dictPath) {
	this->dictPath = dictPath;

	std::ifstream fin(this->dictPath);
	if (!fin.is_open()) return;

	str word;
	while (!fin.eof()) {
		std::getline(fin, word);
		if (!word.empty()) this->words.insert(word);
	}

	fin.close();
}

void Dictionary::addWord(const str& word) {
	str tmpWord{ "" };
	for (const char& chr : word) if (std::isalpha(chr)) tmpWord += std::tolower(chr);
	this->words.insert(tmpWord);
}

bool Dictionary::findWord(const str& word) {
	str tmpWord{ "" };
	for (const char& chr : word) if (std::isalpha(chr)) tmpWord += std::tolower(chr);

	if (this->words.count(tmpWord)) return true;
	return false;
}

void Dictionary::deleteWord(const str& word) {
	str tmpWord{ "" };
	for (const char& chr : word) if (std::isalpha(chr)) tmpWord += std::tolower(chr);
	this->words.erase(tmpWord);
}

setstr Dictionary::getWords() {
	return this->words;
}

bool Dictionary::saveWordsToDict() {
	std::ofstream fout(this->dictPath);
	if (!fout.is_open()) return false;

	for (auto& it : this->words) fout << it << "\n";

	fout.close();
	return true;
}
