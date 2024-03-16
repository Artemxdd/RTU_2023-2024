#include "LineInConfigFile.h"

LineInConfigFile::LineInConfigFile(const line& l) {
	this->setLine(l);
}

line LineInConfigFile::getLine() const {
	return this->l;
}

TypeOfLine LineInConfigFile::getTypeOfLine() const {
	return this->tol;
}

Config LineInConfigFile::getConfig() const {
	return Config(this->getKey(), this->getValue());
}

void LineInConfigFile::setLine(const line& l) {
	this->l = l;
	Config cfg(parse(this->l));
	Config::setKey(cfg.getKey());
	Config::setValue(cfg.getValue());
	this->setTypeOfLine();
}

void LineInConfigFile::setKey(const key& k) {
	std::regex cfg_regex{ "^([\\W]*)[\\w-]+([\\s]*=[\\s]*)[\\w.-]+([\\W]*)$" };
	std::smatch cfg_smatch;
	std::regex_match(l, cfg_smatch, cfg_regex);
	if (cfg_smatch.size() == 0) return;
	Config::setKey(k);
	this->l = cfg_smatch[1].str() + Config::getKey() + cfg_smatch[2].str() + Config::getValue() + cfg_smatch[3].str();
	this->setTypeOfLine();
}

void LineInConfigFile::setValue(const value& v) {
	std::regex cfg_regex{ "^([\\W]*)[\\w-]+([\\s]*=[\\s]*)[\\w.-]+([\\W]*)$" };
	std::smatch cfg_smatch;
	std::regex_match(l, cfg_smatch, cfg_regex);
	if (cfg_smatch.size() == 0) return;
	Config::setValue(v);
	this->l = cfg_smatch[1].str() + Config::getKey() + cfg_smatch[2].str() + Config::getValue() + cfg_smatch[3].str();
	this->setTypeOfLine();
}

void LineInConfigFile::setTypeOfLine() {
	if (this->getLine() == "") this->tol = BLANK;
	else if (this->getLine()[0] == '#') {
		if (this->getKey() == "" && this->getValue() == "") this->tol = COMMENT;
		else if (this->getKey() != "" && this->getValue() != "") this->tol = COMMENTED_CONFIG;
		else this->tol = UNDEFINED;
	}
	else if (this->getLine()[0] != '#') {
		if (this->getKey() != "" && this->getValue() != "") this->tol = CONFIG;
		else this->tol = UNDEFINED;
	}
}

Config LineInConfigFile::parse(const line& l) const {
	std::regex cfg_regex{ "^[\\W]*([\\w-]+)[\\s]*=[\\s]*([\\w.-]+)[\\W]*$" };
	std::smatch cfg_smatch;
	std::regex_match(l, cfg_smatch, cfg_regex);
	if (cfg_smatch.size() >= 3) return Config(cfg_smatch[1].str(), cfg_smatch[2].str());
	return Config();
}
