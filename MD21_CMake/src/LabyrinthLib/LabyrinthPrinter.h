#pragma once

#include <cinttypes>
#include <iostream>
#include "LabyrinthAnsiColors.cpp"
#include "LabyrinthField.h"

class LabyrinthPrinter {
public:
	LabyrinthPrinter(LabyrinthField& field);

	// Setters
	void operator=(const LabyrinthField& field);
	void setStartColor(color_t color);
	void setFinishColor(color_t color);
	void setBarrierColor(color_t color);
	void setTraceColor(color_t color);
	void setHaltColor(color_t color);

	void print() const;

private:
	LabyrinthField& field_;
	color_t start_		=		COLOR_GREEN;
	color_t finish_		=		COLOR_RED;
	color_t barrier_	=		COLOR_WHITE;
	color_t trace_		=		COLOR_BLUE;
	color_t halt_			=		COLOR_BLACK;

	void setColor(const color_t& color) const;
};

