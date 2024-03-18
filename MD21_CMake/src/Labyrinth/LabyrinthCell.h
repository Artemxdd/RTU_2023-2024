#pragma once

#include <cstdint>

typedef uint8_t value_t;
typedef uintmax_t row_t;
typedef uintmax_t column_t;

enum CellType {
	START,
	FINISH,
	EMPTY,
	BARRIER,
	TRACE,
	HALT
};

class LabyrinthCell {
public:
	LabyrinthCell(const value_t& value, const row_t& row, const column_t& column);

	// Getters
	value_t getValue() const;
	row_t getRow() const;
	column_t getColumn() const;
	CellType getCellType() const;

	// Setters
	void operator=(const value_t& value);
	void setRow(const row_t& row);
	void setColumn(const column_t& column);
	void setCellType(const CellType& cellType);

private:
	value_t value_;
	row_t row_;
	column_t column_;
	CellType cellType_;
};

