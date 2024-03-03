#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

typedef std::string str;
typedef std::vector<str> vecstr;
typedef std::set<str> setstr;
typedef std::map<str, int> mapstrint;

class TxtAnalyzer {
public:
	TxtAnalyzer(const str& filePath);

	int countNumOfWords() const;
	int countNumOfUniqueWords() const;
	setstr findLongestWords() const;
	setstr findMostFrequentWords() const;
	setstr findMostComplexWords() const;

private:
	str filePath;

	void getWords(const str& string, vecstr& words) const;
	void getWords(const str& string, setstr& words) const;
	void getWords(const str& string, mapstrint& words) const;
	void getWords(const str& string, std::map<str, std::map<char, int>>& words) const;
	
	int countNumOfWords(const str& string) const;
	int countNumOfUniqueWords(mapstrint& words) const;
	void findLongestWords(const vecstr& words, setstr& longestWords) const;
	void findMostFrequentWords(const mapstrint& words, setstr& mostFrequentWords) const;
	void findMostComplexWords(const std::map<str, std::map<char, int>>& words, setstr& mostComplexWords) const;
};