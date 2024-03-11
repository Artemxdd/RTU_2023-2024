#pragma once

#include <regex>
#include "Config.h"

typedef std::string line;

enum TypeOfLine { CONFIG, COMMENTED_CONFIG, COMMENT, BLANK, UNDEFINED };

class LineInConfigFile : private Config {
public:
	LineInConfigFile(const line& l);

	line getLine() const;	// Getter
	TypeOfLine getTypeOfLine() const;	// Getter
	Config getConfig() const;	// Getter

	void setLine(const line& l);	// Setter
	void setKey(const key& k);	// Setter
	void setValue(const value& v);	// Setter

private:
	line l;
	TypeOfLine tol;

	void setTypeOfLine();	// Setter

	Config parse(const line& l) const;
};

