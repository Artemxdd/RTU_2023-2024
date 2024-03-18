#include "LabyrinthSolver.h"

template<class T>
LabyrinthSolver<T>::LabyrinthSolver(const T& labyrinthField) {
	this->labyrinthField_ = labyrinthField;
}

template<class T>
std::vector<T> LabyrinthSolver<T>::getRoutes() const {
	return this->labyrinthRoutes_;
}

template<class T>
void LabyrinthSolver<T>::findRoutes() {
	//findRoutes(T, );
}

template<class T>
void LabyrinthSolver<T>::findRoutes(T field, row_t row, column_t, size_t haltsNumber) {
	CellType cellType{ field(row, column).getCellType() };
		//LabyrinthPrinter printer{ field };
		//printer.print();
	
	if (cellType == CellType::HALT) 
		haltsNumber--;
	if ((cellType == CellType::FINISH) && (haltsNumber == 0)) {
		this->fieldWithHalts_.push_back(field);
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

//fields_without_halts_t LabyrinthSolver::getFieldsWithoutHalts() const {
//	return this->fieldsWithoutHalts_;
//}
//
//fields_with_halts_t LabyrinthSolver::getFieldsWithHalts() const {
//	return this->fieldWithHalts_;
//}
//
//void LabyrinthSolver::findRoutesWithoutHalts(LabyrinthFieldWithoutHalts field, row_t row, column_t column) {
//	CellType cellType{ field(row, column).getCellType() };
//
//	if (cellType == CellType::FINISH) {
//		this->fieldsWithoutHalts_.push_back(field);
//		return;
//	}
//	if ((cellType == CellType::BARRIER) || (cellType == CellType::TRACE))
//		return;
//
//	if (cellType != CellType::START) {
//		field.setCellValue(row, column, '*');
//		field.setCellType(row, column, CellType::TRACE);
//	}
//	
//	if (field.isCellExist(row - 1, column))
//		findRoutesWithoutHalts(field, row - 1, column);
//	if (field.isCellExist(row, column + 1))
//		findRoutesWithoutHalts(field, row, column + 1);
//	if (field.isCellExist(row + 1, column))
//		findRoutesWithoutHalts(field, row + 1, column);
//	if (field.isCellExist(row, column - 1))
//		findRoutesWithoutHalts(field, row, column - 1);
//}
//
//void LabyrinthSolver::findRoutesWithHalts(LabyrinthFieldWithHalts field, row_t row, column_t column, 
//	size_t haltsNumber) {
//	CellType cellType{ field(row, column).getCellType() };
//	//LabyrinthPrinter printer{ field };
//	//printer.print();
//
//	if (cellType == CellType::HALT) 
//		haltsNumber--;
//	if ((cellType == CellType::FINISH) && (haltsNumber == 0)) {
//		this->fieldWithHalts_.push_back(field);
//		return;
//	}
//	if (cellType == CellType::FINISH) return;
//	if ((cellType == CellType::BARRIER) || (cellType == CellType::TRACE))
//		return;
//
//	if ((cellType != CellType::START) && (cellType != CellType::HALT)) {
//		field.setCellValue(row, column, '*');
//		field.setCellType(row, column, CellType::TRACE);
//	}
//
//	if (field.isCellExist(row - 1, column))
//		findRoutesWithHalts(field, row - 1, column, haltsNumber);
//	if (field.isCellExist(row, column + 1))
//		findRoutesWithHalts(field, row, column + 1, haltsNumber);
//	if (field.isCellExist(row + 1, column))
//		findRoutesWithHalts(field, row + 1, column, haltsNumber);
//	if (field.isCellExist(row, column - 1))
//		findRoutesWithHalts(field, row, column - 1, haltsNumber);
//}
