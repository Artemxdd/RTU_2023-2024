#pragma once

#include <iostream>
#include <string>
#include <map>
#include <regex>
#include <algorithm>
#include <fstream>

typedef std::string str;
typedef std::map<str, int> mapstrint;

class Dictionary {
public:
	Dictionary(const str& input, const str& output);

	void saveWordsToDict() const;

private:
	str inputPath, dictPath;
	mapstrint words;

	void getWords();
	mapstrint getWordsFromDict() const;
};

