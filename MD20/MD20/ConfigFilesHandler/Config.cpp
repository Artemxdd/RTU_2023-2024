#include "Config.h"

Config::Config() {
	this->k = "";
	this->v = "";
}

Config::Config(const key& k, const value& v) {
	this->k = k;
	this->v = v;
}

key Config::getKey() const {
	return this->k;
}

value Config::getValue() const {
	return this->v;
}

void Config::setKey(const key& k) {
	this->k = k;
}

void Config::setValue(const value& v) {
	this->v = v;
}

void Config::clear() {
	this->k = "";
	this->v = "";
}

value Config::operator[](const key& k) {
	return this->v;
}
