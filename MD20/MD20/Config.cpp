#include "Config.h"

Config::Config() {
	this->k = "";
	this->v = "";
}

Config::Config(key k, value v) {
	this->k = k;
	this->v = v;
}

key Config::getKey() const {
	return this->k;
}

value Config::getValue() const {
	return this->v;
}

void Config::setKey(key k) {
	this->k = k;
}

void Config::setValue(value v) {
	this->v = v;
}

void Config::clear() {
	this->k = "";
	this->v = "";
}

