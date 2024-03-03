#include "TxtAnalyzer.h"

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

int main(int argc, char* argv[]) {
    str projectPath{ getProjectPath(argv[0]) };
    TxtAnalyzer analyzer{ projectPath + "input.txt" };
    str result{ "words: " + std::to_string(analyzer.countNumOfWords()) + "\n" +
                "unique words: " + std::to_string(analyzer.countNumOfUniqueWords()) + "\n"};
    
    result += "longest words: ";
    for (auto& word : analyzer.findLongestWords()) result += word + "\t";
    result += "\n";

    result += "most frequent words: ";
    for (auto& word : analyzer.findMostFrequentWords()) result += word + "\t";
    result += "\n";

    result += "most complex words: ";
    for (auto& word : analyzer.findMostComplexWords()) result += word + "\t";
    result += "\n";

    if (!overwriteFile(projectPath + "output.txt", result))
        std::cout << "Error overwriting the file!" << "\n";
}