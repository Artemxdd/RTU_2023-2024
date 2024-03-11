#include "ConfigFile.h"

ConfigFile::ConfigFile(const filePath& cfgFile) {
	std::ifstream fin(cfgFile);
	if (!fin.is_open()) throw std::exception{};

	line l;
	while (std::getline(fin, l)) this->licf.push_back(LineInConfigFile(l));
}

void ConfigFile::appendLine(const line& l) {
	this->licf.push_back(LineInConfigFile(l));
}

void ConfigFile::deleteLine(const int& index) {
	this->licf.erase(this->licf.begin() + index);
}

void ConfigFile::replaceLine(const int& index, const line& l) {
	this->licf[index] = LineInConfigFile(l);
}

bool ConfigFile::saveLinesToFile(const filePath& fp) const {
	std::ofstream fout(fp);
	if (!fout.is_open()) return false;

	for (auto& it : this->licf) fout << it.getLine() << "\n";

	fout.close();
	return true;
}

v_licfgfile ConfigFile::getLines() {
	return this->licf;
}

void ConfigFile::changeConfig(const key& k, const value& v) {
	for (auto& it : this->licf)
		if (it.getTypeOfLine() == CONFIG && it.getConfig().getKey() == k)
			it.setValue(v);
}

Config ConfigFile::getConfig(const key& k) const {
	for (auto it : this->licf)
		if (it.getTypeOfLine() == CONFIG && it.getConfig().getKey() == k)
			return it.getConfig();

	return Config{ "", "" };
}

v_cfgs ConfigFile::getCommentedConfigs(const key& k) const {
	v_cfgs cfgs;

	for (auto it : this->licf)
		if (it.getTypeOfLine() == COMMENTED_CONFIG && it.getConfig().getKey() == k)
			cfgs.push_back(it.getConfig());

	return cfgs;
}
