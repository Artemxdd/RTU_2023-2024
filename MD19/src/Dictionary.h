#pragma once

#include <string>
#include <set>
#include <regex>
#include <fstream>

typedef std::string str;
typedef std::set<str> setstr;

class Dictionary {
public:
	Dictionary(const str& dictPath);

	void addWord(const str& word);
	bool findWord(const str& word);
	void deleteWord(const str& word);

	setstr getWords();	// Getter
	bool saveWordsToDict();	// Save words from class to dictionary file

private:
	str dictPath;
	setstr words;
};

