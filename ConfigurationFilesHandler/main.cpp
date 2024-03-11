#include <iostream>
#include <filesystem>
#include "ConfigFile.h"

int main(int argc, char* argv[]) {
	filePath projPath(std::filesystem::current_path());
    std::string cfgFileName{ "config.txt" };
    ConfigFile cfgFile{ projPath + "/" + cfgFileName };

    //v_cfg v = cfgFile.getConfig("test1");
    //for (auto it : v) std::cout << it.getKey() << "\t" << it.getValue() << "\n";

//    key k1;
//    std::cout << "Enter config key! Key = "; std::cin >> k1;

    // Check if configuration is in configuration lines
//    Config cfg(cfgFile.getConfig(k1)[0]);
//    if (cfg.getValue() == "") std::cout << "There is no the config with this key in configuration lines!" << "\n";
//    else std::cout << "There is the config with this key in configuration lines!\n"
//        << "Key = " << k1 << "\nValue = " << cfg.getValue() << "\n";
//
//    // Check if configuration is in comments
//    cfg = cfgFile.getConfigFromComments(k1);
//    if (cfg.getValue() == "") std::cout << "There is no the config with this key in comments!" << "\n";
//    else std::cout << "There is the config with this key in comments!\n"
//        << "Key = " << k1 << "\nValue = " << cfg.getValue() << "\n";

    // Change configuration value
    //key k2;
    //value v;
    //std::cout << "Enter config key and new value!\nKey = "; std::cin >> k2;
    //std::cout << "Value = "; std::cin >> v;
    //if (cfgFile.changeConfigValue(k2, v)) cfgFile.saveConfigToFile(projPath + "new_" + cfgFileName);
    //else {
        //cfgFile.appendNewLine(k2 + "=" + v);
        //cfgFile.saveConfigToFile(projPath + "new_" + cfgFileName);
    //};
}
