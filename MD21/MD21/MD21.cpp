#include <iostream>
#include "LabyrinthSolver.h"
#include "LabyrinthPrinter.h"

int main() {
  file_path_t labyrinthPath{ "C:\\Projects\\VisualStudio\\RTU(2023-2024)\\MD21\\labyrinth3.txt" };
  LabyrinthSolver labyrinth{ labyrinth };
  labyrinth.findRoutes(LabyrinthField{ labyrinthPath }, 1, 21);
  for (const LabyrinthField& field : labyrinth.getFieldsWithRoutes()) {
    LabyrinthPrinter printer{ field, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_WHITE };
    printer.print();
  }
}