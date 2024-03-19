#include "LabyrinthPrinter.h"

LabyrinthPrinter::LabyrinthPrinter(LabyrinthField& field) : field_(field) {
}

void LabyrinthPrinter::operator=(const LabyrinthField& field) {
	this->field_ = field;
}

void LabyrinthPrinter::setStartColor(color_t color) {
	this->start_ = color;
}

void LabyrinthPrinter::setFinishColor(color_t color) {
	this->finish_ = color;
}

void LabyrinthPrinter::setBarrierColor(color_t color) {
	this->barrier_ = color;
}

void LabyrinthPrinter::setTraceColor(color_t color) {
	this->trace_ = color;
}

void LabyrinthPrinter::setHaltColor(color_t color) {
	this->halt_ = color;
}

void LabyrinthPrinter::print() const {
	int row{ 0 };
	for (const LabyrinthCell& cell : this->field_.getField()) {
		if (cell.getRow() != row) {
			std::cout << "\n";
			row++;
		}

		CellType cellType{ cell.getCellType() };
		if (cellType == CellType::START) 
			setColor(COLOR_RED);
		else if (cellType == CellType::FINISH) 
			setColor(COLOR_GREEN);
		else if (cellType == CellType::BARRIER) 
			setColor(COLOR_BLUE);
		else 
			setColor(COLOR_WHITE);
		std::cout << cell.getValue();
		setColor(COLOR_BLACK);
	}
	setColor(COLOR_WHITE);
	std::cout << "\n----------------------------------------\n";
}

void LabyrinthPrinter::setColor(const color_t& color) const {
	std::cout << "\x1b[" << color << "m";
}
