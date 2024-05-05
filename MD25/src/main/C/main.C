#include "../h/Line.h"
#include "../h/OptionsHandler.h"

int main(int argc, char* argv[]) {
  OptionsHandler optionsHandler{ argc, argv };
  optionsHandler.execute();
} 
