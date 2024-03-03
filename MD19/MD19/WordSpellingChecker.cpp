#include "WordSpellingChecker.h"

WordSpellingChecker::WordSpellingChecker(const str& dictPath) {
	Dictionary dict{ dictPath };
	this->wordsFromDict = dict.getWords();
	if (this->wordsFromDict.size() < 1) throw std::exception("there are no words in the dictionary");
}

str WordSpellingChecker::checkForMissingLetter(const str& word) {
	if (checkIfWordIsCorrect(word)) return word;

	str tmpWord;
	for (int index{ 0 }; index < word.size() + 1; index++) {
		for (char chr{ 'a' }; chr <= 'z'; chr++) {
			tmpWord = word;
			tmpWord.insert(tmpWord.begin() + index, chr);
			if (this->wordsFromDict.count(tmpWord)) return tmpWord;
		}
	}
	
	return word;
}

str WordSpellingChecker::checkForExtraLetter(const str& word) {
	if (checkIfWordIsCorrect(word)) return word;

	str tmpWord;
	for (int index{ 0 }; index < word.size() - 1; index++) {
		tmpWord = word;
		tmpWord.erase(tmpWord.begin() + index);
		if (this->wordsFromDict.count(tmpWord)) return tmpWord;
	}

	return word;
}

str WordSpellingChecker::checkForWrongLetter(const str& word) {
	if (checkIfWordIsCorrect(word)) return word;

	str tmpWord, letter;
	for (int index{ 0 }; index < word.size() - 1; index++) {
		for (char chr{ 'a' }; chr <= 'z'; chr++) {
			tmpWord = word;
			tmpWord[index] = chr;
			if (this->wordsFromDict.count(tmpWord)) return tmpWord;
		}
	}

	return word;
}

bool WordSpellingChecker::checkIfWordIsCorrect(const str& word) {
	if (this->wordsFromDict.count(word)) return true;
	return false;
}
