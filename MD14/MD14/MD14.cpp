#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include "ArithmeticalErrorFinder.h"

bool overwriteFile(const std::string& fileName, const std::string& string) {
    FILE* file;
    fopen_s(&file, fileName.c_str(), "w");

    if (!file) return false;

    fputs(string.c_str(), file);
    fclose(file);

    return true;
}

bool readDataFromFile(const std::string& fileName, std::string& dataFromFile) {
    FILE* file;
    fopen_s(&file, fileName.c_str(), "r");

    if (!file) return false;

    char temporaryDataFromFile[100];

    while (fgets(temporaryDataFromFile, 100, file)) dataFromFile += temporaryDataFromFile;

    fclose(file);

    return true;
}

int main() {
    std::string dataFromFile{ "" }, firstSummand{ "" }, secondSummand{""}, sum{ "" };

    if (!readDataFromFile("input.txt", dataFromFile)) std::cout << "Error opening the file!";

    char firstSummandChar[100]{ 0 }, secondSummandChar[100]{ 0 }, sumChar[100]{ 0 };
    sscanf_s(dataFromFile.c_str(), "%[0-9]+%[0-9]=%[0-9]", firstSummandChar, 100, secondSummandChar, 100, sumChar, 100);

    firstSummand = firstSummandChar;
    secondSummand = secondSummandChar;
    sum = sumChar;

    ArithmeticalErrorFinder errorFinder{};
    std::vector<std::string> results;

    if (!(errorFinder.checkIfThereIsExtraDigit(firstSummand, secondSummand, sum, results)))
        results.push_back("There is no extra digit");

    if (!(errorFinder.checkIfThereIsWrongDigit(firstSummand, secondSummand, sum, results)))
        results.push_back("There is no wrong digit");

    if (!(errorFinder.checkIfThereIsMissingDigit(firstSummand, secondSummand, sum, results)))
        results.push_back("There is no missing digit");

    std::string resultsAsString{ "" };

    for (auto& result : results) resultsAsString += result + "\n";

    if (!overwriteFile("output.txt", resultsAsString)) std::cout << "Error overwriting the file!";

}