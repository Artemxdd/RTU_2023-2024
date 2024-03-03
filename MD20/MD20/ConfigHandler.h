#pragma once

#include <regex>
#include "Config.h"

typedef std::string key, value, line;

// Config in line
namespace cfgln {
	Config findConfig(const line& l);
	line changeConfig(const line& l, const key& k, const value& v);
};

