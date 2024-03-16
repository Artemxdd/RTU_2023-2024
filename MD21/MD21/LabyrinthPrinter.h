#pragma once

#include <cinttypes>
#include <iostream>
#include "LabyrinthField.h"

typedef int32_t color_t;

const color_t COLOR_BLACK{ 0 };
const color_t COLOR_RED{ 31 };
const color_t COLOR_GREEN{ 32 };
const color_t COLOR_BLUE{ 34 };
const color_t COLOR_WHITE{ 37 };

class LabyrinthPrinter {
public:
	LabyrinthPrinter(const LabyrinthField& field, const color_t& start, const color_t& finish,
		const color_t& barrier, const color_t& track);

	void operator=(const LabyrinthField& field);	// Setter

	void print() const;

private:
	LabyrinthField field_;
	color_t start_;
	color_t finish_;
	color_t barrier_;
	color_t trace_;

	void setColor(const color_t& color) const;
};

