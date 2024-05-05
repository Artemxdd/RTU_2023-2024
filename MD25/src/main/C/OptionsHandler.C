#include "../h/OptionsHandler.h"

OptionsHandler::OptionsHandler(int argc, char* argv[]) {
  optionsDescription_.add_options()
    ("help", "help message")
    ("e", "encrypt")
    ("d", "decrypt")
    ("t", po::value<std::string>(), "text from console")
    ("f", po::value<std::string>(), "file")
    ("p", po::value<std::string>(), "password")
    ("b", "password brute force [a-z] and size <= 10 chars")
    ("s", "save to file")
    ("c", "console out");
  
  po::store(po::parse_command_line(argc, argv, optionsDescription_), variablesMap_);
  po::notify(variablesMap_);
}

void OptionsHandler::execute() const {
  if (variablesMap_.count("help")) {
    std::cout << "Usage:\n" << "\tMD25Exec --e/--d --t/--f --p --s/--c" << "\n";
    std::cout << optionsDescription_ << "\n";
  }

  /*Temporarily*/
  if (variablesMap_.count("d") && variablesMap_.count("f") && variablesMap_.count("b")) {
    Reader reader{};
    reader.readFile(variablesMap_["f"].as<std::string>());
    Decryptor decryptor{};
    passwordBruteForce(reader, decryptor);
  }
  /*Temporarily*/

  if (!isNecessaryOptionsProvided())
    return;

  if (variablesMap_.count("e")) {
    Encryptor encryptor{};

    if (variablesMap_.count("t")) {
      encryptor.encrypt(variablesMap_["t"].as<std::string>());
      
      if (variablesMap_.count("s")) {
        Saver saver{ variablesMap_["s"].as<std::string>() };
        saver.overrideFile(encryptor.getEncryptedTxt());
      }
      else if (variablesMap_.count("c")) {
        std::cout << encryptor.getEncryptedTxt() << "\n";
      }

    }
    else if (variablesMap_.count("f")) {
      Reader reader{};
      reader.readFile(variablesMap_["f"].as<std::string>());
      for (const std::string& str : reader.getText())
        encryptor.encrypt(str);

      if (variablesMap_.count("s")) {
        Saver saver{ variablesMap_["s"].as<std::string>() };
        saver.overrideFile(encryptor.getEncryptedTxt());
      }
      else if (variablesMap_.count("c")) {
        std::cout << encryptor.getEncryptedTxt() << "\n";
      }

    }

  }
  else if (variablesMap_.count("d")) {
    Decryptor decryptor{};

    if (variablesMap_.count("t")) {
      decryptor.decrypt(variablesMap_["t"].as<std::string>(), variablesMap_["p"].as<std::string>());

      if (variablesMap_.count("s")) {
        Saver saver{ variablesMap_["s"].as<std::string>() };
        saver.overrideFile(decryptor.getDecryptedTxt());
      }
      else if (variablesMap_.count("c")) {
        std::cout << decryptor.getDecryptedTxt() << "\n";
      }

    }
    else if (variablesMap_.count("f")) {
      Reader reader{};
      reader.readFile(variablesMap_["f"].as<std::string>());
      for (const std::string& str : reader.getText())
        decryptor.decrypt(str, variablesMap_["p"].as<std::string>());

      if (variablesMap_.count("s")) {
        Saver saver{ variablesMap_["s"].as<std::string>() };
        saver.overrideFile(decryptor.getDecryptedTxt());
      }
      else if (variablesMap_.count("c")) {
        std::cout << decryptor.getDecryptedTxt() << "\n";
      }
      
    }

  }
}

bool OptionsHandler::isNecessaryOptionsProvided() const {
  if (!variablesMap_.count("e") && !variablesMap_.count("d")) 
    return false;
  if (!variablesMap_.count("t") && !variablesMap_.count("f")) 
    return false;
  if (!variablesMap_.count("p") && !variablesMap_.count("b"))
    return false;
  if (!variablesMap_.count("s") && !variablesMap_.count("c")) 
    return false;

  return true;
}

void OptionsHandler::passwordBruteForce(const Reader& reader, Decryptor& decryptor) const {
  PasswordsGenerator generator{};
  std::set<std::string> passwords{};
  std::vector<std::string> text{ reader.getText() };

  // 1 letter passwords
  passwords = generator.getPasswords();
  generator.generate1Letter();

  for (const std::string& password : passwords) {
    for (size_t i{ 0 }; i < text.size(); i++)
      decryptor.decrypt(text[i], password);
    if (decryptor.isAllTextGraphical()) {
      std::cout << password << "\n" << decryptor.getDecryptedTxt() << "\n\n\n-------------------------------\n\n\n";
    }
  }

  std::cout << "Done\n";
}