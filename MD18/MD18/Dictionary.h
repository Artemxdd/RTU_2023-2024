#pragma once

#include <string>
#include <map>
#include <vector>
#include <regex>
#include <fstream>

typedef std::string str;
typedef std::vector<std::string> vecstr;
typedef std::map<str, int> mapstrint;

class Dictionary {
public:
	enum Status {
		OK, ERROR
	};

	Dictionary(const str& input, const str& output);

	mapstrint getInWords(); // Getter
	mapstrint getOutWords(); // Getter

	Status saveWordsToOut() const;
	vecstr getWrongWordsFromIn() const;

private:
	str inputPath, outputPath;
	mapstrint wordsFromIn, wordsFromOut;

	Status loadInWords(); // Load words from input file
	Status loadOutWords(); // Load words from output file
};

