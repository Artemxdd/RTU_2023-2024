#pragma once

#include <stdint.h>

typedef uint8_t cell_value_t;
typedef uintmax_t cell_row_t;
typedef uintmax_t cell_column_t;

enum cell_type_t {
	START,
	FINISH,
	EMPTY,
	BARRIER,
	TRACE,
	HALT
};

class Cell {
public:
	Cell(const cell_value_t& value, const cell_row_t& row, const cell_column_t& column);

	// Getters
	cell_value_t getValue() const;
	cell_row_t getRow() const;
	cell_column_t getColumn() const;
	cell_type_t getType() const;

	// Setters
	void setValue(const cell_value_t& value);
	void setRow(const cell_row_t& row);
	void setColumn(const cell_column_t& column);
	void setType(const cell_type_t& cellType);

private:
	cell_value_t value_;
	cell_row_t row_;
	cell_column_t column_;
	cell_type_t type_;
};

