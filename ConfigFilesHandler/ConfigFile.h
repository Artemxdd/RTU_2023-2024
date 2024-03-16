#pragma once

#include <vector>
#include <fstream>
#include <regex>
#include "LineInConfigFile.h"

typedef std::string filePath;
typedef std::vector<Config> v_cfgs;
typedef std::vector<LineInConfigFile> v_licfgfile;

class ConfigFile {
public:
	ConfigFile(const filePath& cfgFile);

	void appendLine(const line& l);
	void deleteLine(const int& index);
	void replaceLine(const int& index, const line& l);
	bool saveLinesToFile(const filePath& fp) const;
	v_licfgfile getLines(); // Getter

	void changeConfig(const key& k, const value& v);	// Changes config's value with type CONFIG
	Config getConfig(const key& k) const;	// Finds config in lines with type CONFIG
	v_cfgs getCommentedConfigs(const key& k) const;

private:
	v_licfgfile licf;	// Line, type of line, key, value
};

