#include "LabyrinthPrinter.h"

LabyrinthPrinter::LabyrinthPrinter(const LabyrinthField& field, const color_t& start, const color_t& finish,
	const color_t& barrier, const color_t& trace) {
	this->field_ = field;
	this->start_ = start;
	this->finish_ = finish;
	this->barrier_ = barrier;
	this->trace_ = trace;
}

void LabyrinthPrinter::operator=(const LabyrinthField& field) {
	this->field_ = field;
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
	std::cout << "\n----------------------------------------\n";
}

void LabyrinthPrinter::setColor(const color_t& color) const {
	std::cout << "\x1b[" << color << "m";
}
