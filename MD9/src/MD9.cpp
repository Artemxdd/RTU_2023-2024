#include <iostream>
#include <string>

bool isStringLowercase(const std::string& str) {
    bool isStringLowercase{ true };

    for (const char& currentChar : str) {

        if (isupper(currentChar)) {
            isStringLowercase = false;
            break;
        }

    }

    return isStringLowercase;
}

unsigned int countLowercaseWords(const std::string& str) {
    std::string word{ "" };
    unsigned int amountOfLowercaseWords{ 0 };

    for (const char& currentChar : str) {

        if (isalpha(currentChar)) word += currentChar; 
        else if (!word.empty()) { 

            if (isStringLowercase(word)) amountOfLowercaseWords++; 

            word.clear();
        }

    }

    if (!word.empty() && isStringLowercase(word)) amountOfLowercaseWords++;

    return amountOfLowercaseWords;
}

unsigned int countTheLongestWordLength(const std::string& str) {
    std::string word{ "" };
    unsigned int lengthOfTheLongestWord{ 0 };

    for (const char& currentChar : str) {
        
        if (isalpha(currentChar)) word += currentChar;
        else if (!word.empty()) {

            if (word.length() > lengthOfTheLongestWord) lengthOfTheLongestWord = word.length();

            word.clear();
        }

    }

    if (!word.empty() && word.length() > lengthOfTheLongestWord) lengthOfTheLongestWord = word.length();

    return lengthOfTheLongestWord;
}

std::string changeFirstLetterToUppercaseAndRestLettersToLowercase(const std::string& str) {
    std::string strWithChanges{ "" };
    unsigned int lengthOfWord{ 0 };

    for (const char& currentChar : str) {

        if (isalpha(currentChar)) { 
            lengthOfWord++;

            if (lengthOfWord == 1) strWithChanges += toupper(currentChar);
            else strWithChanges += tolower(currentChar);

        }
        else {
            strWithChanges += currentChar;
            lengthOfWord = 0;
        }

    }

    return strWithChanges;
}

std::string getLowercaseString(const std::string& str) {
    std::string lowercaseString{ "" };

    for (char currentChar : str) lowercaseString += tolower(currentChar);

    return lowercaseString;
}

void appendWord(const std::string& word, std::string words[], unsigned int& numberOfWords) {

    for (int index = 0; index < numberOfWords; index++) {

        if (words[index] == word) return;

    }

    words[numberOfWords++] = word;
}

void showWords(std::string words[], unsigned int numberOfWords) {
    
    for (int index = 0; index < numberOfWords; index++) {
        std::cout << words[index];

        if (index < numberOfWords - 1) std::cout << ", ";

    }

}

void getListOfWordsEnclosedInParentheses(const std::string& str, std::string words[], unsigned int& numberOfWords) {
    std::string word{ "" };
    unsigned int numberOfRoundBrackets{ 0 };

    for (const char& currentChar : str) {

        if (currentChar == '(') numberOfRoundBrackets++; 

        if (numberOfRoundBrackets > 0) {

            if (isalpha(currentChar)) word += currentChar;
            else if (!word.empty()) {
                appendWord(getLowercaseString(word), words, numberOfWords);
                word.clear();
            }

        }

        if (currentChar == ')') numberOfRoundBrackets--;

    }

}

int main() {
    std::string str{ "" };
    std::cout << "Enter string! String = ";
    std::getline(std::cin, str);
    std::cout << "\n\n";

    std::string words[100]{ "" };
    unsigned int numberOfWords = 0;

    std::cout << "Number of lowercase words: " << countLowercaseWords(str) << "\n\n";
    std::cout << "Length of the longest word: " << countTheLongestWordLength(str) << "\n\n";
    std::cout << "String where the first letter is uppercase and the rest letters are lowercase:\n"
        << changeFirstLetterToUppercaseAndRestLettersToLowercase(str) << "\n\n";
    std::cout << "List of words enclosed in parentheses:\n"; 
    getListOfWordsEnclosedInParentheses(str, words, numberOfWords);
    showWords(words, numberOfWords);
}