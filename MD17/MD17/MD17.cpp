#include "Dictionary.h"

static str getProjectPath(const str& path) {
    str projectPath{ "" };
    int numberOfBackslashes{ 0 };

    for (auto it{ path.rbegin() }; it < path.rend(); it++) {

        if (*it == '\\')  numberOfBackslashes++;
        if (numberOfBackslashes >= 3) projectPath += *it;

    }

    std::reverse(projectPath.begin(), projectPath.end());
    return projectPath;
}

int main(int argc, char* argv[]) {
    str projectPath{ getProjectPath(argv[0]) },
        inputFile{ projectPath + "input.txt" }, outputFile{ projectPath + "output.txt" };
    std::cout << "Enter input file path! (" << projectPath + "input.txt" << ")" << "\n";
    std::cout << "Input file = "; std::getline(std::cin, inputFile);
    std::cout << "Enter output file path! (" << projectPath + "output.txt" << ")" << "\n";
    std::cout << "Output file = "; std::getline(std::cin, outputFile);

    if (inputFile == "") inputFile = projectPath + "input.txt";
    if (outputFile == "") outputFile = projectPath + "output.txt";

	Dictionary dict{ inputFile, outputFile };
	dict.saveWordsToDict();
}