#include "ConfigFile.h"

ConfigFile::ConfigFile(const filePath& cfgFile) {
	std::ifstream fin(cfgFile);
	if (!fin.is_open()) throw std::exception{ "Error with configuration file!" };

	line l;
	while (std::getline(fin, l)) this->ls.push_back(l);
}

void ConfigFile::appendNewLine(const line& l) {
	this->ls.push_back(l);
}

bool ConfigFile::changeConfigValue(const key& k, const value& v) {
	for (line& l : this->ls) {
		Config cfg{ cfgln::findConfig(l) };
		if (cfg.getKey() == k) { 
			l = cfgln::changeConfig(l, k, v);
			return true;
		}
	}
	return false;
}

Config ConfigFile::getConfig(const key& k) {
	for (const line& l : this->ls) {
		if (getTypeOfLine(l) == CFG) {
			Config cfg{ cfgln::findConfig(l) };
			if (cfg.getKey() == k) return cfg;
		}
	}
	return Config{ "", "" };
}

Config ConfigFile::getConfigFromComments(const key& k) {
	for (line l : this->ls) {
		if (getTypeOfLine(l) == COMMENT) {
			l[0] = ' ';
			Config cfg{ cfgln::findConfig(l) };
			if (cfg.getKey() == k) return cfg;
		}
	}
	return Config{ "", "" };
}

bool ConfigFile::saveConfigToFile(const filePath& cfgFile) {
	std::ofstream fout(cfgFile);
	if (!fout.is_open()) return false;

	for (auto& it : this->ls) fout << it << "\n";

	fout.close();
	return true;
}

ConfigFile::TypeOfLine ConfigFile::getTypeOfLine(const line& l) {
	if (l.size() == 0) return BLANK;
	if (l[0] == '#') return COMMENT;
	return CFG;
}

