#include <iostream>
#include "LabyrinthLib/LabyrinthSolver.h"
#include "Labyrinthlib/LabyrinthPrinter.h"
#include "boost/program_options.hpp"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
  po::options_description options("Options");
  options.add_options()
    ("help", "help message")
    ("p", po::value<std::string>(), "path to labyrinth file")
    ("H", "labyrinth with halts (labyrinth type)")
    ("h", "labyrinth without halts (labyrinth type)")
    ("a", "all routes (route type)")
    ("s", "shortest route (route type)");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, options), vm);
  po::notify(vm);

  if (vm.count("help")) {
    std::cout << options << "\n";
    return 0;
  }

  if (vm.count("p")) {
    file_path_t labyrinthPath = vm["p"].as<std::string>();
    LabyrinthSolver labyrinthSolver;

    if (vm.count("H")) {  // labyrinth with halts
      if (vm.count("a")) {  // all routes 
        LabyrinthFieldWithHalts field{ labyrinthPath };
        labyrinthSolver.findRoutesWithHalts(field);
        for (LabyrinthFieldWithHalts& field : labyrinthSolver.getFieldsWithHalts()) {
          LabyrinthPrinter printer{ field };
          printer.print();
        }
      }
      else if (vm.count("s")) { // shortest route
        LabyrinthFieldWithHalts field{ labyrinthPath };
        labyrinthSolver.findRoutesWithHalts(field);
        LabyrinthFieldWithHalts shortestField{ labyrinthSolver
          .getFieldWithHaltsWithShortestTrace() };
        LabyrinthPrinter printer{ shortestField };
        printer.print();
      }
    }
    else if (vm.count("h")) { // labyrinth without halts
      if (vm.count("a")) {  // all routes 
        LabyrinthFieldWithoutHalts field{ labyrinthPath };
        labyrinthSolver.findRoutesWithoutHalts(field);
        for (LabyrinthFieldWithoutHalts& field : labyrinthSolver.getFieldsWithoutHalts()) {
          LabyrinthPrinter printer{ field };
          printer.print();
        }
      }
      else if (vm.count("s")) { // shortest route
        LabyrinthFieldWithoutHalts field{ labyrinthPath };
        labyrinthSolver.findRoutesWithoutHalts(field);
        LabyrinthFieldWithoutHalts shortestField{ labyrinthSolver
          .getFieldWithoutHaltsWithShortestTrace() };
        LabyrinthPrinter printer{ shortestField };
        printer.print();
      }
    }
  }
}