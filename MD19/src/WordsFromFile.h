#pragma once

#include <string>
#include <map>
#include <fstream>

typedef std::string str;
typedef std::map<str, int> mapstrint;

class WordsFromFile {
public:
	WordsFromFile(const str& filePath);

	mapstrint getWords();	// Getter

private:
	str filePath;
	mapstrint words;
};

