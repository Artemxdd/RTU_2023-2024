#pragma once

#include <vector>
#include <fstream>
#include "ConfigHandler.h"

typedef std::string filePath;
typedef std::vector<std::string> lines;

class ConfigFile {
public:
	ConfigFile(const filePath& cfgFile);

	void appendNewLine(const line& l);
	bool changeConfigValue(const key& k, const value& v);

	Config getConfig(const key& k);	
	Config getConfigFromComments(const key& k);	

	bool saveConfigToFile(const filePath& cfgFile);

private:
	lines ls;	// Lines from cfg file

	enum TypeOfLine {
		CFG, COMMENT, BLANK
	};

	TypeOfLine getTypeOfLine(const line& l);
};

