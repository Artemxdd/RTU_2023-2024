#include "Solver.h"

fields_without_halts_t Solver::getFieldsWithoutHalts() const {
	return this->fieldsWithoutHalts_;
}

fields_with_halts_t Solver::getFieldsWithHalts() const {
	return this->fieldsWithHalts_;
}

Field Solver::getFieldWithoutHaltsWithShortestTrace() const {
	size_t stepsNumber { INT_MAX };
	size_t shortestTraceId{ 0 };
	for (size_t i{ 0 }; i < this->fieldsWithoutHalts_.size(); i++) {
		size_t tmpStepsNumber{ this->fieldsWithoutHalts_[i].countSteps() };
		if (tmpStepsNumber < stepsNumber) {
			stepsNumber = tmpStepsNumber;
			shortestTraceId = i;
		}
	}
	return this->fieldsWithoutHalts_[shortestTraceId];
}

FieldWithHalts Solver::getFieldWithHaltsWithShortestTrace() const {
	size_t stepsNumber{ INT_MAX };
	size_t shortestTraceId{ 0 };
	for (size_t i{ 0 }; i < this->fieldsWithHalts_.size(); i++) {
		size_t tmpStepsNumber{ this->fieldsWithHalts_[i].countSteps() };
		if (tmpStepsNumber < stepsNumber) {
			stepsNumber = tmpStepsNumber;
			shortestTraceId = i;
		}
	}
	return this->fieldsWithHalts_[shortestTraceId];
}

void Solver::findRoutesWithoutHalts(const Field& field) {
	this->fieldsWithoutHalts_.clear();
	findRoutesWithoutHalts(field, field.getStart()->getRow(), field.getStart()->getColumn());
}

void Solver::findRoutesWithHalts(const FieldWithHalts& field) {
	this->fieldsWithoutHalts_.clear();
	findRoutesWithHalts(field, field.getStart()->getRow(), field.getStart()->getColumn(), 
		field.getHaltsNumber());
}

void Solver::findRoutesWithoutHalts(Field field, cell_row_t row, cell_column_t column) {
	cell_type_t cellType{ field(row, column).getType() };

	if ((cellType == cell_type_t::START) && (!field.isFirstStep()))
		return;
	if (cellType == cell_type_t::FINISH) {
		this->fieldsWithoutHalts_.push_back(field);
		return;
	}
	if ((cellType == cell_type_t::BARRIER) || (cellType == cell_type_t::TRACE))
		return;

	if (cellType != cell_type_t::START) {
		field(row, column).setValue('*');
		field(row, column).setType(cell_type_t::TRACE);
	}

	//Printer printer{ field };
	//printer.print();
	
	if (field.isCellExist(row - 1, column))
		findRoutesWithoutHalts(field, row - 1, column);
	if (field.isCellExist(row, column + 1))
		findRoutesWithoutHalts(field, row, column + 1);
	if (field.isCellExist(row + 1, column))
		findRoutesWithoutHalts(field, row + 1, column);
	if (field.isCellExist(row, column - 1))
		findRoutesWithoutHalts(field, row, column - 1);
}

void Solver::findRoutesWithHalts(FieldWithHalts field, cell_row_t row, cell_column_t column, 
	size_t haltsNumber) {
	cell_type_t cellType{ field(row, column).getType() };
	//Printer printer{ field };
	//printer.print();

	if ((cellType == cell_type_t::START) && (!field.isFirstStep()))
		return;
	if (cellType == cell_type_t::HALT)
		haltsNumber--;
	if ((cellType == cell_type_t::FINISH) && (haltsNumber == 0)) {
		this->fieldsWithHalts_.push_back(field);
		return;
	}
	if (cellType == cell_type_t::FINISH) return;
	if ((cellType == cell_type_t::BARRIER) || (cellType == cell_type_t::TRACE))
		return;

	if ((cellType != cell_type_t::START) && (cellType != cell_type_t::HALT)) {
		field(row, column).setValue('*');
		field(row, column).setType(cell_type_t::TRACE);
	}

	if (field.isCellExist(row - 1, column))
		findRoutesWithHalts(field, row - 1, column, haltsNumber);
	if (field.isCellExist(row, column + 1))
		findRoutesWithHalts(field, row, column + 1, haltsNumber);
	if (field.isCellExist(row + 1, column))
		findRoutesWithHalts(field, row + 1, column, haltsNumber);
	if (field.isCellExist(row, column - 1))
		findRoutesWithHalts(field, row, column - 1, haltsNumber);
}
