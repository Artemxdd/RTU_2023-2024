#pragma once

#include "Field.h"

class FieldWithHalts : public Field {
public:
	FieldWithHalts(const file_path_t& filePath);

	size_t getHaltsNumber() const;	// Getter

private:
	size_t haltsNumber_;
};

