#include "TxtAnalyzer.h"

TxtAnalyzer::TxtAnalyzer(const str& filePath) {
	this->filePath = filePath;
}

int TxtAnalyzer::countNumOfWords() const {
    std::ifstream fin;
    fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    int numOfWords{ 0 };

    try {
        std::cout << "Trying to open (" << this->filePath << ") file!" << "\n";
        fin.open(this->filePath);
        std::cout << "File is opened!" << "\n";

        std::string line{ "" };

        while (!fin.eof()) {
            std::getline(fin, line);
            numOfWords += countNumOfWords(line);
        }

        std::cout << "Data is received!" << "\n";
    }
    catch (const std::ofstream::failure& exception) {
        std::cout << exception.what() << "\n" << exception.code() << "\n";
    }

    fin.close();
    return numOfWords;
}

int TxtAnalyzer::countNumOfUniqueWords() const {
    std::ifstream fin;
    fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    int numOfUniqueWords{ 0 };
    std::map<str, int> words;

    try {
        std::cout << "Trying to open (" << this->filePath << ") file!" << "\n";
        fin.open(this->filePath);
        std::cout << "File is opened!" << "\n";

        std::string line{ "" };

        while (!fin.eof()) {
            std::getline(fin, line);
            getWords(line, words);
        }

        numOfUniqueWords = countNumOfUniqueWords(words);

        std::cout << "Data is received!" << "\n";
    }
    catch (const std::ofstream::failure& exception) {
        std::cout << exception.what() << "\n" << exception.code() << "\n";
    }

    fin.close();
    return numOfUniqueWords;
}

setstr TxtAnalyzer::findLongestWords() const {
    std::ifstream fin;
    fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    vecstr words;
    setstr longestWords{};

    try {
        std::cout << "Trying to open (" << this->filePath << ") file!" << "\n";
        fin.open(this->filePath);
        std::cout << "File is opened!" << "\n";

        std::string line{ "" };

        while (!fin.eof()) {
            std::getline(fin, line);
            getWords(line, words);
        }

        findLongestWords(words, longestWords);

        std::cout << "Data is received!" << "\n";
    }
    catch (const std::ofstream::failure& exception) {
        std::cout << exception.what() << "\n" << exception.code() << "\n";
    }

    fin.close();
    return longestWords;
}

setstr TxtAnalyzer::findMostFrequentWords() const {
    std::ifstream fin;
    fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    std::map<str, int> words;
    setstr mostFrequentWords{};

    try {
        std::cout << "Trying to open (" << this->filePath << ") file!" << "\n";
        fin.open(this->filePath);
        std::cout << "File is opened!" << "\n";

        std::string line{ "" };

        while (!fin.eof()) {
            std::getline(fin, line);
            getWords(line, words);
        }

        findMostFrequentWords(words, mostFrequentWords);

        std::cout << "Data is received!" << "\n";
    }
    catch (const std::ofstream::failure& exception) {
        std::cout << exception.what() << "\n" << exception.code() << "\n";
    }

    fin.close();
    return mostFrequentWords;
}

setstr TxtAnalyzer::findMostComplexWords() const {
    std::ifstream fin;
    fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    std::map<str, std::map<char, int>> words;
    setstr mostComplexWords{};

    try {
        std::cout << "Trying to open (" << this->filePath << ") file!" << "\n";
        fin.open(this->filePath);
        std::cout << "File is opened!" << "\n";

        std::string line{ "" };

        while (!fin.eof()) {
            std::getline(fin, line);
            getWords(line, words);
        }

        findMostComplexWords(words, mostComplexWords);

        std::cout << "Data is received!" << "\n";
    }
    catch (const std::ofstream::failure& exception) {
        std::cout << exception.what() << "\n" << exception.code() << "\n";
    }

    fin.close();
    return mostComplexWords;
}

void TxtAnalyzer::getWords(const str& string, vecstr& words) const {
    str word{ "" };

    for (auto it = string.cbegin(); it != string.cend(); ++it) {

        if (std::isalpha(*it)) 
            word += (*it) | ' ';  // word += std::tolower(*it)
        else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }

    }

    if (!word.empty()) words.push_back(word);
}

void TxtAnalyzer::getWords(const str& string, setstr& words) const {
    str word{ "" };

    for (auto it = string.cbegin(); it != string.cend(); ++it) {

        if (std::isalpha(*it)) 
            word += (*it) | ' ';  // word += std::tolower(*it)
        else if (!word.empty()) {
            words.insert(word);
            word.clear();
        }

    }

    if (!word.empty()) words.insert(word);
}

void TxtAnalyzer::getWords(const str& string, mapstrint& words) const {
    str word{ "" };

    for (auto it = string.cbegin(); it != string.cend(); ++it) {

        if (std::isalpha(*it)) 
            word += (*it) | ' ';  // word += std::tolower(*it)
        else if (!word.empty()) {
            words[word] += 1;
            word.clear();
        }

    }

    if (!word.empty()) words[word] += 1;
}

void TxtAnalyzer::getWords(const str& string, std::map<str, std::map<char, int>>& words) const {
    str word{ "" };

    for (auto it = string.cbegin(); it != string.cend(); ++it) {

        if (std::isalpha(*it)) 
            word += (*it) | ' ';  // word += std::tolower(*it)
        else if (!word.empty()) {

            for (auto chr : word) words[word][chr] += 1;

            word.clear();
        }

    }

    if (!word.empty()) 
        for (auto chr : word) words[word][chr] += 1;
}

int TxtAnalyzer::countNumOfWords(const str& string) const {
    int numOfWords{ 0 };
    bool isWord{ false };
    
    for (auto it = string.cbegin(); it != string.cend(); ++it) {

        if (std::isalpha(*it)) isWord = true;
        else if (isWord) {
            ++numOfWords;
            isWord = false;
        }

    }

    if (isWord) numOfWords++;

    return numOfWords;
}

int TxtAnalyzer::countNumOfUniqueWords(mapstrint& words) const {
    int numOfUniqueWords{ 0 };

    for (auto it = words.cbegin(); it != words.cend(); ++it)
        if (((*it).second ^ 1) == 0)    // (*it).second == 1
            numOfUniqueWords++;

    return numOfUniqueWords;
}

void TxtAnalyzer::findLongestWords(const vecstr& words, setstr& longestWords) const {
    int sizeOfLongestWord{ 0 };

    for (auto it = words.cbegin(); it != words.cend(); ++it)
        if ((*it).size() > sizeOfLongestWord) sizeOfLongestWord = (*it).size();

    for (auto it = words.cbegin(); it != words.cend(); ++it)
        if ((*it).size() == sizeOfLongestWord) longestWords.insert(*it);
}

void TxtAnalyzer::findMostFrequentWords(const mapstrint& words, setstr& mostFrequentWords) const {
    int numOfRepeats{ 0 };

    for (auto it = words.cbegin(); it != words.cend(); ++it)
        if ((*it).second > numOfRepeats) numOfRepeats = (*it).second;

    for (auto it = words.cbegin(); it != words.cend(); ++it)
        if ((*it).second == numOfRepeats) mostFrequentWords.insert((*it).first);
}

void TxtAnalyzer::findMostComplexWords(const std::map<str, std::map<char, int>>& words, 
    setstr& mostComplexWords) const {
    int maxNumOfLetters{ 0 }, tmpMax{ 0 };

    for (const auto& it1 : words) {

        if (it1.second.size() > maxNumOfLetters) maxNumOfLetters = it1.second.size();

    }

    for (const auto& it1 : words) {

        if (it1.second.size() == maxNumOfLetters) mostComplexWords.insert(it1.first);

    }
}