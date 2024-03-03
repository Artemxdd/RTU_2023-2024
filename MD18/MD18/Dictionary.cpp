#include "Dictionary.h"

Dictionary::Dictionary(const str& input, const str& output) {
    this->inputPath = input;
    this->outputPath = output;
    if (loadInWords() == Status::ERROR) throw std::exception("STATUS:ERROR");
    if (loadOutWords() == Status::ERROR) throw std::exception("STATUS:ERROR");
}

mapstrint Dictionary::getInWords() {
    return this->wordsFromIn;
}

mapstrint Dictionary::getOutWords() {
    return this->wordsFromOut;
}

Dictionary::Status Dictionary::saveWordsToOut() const {
    std::ofstream fout;
    mapstrint allWords;

    for (auto& it : this->wordsFromIn) allWords[it.first] += it.second;
    for (auto& it : this->wordsFromOut) allWords[it.first] += it.second;

    fout.open(this->outputPath);
    if (!fout.is_open()) return Dictionary::ERROR;

    for (auto it{ allWords.begin() }; it != allWords.end(); ++it) {
        fout << it->first << "\t" << it->second;
        if (it != (--allWords.end())) fout << "\n";
    }

    fout.close();
    return Dictionary::OK;
}

vecstr Dictionary::getWrongWordsFromIn() const {
    vecstr incorrectWords;

    for (auto& it : this->wordsFromIn) {
        if (this->wordsFromOut.count(it.first) == 0) {
            incorrectWords.push_back(it.first);
        }
    }

    return incorrectWords;
}

Dictionary::Status Dictionary::loadInWords() {
    std::ifstream fin;

    fin.open(this->inputPath);
    if (!fin.is_open()) return Dictionary::ERROR;

    str line{ "" };
    std::regex ex{ "[a-zA-Z]+" };

    while (!fin.eof()) {
        std::getline(fin, line);

        for (std::sregex_iterator it = std::sregex_iterator(line.begin(), line.end(), ex);
            it != std::sregex_iterator(); ++it) {
            str word = (*it).str();
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            this->wordsFromIn[word] += 1;
        }

    }

    fin.close();
    return Dictionary::OK;
}

Dictionary::Status Dictionary::loadOutWords() {
    std::ifstream fin;

    fin.open(this->outputPath);
    if (!fin.is_open()) return Dictionary::ERROR;

    mapstrint words;
    str line{ "" };
    std::regex ex{ "([a-z]+)\t([0-9]+)" };
    std::smatch sm;

    while (!fin.eof()) {
        std::getline(fin, line);
        if (std::regex_match(line, sm, ex)) words[sm[1]] = stoi(sm[2]);
    }

    this->wordsFromOut = words;

    fin.close();
    return Dictionary::OK;
}