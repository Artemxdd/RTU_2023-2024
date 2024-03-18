#include <iostream>
#include "LabyrinthSolver.h"
#include "LabyrinthPrinter.h"

int main() {
  file_path_t labyrinthPath{ "C:\\Projects\\VisualStudio\\RTU(2023-2024)\\MD21\\labyrinth1_with_halts.txt" };
  LabyrinthSolver labyrinth{ labyrinthPath };
  LabyrinthFieldWithHalts fieldWithHalts{ labyrinthPath };
  row_t row{ fieldWithHalts.getStart()->getRow() };
  column_t column{ fieldWithHalts.getStart()->getColumn() };
  labyrinth.findRoutesWithHalts(fieldWithHalts, row, column, 2);
  for (LabyrinthFieldWithHalts& field : labyrinth.getFieldsWithHalts()) {
    LabyrinthPrinter printer{ field };
    printer.print();
  }
  LabyrinthFieldWithoutHalts withoutHalts{ labyrinthPath };
}