#pragma once

#include "LabyrinthField.h"

class LabyrinthFieldWithHalts : public LabyrinthField {
public:
	LabyrinthFieldWithHalts(const file_path_t& filePath);

	size_t getHaltsNumber() const;	// Getter

	bool isCellHalt(const row_t& row, const column_t& column) const;
	bool isCellHalt(const LabyrinthCell& cell) const;

private:
	size_t haltsNumber_;

	void defineType() override;
};

