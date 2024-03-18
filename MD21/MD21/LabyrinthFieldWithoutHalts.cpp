#include "LabyrinthFieldWithoutHalts.h"

LabyrinthFieldWithoutHalts::LabyrinthFieldWithoutHalts(const file_path_t& filePath)
	: LabyrinthField(filePath) {

}

void LabyrinthFieldWithoutHalts::defineType() {
	this->type_ = FieldType::WITH_HALTS;
}
