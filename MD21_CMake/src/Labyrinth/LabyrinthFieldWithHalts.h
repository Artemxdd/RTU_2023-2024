#pragma once

#include "LabyrinthField.h"

class LabyrinthFieldWithHalts : public LabyrinthField {
public:
	LabyrinthFieldWithHalts(const file_path_t& filePath);

	bool isCellHalt(const row_t& row, const column_t& column) const;
	bool isCellHalt(const LabyrinthCell& cell) const;

private:
	void defineType() override;
};

