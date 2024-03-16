#include "LabyrinthCell.h"

LabyrinthCell::LabyrinthCell(const value_t& value, const row_t& row, const column_t& column) {
	this->value_ = value;
	this->row_ = row;
	this->column_ = column;
	if (value == 'S') this->cellType_ = CellType::START;
	else if (value == 'F') this->cellType_ = CellType::FINISH;
	else if (value == ' ') this->cellType_ = CellType::EMPTY;
	else if (value == '#') this->cellType_ = CellType::BARRIER;
	else this->cellType_ = CellType::TRACE;
}

value_t LabyrinthCell::getValue() const {
	return this->value_;
}

row_t LabyrinthCell::getRow() const {
	return this->row_;
}

column_t LabyrinthCell::getColumn() const {
	return this->column_;
}

CellType LabyrinthCell::getCellType() const {
	return this->cellType_;
}

void LabyrinthCell::operator=(const value_t& value) {
	this->value_ = value;
}

void LabyrinthCell::setRow(const row_t& row) {
	this->row_ = row;
}

void LabyrinthCell::setColumn(const column_t& column) {
	this->column_ = column;
}

void LabyrinthCell::setCellType(const CellType& cellType) {
	this->cellType_ = cellType;
}
