#pragma once

#include "WordSpellingChecker.h"
#include <fstream>
#include <iostream>
#include <map>

typedef std::vector<str> vecstr;
typedef std::map<str, bool> mapstrbool;

class CorrectTxtInFile {
public:
	CorrectTxtInFile(const str& filePath, const str& dictPath);

	void highligtWrongWordsAndOutToCons() const;
	void correctWrongWordsAndSaveToFile() const;

private:
	vecstr txt;
	str filePath, dictPath;
};