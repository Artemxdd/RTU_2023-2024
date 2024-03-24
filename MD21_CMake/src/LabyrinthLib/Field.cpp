#include "Field.h"

Field::Field(const file_path_t& filePath) {
  std::ifstream fin{ filePath };
  if (!fin.is_open()) throw std::exception{ "LabyrinthFieldWithoutHalts: File is not opened!" };

  std::string line{};
  cell_row_t rowIndex{ 0 };
  cell_column_t columnIndex{};
  while (getline(fin, line)) {
    columnIndex = 0;
    for (size_t i{ 0 }; i < line.size(); i++)
      this->field_.push_back(Cell{ (cell_value_t)line[i], rowIndex, columnIndex++ });
    rowIndex++;
  }
  defineStart();
  defineFinish();

  fin.close();
}

field_t Field::getField() const {
  return this->field_;
}

Cell& Field::operator()(const cell_row_t& row, const cell_column_t& column) {
  for (Cell& cell : this->field_)
    if ((cell.getRow() == row) && (cell.getColumn() == column))
      return cell;
}

void Field::operator=(const file_path_t& filePath) {
  std::ifstream fin{ filePath };
  if (!fin.is_open()) throw std::exception{ "LabyrinthFieldWithoutHalts: File is not opened!" };

  std::string line{};
  cell_row_t rowIndex{ 0 };
  cell_column_t columnIndex{};
  this->field_.clear();
  while (getline(fin, line)) {
    columnIndex = 0;
    for (size_t i{ 0 }; i < line.size(); i++)
      this->field_.push_back(Cell{ (cell_value_t)line[i], rowIndex, columnIndex++ });
    rowIndex++;
  }
  defineStart();
  defineFinish();

  fin.close();
}

const Cell* Field::getStart() const {
  return this->start_;
}

const Cell* Field::getFinish() const {
  return this->finish_;
}

size_t Field::countSteps() const {
  size_t stepsNumber{ 0 };
  for (auto& cell : this->field_)
    if (cell.getType() == cell_type_t::TRACE)
      stepsNumber++;
  return stepsNumber;
}

bool Field::isCellExist(const cell_row_t& row, const cell_column_t& column) const {
  for (auto& cell : this->field_)
    if ((cell.getRow() == row) && (cell.getColumn() == column))
      return true;
  return false;
}

bool Field::isFirstStep() const {
  for (auto& cell : this->field_)
    if (cell.getType() == cell_type_t::TRACE)
      return false;
  return true;
}

void Field::defineStart() {
  for (auto& cell : this->field_)
    if (cell.getType() == cell_type_t::START)
      this->start_ = &cell;
}

void Field::defineFinish() {
  for (auto& cell : this->field_)
    if (cell.getType() == cell_type_t::FINISH)
      this->finish_ = &cell;
}
