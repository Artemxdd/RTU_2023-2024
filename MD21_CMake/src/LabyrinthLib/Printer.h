#pragma once

#include <iostream>
#include "AnsiColors.h"
#include "Field.h"

class Printer {
public:
	Printer(Field& field);

	// Setters
	void operator=(const Field& field);
	void setStartColor(color_t color);
	void setFinishColor(color_t color);
	void setBarrierColor(color_t color);
	void setTraceColor(color_t color);
	void setHaltColor(color_t color);

	void print() const;

	static void setConsoleColor(const color_t& color);

private:
	Field& field_;
	color_t start_		=		ANSI_GREEN;
	color_t finish_		=		ANSI_RED;
	color_t barrier_	=		ANSI_LIGHT_GRAY;
	color_t trace_		=		ANSI_BLUE;
	color_t halt_			=		ANSI_LIGHT_MAGENTA;
};

