#include "LabyrinthFieldWithHalts.h"

LabyrinthFieldWithHalts::LabyrinthFieldWithHalts(const file_path_t& filePath) : LabyrinthField(filePath) {
	// ...
}

bool LabyrinthFieldWithHalts::isCellHalt(const row_t& row, const column_t& column) const {
  for (auto& cell : this->field_)
    if ((cell.getRow() == row) && (cell.getColumn() == column))
      if (cell.getCellType() == CellType::HALT)
        return true;
  return false;
}

bool LabyrinthFieldWithHalts::isCellHalt(const LabyrinthCell& cell) const {
  if (cell.getCellType() == CellType::HALT) return true;
  return false;
}

void LabyrinthFieldWithHalts::defineType() {
  this->type_ = FieldType::WITH_HALTS;
}
