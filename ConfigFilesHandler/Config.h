#pragma once

#include <string>

typedef std::string key, value;

class Config {
public:
	Config();	// Empty config
	Config(const key& k, const value& v);	// Config with key and value
	virtual ~Config();

	key getKey() const;	// Getter
	value getValue() const;	// Getter

	virtual void setKey(const key& k);	// Setter
	virtual void setValue(const value& v);	// Setter

	void clear();	// Set key and value to ""

	value operator[](const key& k);	// Get value by key

private:
	key k; 
	value v;
};

