#include "LabyrinthField.h"

LabyrinthField::LabyrinthField() {
}

LabyrinthField::LabyrinthField(const file_path_t& filePath) {
  std::ifstream fin{ filePath };
  if (!fin.is_open()) throw std::exception{ "LabyrinthField: File is not opened!" };

  std::string line{};
  row_t rowIndex{ 0 };
  column_t columnIndex{};
  while (getline(fin, line)) { 
    columnIndex = 0;
    for (size_t i{ 0 }; i < line.size(); i++) 
      this->field_.push_back(LabyrinthCell{ (value_t)line[i], rowIndex, columnIndex++ });
    rowIndex++;
  }

  fin.close();
}

field_t LabyrinthField::getField() const {
  return this->field_;
}

LabyrinthCell& LabyrinthField::operator()(const row_t& row, const column_t& column) {
  for (auto& cell : this->field_)
    if ((cell.getRow() == row) && (cell.getColumn() == column))
      return cell;
}

void LabyrinthField::setCellValue(const row_t& row, const column_t& column, const value_t& value) {
  for (auto& cell : this->field_)
    if ((cell.getRow() == row) && (cell.getColumn() == column))
      cell = value;
}

void LabyrinthField::setCellType(const row_t& row, const column_t& column, const CellType& cellType) {
  for (auto& cell : this->field_)
    if ((cell.getRow() == row) && (cell.getColumn() == column))
      cell.setCellType(cellType);
}

bool LabyrinthField::isCellExist(const row_t& row, const column_t& column) const {
  for (auto& cell : this->field_)
    if ((cell.getRow() == row) && (cell.getColumn() == column))
      return true;
  return false;
}
