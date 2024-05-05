#include <boost/program_options.hpp>
#include <iostream>
#include "../h/Encryptor.h"
#include "../h/Decryptor.h"
#include "../h/PasswordsGenerator.h"
#include "../../FilesHandlingLib/files_handling.h"

namespace po = boost::program_options;

class OptionsHandler {
public:
  OptionsHandler(int argc, char* argv[]);
  void execute() const;
private:
  po::options_description optionsDescription_;
  po::variables_map variablesMap_;

  bool isNecessaryOptionsProvided() const;
  void passwordBruteForce(const Reader& reader, Decryptor& decryptor) const;
};