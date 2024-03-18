#include <iostream>
#include "LabyrinthSolver.h"
#include "LabyrinthPrinter.h"

int main() {
  file_path_t labyrinthPath{ "C:\\Projects\\VisualStudio\\RTU(2023-2024)\\MD21\\labyrinth_small.txt" };
  LabyrinthSolver labyrinth;
  LabyrinthFieldWithHalts fieldWithHalts{ labyrinthPath };
  labyrinth.findRoutesWithHalts(fieldWithHalts);
  for (LabyrinthFieldWithHalts& field : labyrinth.getFieldsWithHalts()) {
    LabyrinthPrinter printer{ field };
    printer.print();
  }
}