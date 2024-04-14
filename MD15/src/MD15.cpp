#include <iostream>
#include <fstream>
#include "ArithmeticalErrorFinder.h"

static bool overwriteFile(const std::string& path, const std::string& string) {
    std::ofstream fout;
    fout.exceptions(std::ofstream::badbit | std::ofstream::failbit);

    try {
        std::cout << "Trying to open (" << path << ") file!" << "\n";
        fout.open(path);
        std::cout << "File is opened or created!" << "\n";
        fout << string;
        std::cout << "Data is recorded!" << "\n";
    }
    catch (const std::ifstream::failure& exception) {
        std::cout << exception.what() << "\n" << exception.code() << "\n";
        return false;
    }

    fout.close();
    return true;
}

static bool readDataFromFile(const std::string& path, std::string& dataFromFile) {
    std::ifstream fin;
    fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);

    try {
        std::cout << "Trying to open (" << path << ") file!" << "\n";
        fin.open(path);
        std::cout << "File is opened!" << "\n";
        
        std::string line{ "" };

        while (!fin.eof()) {
            line = "";
            std::getline(fin, line);
            dataFromFile += line;
        }

        std::cout << "Data is received!" << "\n";
    }
    catch (const std::ofstream::failure& exception) {
        std::cout << exception.what() << "\n" << exception.code() << "\n";
        return false;
    }

    fin.close();
    return true;
}

static std::string getProjectPath(const std::string& path) {
    std::string projectPath{ "" };
    int numberOfBackslashes{ 0 };

    for (auto it{ path.rbegin() }; it < path.rend(); it++) {

        if (*it == '\\')  numberOfBackslashes++;
        if (numberOfBackslashes >= 3) projectPath += *it;

    }

    std::reverse(projectPath.begin(), projectPath.end());
    return projectPath;
}

int main(int argc, char* argv[]) {
    std::string arithmeticExpression{ "" }, projectPath{ getProjectPath(argv[0])};

    if (argc < 2) {

        if (!readDataFromFile(projectPath + "input.txt", arithmeticExpression)) 
            std::cout << "Error opening the file!" << "\n";

    }
    else arithmeticExpression = argv[1];

    ArithmeticalErrorFinder errorFinder;
    std::vector<std::string> results;
    std::string firstSummand{ "" }, secondSummand{ "" }, sum{ "" }, theMostSuitableFix{ "" };
 
    char firstSummandChar[1000]{ 0 }, secondSummandChar[1000]{ 0 }, sumChar[1000]{ 0 };
    sscanf_s(arithmeticExpression.c_str(), "%[0-9]+%[0-9]=%[0-9]", firstSummandChar, 1000, 
        secondSummandChar, 1000, sumChar, 1000);

    firstSummand = firstSummandChar;
    secondSummand = secondSummandChar;
    sum = sumChar;

    if (!(errorFinder.checkIfThereIsExtraDigit(firstSummand, secondSummand, sum, results)))
        results.push_back("There is no extra digit");

    if (!(errorFinder.checkIfThereIsWrongDigit(firstSummand, secondSummand, sum, results)))
        results.push_back("There is no wrong digit");

    if (!(errorFinder.checkIfThereIsMissingDigit(firstSummand, secondSummand, sum, results)))
        results.push_back("There is no missing digit");

    if (!(errorFinder.checkIfThereAreTwoDigitsInRowInWrongOrder(firstSummand, secondSummand, sum, results)))
        results.push_back("There are no two digits in the row in a wrong order");

    if (!(errorFinder.checkIfThereAreTwoWrongDigits(firstSummand, secondSummand, sum, results)))
        results.push_back("There are no two wrong digits");

    if (!(errorFinder.checkIfThereIsTheMostSuitableFix(firstSummand, secondSummand, sum, theMostSuitableFix)))
        results.push_back("There is no suitable fix because there are no answers");

    if (theMostSuitableFix.size() > 0) results.push_back("The most suitable fix is: " + theMostSuitableFix);

    if (argc < 2) {
        std::string resultsAsString{ "" };

        for (auto& result : results) resultsAsString += result + "\n";

        if (!overwriteFile(projectPath + "output.txt", resultsAsString)) 
            std::cout << "Error overwriting the file!" << "\n";

    }
    else
        for (auto& result : results) std::cout << result + "\n";

    system("pause");
    return 0;
}