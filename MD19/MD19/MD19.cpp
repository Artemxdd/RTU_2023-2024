#include <iostream>
#include "CorrectTxtInFile.h"

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
	str projPath{ getProjectPath(argv[0]) },
        dictPath{ projPath + "dictionary.txt" },
		srcPath;

    std::cout << "Enter input file path! (" << projPath + "input.txt" << ")" << "\n";
    std::cout << "Input file = "; std::getline(std::cin, srcPath);
    if (srcPath == "") srcPath = projPath + "input.txt";

    try {
        CorrectTxtInFile correct{ srcPath, dictPath };
        correct.highligtWrongWordsAndOutToCons();
        correct.correctWrongWordsAndSaveToFile();
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << "\n";
    }

}