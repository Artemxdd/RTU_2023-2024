#include <iostream>
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

static void setColor(int color) {
    std::cout << "\x1b[" << color << "m";
}

static void resetColor() {
    std::cout << "\x1b[0m";
}

int main(int argc, char* argv[]) {
    str projPath{ getProjectPath(argv[0]) }, inPath, outPath;

    std::cout << "Enter input file path! (" << projPath + "input.txt" << ")" << "\n";
    std::cout << "Input file = "; std::getline(std::cin, inPath);
    std::cout << "Enter output file path! (" << projPath + "output.txt" << ")" << "\n";
    std::cout << "Output file = "; std::getline(std::cin, outPath);

    if (inPath == "") inPath = projPath + "input.txt";
    if (outPath == "") outPath = projPath + "output.txt";

    vecstr wrongWords;
    try {
        Dictionary dict{ inPath, outPath };
        wrongWords = dict.getWrongWordsFromIn();

        setColor(31);
        for (auto& it : wrongWords) std::cout << it << "\n";
        resetColor();
        std::cout << "Number of wrong words: " << wrongWords.size() << "\n";
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << "\n";
    }
}