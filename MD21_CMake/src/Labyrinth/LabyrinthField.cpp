#include "LabyrinthField.h"

LabyrinthField::LabyrinthField() {
  this->start_ = nullptr;
  this->finish_ = nullptr;
  this->type_ = FieldType::UNDEFINED;
}

LabyrinthField::LabyrinthField(const file_path_t& filePath) {
  std::ifstream fin{ filePath };
  if (!fin.is_open()) throw std::exception{ "LabyrinthFieldWithoutHalts: File is not opened!" };

  std::string line{};
  row_t rowIndex{ 0 };
  column_t columnIndex{};
  while (getline(fin, line)) {
    columnIndex = 0;
    for (size_t i{ 0 }; i < line.size(); i++)
      this->field_.push_back(LabyrinthCell{ (value_t)line[i], rowIndex, columnIndex++ });
    rowIndex++;
  }
  defineStart();
  defineFinish();
  //defineType();

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

const LabyrinthCell* LabyrinthField::getStart() const {
  return this->start_;
}

const LabyrinthCell* LabyrinthField::getFinish() const {
  return this->finish_;
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

void LabyrinthField::defineStart() {
  for (auto& cell : this->field_)
    if (cell.getCellType() == CellType::START)
      this->start_ = &cell;
}

void LabyrinthField::defineFinish() {
  for (auto& cell : this->field_)
    if (cell.getCellType() == CellType::FINISH)
      this->finish_ = &cell;
}
