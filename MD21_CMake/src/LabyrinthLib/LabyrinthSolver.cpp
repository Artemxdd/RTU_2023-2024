#include "LabyrinthSolver.h"

fields_without_halts_t LabyrinthSolver::getFieldsWithoutHalts() const {
	return this->fieldsWithoutHalts_;
}

fields_with_halts_t LabyrinthSolver::getFieldsWithHalts() const {
	return this->fieldsWithHalts_;
}

LabyrinthFieldWithoutHalts LabyrinthSolver::getFieldWithoutHaltsWithShortestTrace() const {
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

LabyrinthFieldWithHalts LabyrinthSolver::getFieldWithHaltsWithShortestTrace() const {
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

void LabyrinthSolver::findRoutesWithoutHalts(const LabyrinthFieldWithoutHalts& field) {
	this->fieldsWithoutHalts_.clear();
	findRoutesWithoutHalts(field, field.getStart()->getRow(), field.getStart()->getColumn());
}

void LabyrinthSolver::findRoutesWithHalts(const LabyrinthFieldWithHalts& field) {
	this->fieldsWithoutHalts_.clear();
	findRoutesWithHalts(field, field.getStart()->getRow(), field.getStart()->getColumn(), 
		field.getHaltsNumber());
}

void LabyrinthSolver::findRoutesWithoutHalts(LabyrinthFieldWithoutHalts field, row_t row, column_t column) {
	CellType cellType{ field(row, column).getCellType() };

	if ((cellType == CellType::START) && (!field.isFirstStep()))
		return;
	if (cellType == CellType::FINISH) {
		this->fieldsWithoutHalts_.push_back(field);
		return;
	}
	if ((cellType == CellType::BARRIER) || (cellType == CellType::TRACE))
		return;

	if (cellType != CellType::START) {
		field.setCellValue(row, column, '*');
		field.setCellType(row, column, CellType::TRACE);
	}

	//LabyrinthPrinter printer{ field };
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

void LabyrinthSolver::findRoutesWithHalts(LabyrinthFieldWithHalts field, row_t row, column_t column, 
	size_t haltsNumber) {
	CellType cellType{ field(row, column).getCellType() };
	//LabyrinthPrinter printer{ field };
	//printer.print();

	if ((cellType == CellType::START) && (!field.isFirstStep()))
		return;
	if (cellType == CellType::HALT) 
		haltsNumber--;
	if ((cellType == CellType::FINISH) && (haltsNumber == 0)) {
		this->fieldsWithHalts_.push_back(field);
		return;
	}
	if (cellType == CellType::FINISH) return;
	if ((cellType == CellType::BARRIER) || (cellType == CellType::TRACE))
		return;

	if ((cellType != CellType::START) && (cellType != CellType::HALT)) {
		field.setCellValue(row, column, '*');
		field.setCellType(row, column, CellType::TRACE);
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
