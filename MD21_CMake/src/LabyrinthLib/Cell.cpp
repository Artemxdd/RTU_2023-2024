#include "Cell.h"

Cell::Cell(const cell_value_t& value, const cell_row_t& row, const cell_column_t& column) {
	this->value_ = value;
	this->row_ = row;
	this->column_ = column;
	if (value == 'S') this->type_ = cell_type_t::START;
	else if (value == 'F') this->type_ = cell_type_t::FINISH;
	else if (value == 'H') this->type_ = cell_type_t::HALT;
	else if (value == ' ') this->type_ = cell_type_t::EMPTY;
	else if (value == '#') this->type_ = cell_type_t::BARRIER;
	else this->type_ = cell_type_t::TRACE;
}

cell_value_t Cell::getValue() const {
	return this->value_;
}

cell_row_t Cell::getRow() const {
	return this->row_;
}

cell_column_t Cell::getColumn() const {
	return this->column_;
}

cell_type_t Cell::getType() const {
	return this->type_;
}

void Cell::setValue(const cell_value_t& value) {
	this->value_ = value;
}

void Cell::setRow(const cell_row_t& row) {
	this->row_ = row;
}

void Cell::setColumn(const cell_column_t& column) {
	this->column_ = column;
}

void Cell::setType(const cell_type_t& cellType) {
	this->type_ = cellType;
}
