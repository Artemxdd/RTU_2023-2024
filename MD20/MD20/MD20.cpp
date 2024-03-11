#include <iostream>
#include "ConfigFile.h"

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
    filePath projPath{ getProjectPath(argv[0]) };
    std::string cfgFileName{ "config.txt" };
    ConfigFile cfgFile{ projPath + cfgFileName };
    
    key k1;
    std::cout << "Enter config key! Key = "; std::cin >> k1;

    // Check if configuration is in configuration lines
    Config cfg{ cfgFile.getConfig(k1) };
    if (cfg.getValue() == "") std::cout << "There is no the config with this key in configuration lines!" << "\n";
    else std::cout << "There is the config with this key in configuration lines!\n" 
        << "Key = " << k1 << "\nValue = " << cfg.getValue() << "\n";

    // Check if configuration is in comments
    cfg = cfgFile.getConfigFromComments(k1);
    if (cfg.getValue() == "") std::cout << "There is no the config with this key in comments!" << "\n";
    else std::cout << "There is the config with this key in comments!\n" 
        << "Key = " << k1 << "\nValue = " << cfg.getValue() << "\n";

    // Change configuration value
    key k2;
    value v;
    std::cout << "Enter config key and new value!\nKey = "; std::cin >> k2;
    std::cout << "Value = "; std::cin >> v;
    if (cfgFile.changeConfigValue(k2, v)) cfgFile.saveConfigToFile(projPath + "new_" + cfgFileName);
    else { 
        cfgFile.appendNewLine(k2 + "=" + v);
        cfgFile.saveConfigToFile(projPath + "new_" + cfgFileName);
    };
}
