#include <iostream>
#include "LabyrinthLib/labyrinth.h"
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
    std::cout << "Usage:\n" << "\tlabyrinthExecutable.exe --p <path-to-labyrinth> --h/--H --a/--s" << "\n";
    std::cout << options << "\n";
    return 0;
  }

  if (vm.count("p")) {
    file_path_t labyrinthPath = vm["p"].as<std::string>();
    Solver labyrinthSolver;

    if (vm.count("H")) {  // labyrinth with halts
      FieldWithHalts field{ labyrinthPath };
      labyrinthSolver.findRoutesWithHalts(field);

      if (vm.count("a")) {  // all routes 
        for (FieldWithHalts& field : labyrinthSolver.getFieldsWithHalts()) {
          Printer printer{ field };
          printer.print();
        }
      }
      else if (vm.count("s")) { // shortest route
        FieldWithHalts shortestField{ labyrinthSolver
          .getFieldWithHaltsWithShortestTrace() };
        Printer printer{ shortestField };
        printer.print();
      }
    }
    else if (vm.count("h")) { // labyrinth without halts
      Field field{ labyrinthPath };
      labyrinthSolver.findRoutesWithoutHalts(field);

      if (vm.count("a")) {  // all routes 
        for (Field& field : labyrinthSolver.getFieldsWithoutHalts()) {
          Printer printer{ field };
          printer.print();
        }
      }
      else if (vm.count("s")) { // shortest route
        Field shortestField{ labyrinthSolver
          .getFieldWithoutHaltsWithShortestTrace() };
        Printer printer{ shortestField };
        printer.print();
      }
    }
  }
}