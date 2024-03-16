#include "LabyrinthSolver.h"

LabyrinthSolver::LabyrinthSolver(const file_path_t& filePath) : LabyrinthField(filePath) {
}

fields_with_routes_t LabyrinthSolver::getFieldsWithRoutes() const {
	return this->fieldsWithRoutes;
}

void LabyrinthSolver::findRoutes(LabyrinthField field, row_t row, column_t column) {
	CellType cellType{ field(row, column).getCellType() };

	if (cellType == CellType::FINISH) {
		this->fieldsWithRoutes.push_back(field);
		return;
	}
	if ((cellType == CellType::BARRIER) || (cellType == CellType::TRACE))
		return;

	if (cellType != CellType::START) {
		field.setCellValue(row, column, '*');
		field.setCellType(row, column, CellType::TRACE);
	}
	
	if (field.isCellExist(row - 1, column))
		findRoutes(field, row - 1, column);
	if (field.isCellExist(row, column + 1))
		findRoutes(field, row, column + 1);
	if (field.isCellExist(row + 1, column))
		findRoutes(field, row + 1, column);
	if (field.isCellExist(row, column - 1))
		findRoutes(field, row, column - 1);
}
