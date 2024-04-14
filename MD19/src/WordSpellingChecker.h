#pragma once

#include "Dictionary.h"

class WordSpellingChecker {	// word should be lowercase
public:
	WordSpellingChecker(const str& dictPath);

	str checkForMissingLetter(const str& word);
	str checkForExtraLetter(const str& word);
	str checkForWrongLetter(const str& word);
	bool checkIfWordIsCorrect(const str& word);

private:
	setstr wordsFromDict;
};

