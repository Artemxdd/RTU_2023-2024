#pragma once

#include <string>

typedef std::string key, value;

class Config {
public:
	Config();	// Empty config
	Config(key k, value v);	// Config with key and value

	key getKey() const;	// Getter
	value getValue() const;	// Getter

	void setKey(key k);	// Setter
	void setValue(value v);	// Setter

	void clear();	// Set key and value to ""

private:
	key k; 
	value v;
};

