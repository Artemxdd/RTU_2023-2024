#include "Dictionary.h"

Dictionary::Dictionary(const str& input, const str& output) {
	this->inputPath = input;
    this->dictPath = output;
    getWords();
}

void Dictionary::saveWordsToDict() const {
    std::ofstream fout;
    fout.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    mapstrint words{ getWordsFromDict() };
    size_t numOfWords{ words.size() };

    for (auto& it : this->words) words[it.first] += it.second;

    try {
        std::cout << "Trying to open (" << this->dictPath << ") file!" << "\n";
        fout.open(this->dictPath);
        std::cout << "File is opened!" << "\n";

        for (auto it{ words.begin() }; it != words.end(); ++it) {
            fout << it->first << "\t" << it->second;
            if (it != (--words.end())) fout << "\n";
        }

        std::cout << "Data is recorded!" << "\n";
    }
    catch (const std::ofstream::failure& exception) {
        std::cout << exception.what() << "\n" << exception.code() << "\n";
    }

    fout.close();

    std::cout << "There were " << numOfWords << " words in the dictionary!\n";

    if (this->words.size() > numOfWords) std::cout << numOfWords - this->words.size();
    else std::cout << "0";

    std::cout << " new words have been added!";
}

void Dictionary::getWords() {
    std::ifstream fin;
    fin.exceptions(std::ifstream::badbit);

    try {
        std::cout << "Trying to open (" << this->inputPath << ") file!" << "\n";
        fin.open(this->inputPath);
        std::cout << "File is opened!" << "\n";

        str line{ "" };
        std::regex ex{ "[a-zA-Z'-]+" };

        while (!fin.eof()) {
            std::getline(fin, line);
            
            for (std::sregex_iterator it = std::sregex_iterator(line.begin(), line.end(), ex);
                it != std::sregex_iterator(); ++it) {
                str word = (*it).str();
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                this->words[word] += 1;
            }

        }

        std::cout << "Data is received!" << "\n";
    }
    catch (const std::ifstream::failure& exception) {
        std::cout << exception.what() << "\n" << exception.code() << "\n";
    }

    fin.close();
}

mapstrint Dictionary::getWordsFromDict() const {
    std::ifstream fin;
    fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    mapstrint words;

    try {
        std::cout << "Trying to open (" << this->dictPath << ") file!" << "\n";
        fin.open(this->dictPath);
        std::cout << "File is opened!" << "\n";

        str line{ "" };
        std::regex ex{ "([a-z]+)\t([0-9]+)" };
        std::smatch sm;

        while (!fin.eof()) {
            std::getline(fin, line);
            if (std::regex_match(line, sm, ex)) words[sm[1]] = stoi(sm[2]);
        }

        std::cout << "Data is received!" << "\n";
    }
    catch (const std::ifstream::failure& exception) {
        std::cout << exception.what() << "\n" << exception.code() << "\n";
    }

    fin.close();
    
    return words;
}