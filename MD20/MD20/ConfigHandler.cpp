#include "ConfigHandler.h"

Config cfgln::findConfig(const line& l) {
	std::regex cfg_regex{ "^[\\W]*([\\w-]+)[\\s]*=[\\s]*([\\w-.]+)[\\W]*$" };
	std::smatch cfg_smatch;
	std::regex_match(l, cfg_smatch, cfg_regex);
	if (cfg_smatch.size() >= 3) return Config{ cfg_smatch[1].str(), cfg_smatch[2].str() };
	return Config{};
}

line cfgln::changeConfig(const line& l, const key& k, const value& v) {
	std::regex cfg_regex{ "^([\\W]*)[\\w-]+([\\s]*=[\\s]*)[\\w-.]+([\\W]*)$" };
	std::smatch cfg_smatch;
	std::regex_match(l, cfg_smatch, cfg_regex);
	if (cfg_smatch.size() == 0) return l;
	return cfg_smatch[1].str() + k + cfg_smatch[2].str() + v + cfg_smatch[3].str();
}
