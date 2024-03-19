#include <iostream>
#include "LabyrinthLib/LabyrinthSolver.h"
#include "Labyrinthlib/LabyrinthPrinter.h"

int main(int argc, char* argv[]) {
  file_path_t labyrinthPath{ "" };

  if (argc > 1) {
    labyrinthPath = argv[1];
    LabyrinthSolver labyrinth;

    if (argc == 2) {
      LabyrinthFieldWithoutHalts field{ labyrinthPath };
      labyrinth.findRoutesWithoutHalts(field);
      for (LabyrinthFieldWithoutHalts& field : labyrinth.getFieldsWithoutHalts()) {
        LabyrinthPrinter printer{ field };
        printer.print();
      }
    }
    else if (argc == 3) {
      if ((argv[2][0] == '-') && (argv[2][1] == 'h')) {
        LabyrinthFieldWithHalts field{ labyrinthPath };
        labyrinth.findRoutesWithHalts(field);
        for (LabyrinthFieldWithHalts& field : labyrinth.getFieldsWithHalts()) {
          LabyrinthPrinter printer{ field };
          printer.print();
        }
      }
      else if ((argv[2][0] == '-') && (argv[2][1] == 's')) {
        LabyrinthFieldWithoutHalts field{ labyrinthPath };
        labyrinth.findRoutesWithoutHalts(field);
        LabyrinthFieldWithoutHalts shortestField{ labyrinth.getFieldWithoutHaltsWithShortestTrace() };
        LabyrinthPrinter printer{ shortestField };
        printer.print();
      }
    }
    else if (argc == 4) {
      if (((argv[2][0] == '-') && (argv[2][1] == 'h')) && ((argv[3][0] == '-') && (argv[3][1] == 's'))) {
        LabyrinthFieldWithHalts field{ labyrinthPath };
        labyrinth.findRoutesWithHalts(field);
        LabyrinthFieldWithHalts shortestField{ labyrinth.getFieldWithHaltsWithShortestTrace() };
        LabyrinthPrinter printer{ shortestField };
        printer.print();
      }
    }
  }
}