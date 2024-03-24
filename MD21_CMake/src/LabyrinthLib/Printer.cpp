#include "Printer.h"

Printer::Printer(Field& field) : field_(field) {
}

void Printer::operator=(const Field& field) {
	this->field_ = field;
}

void Printer::setStartColor(color_t color) {
	this->start_ = color;
}

void Printer::setFinishColor(color_t color) {
	this->finish_ = color;
}

void Printer::setBarrierColor(color_t color) {
	this->barrier_ = color;
}

void Printer::setTraceColor(color_t color) {
	this->trace_ = color;
}

void Printer::setHaltColor(color_t color) {
	this->halt_ = color;
}

void Printer::print() const {
	int row{ 0 };
	for (const Cell& cell : this->field_.getField()) {
		if (cell.getRow() != row) {
			std::cout << "\n";
			row++;
		}

		cell_type_t cellType{ cell.getType() };
		if (cellType == cell_type_t::START)
			setConsoleColor(this->start_);
		else if (cellType == cell_type_t::FINISH)
			setConsoleColor(this->finish_);
		else if (cellType == cell_type_t::BARRIER)
			setConsoleColor(this->barrier_);
		else if (cellType == cell_type_t::TRACE)
			setConsoleColor(this->trace_);
		else if (cellType == cell_type_t::HALT)
			setConsoleColor(this->halt_);
		else
			setConsoleColor(ANSI_WHITE);
		std::cout << cell.getValue();
	}
	setConsoleColor(ANSI_WHITE);
	std::cout << "\n----------------------------------------\n";
}

void Printer::setConsoleColor(const color_t& color) {
	std::cout << "\x1b[" << color << "m";
}
