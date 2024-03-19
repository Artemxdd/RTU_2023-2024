#pragma once

#include "LabyrinthField.h"

class LabyrinthFieldWithoutHalts : public LabyrinthField {
public:
	LabyrinthFieldWithoutHalts(const file_path_t& filePath);

private:
	void defineType() override;
};

