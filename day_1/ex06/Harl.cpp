#include "Harl.hpp"

//  private function
void Harl::debug(void) { std::cout << "DEBUG\n"; }

void Harl::info(void) { std::cout << "INFO\n"; }

void Harl::warning(void) { std::cout << "WARNING\n"; }

void Harl::error(void) { std::cout << "ERROR\n"; }

// public function
void Harl::complain(std::string level) {

  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  void (Harl::*harlFunctions[])(void) = {&Harl::debug, &Harl::info,
                                         &Harl::warning, &Harl::error};

  for (int i = 0; i < 4; i++) {
    if (levels[i] == level) {
      (this->*harlFunctions[i])();
      return;
    }
  }
}

void Harl::filter(std::string level) {
  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  int i = 0;
  while (i < 4 && level != levels[i])
    i++;
  switch (i) {
  case 0:
    debug();
    break;
  case 1:
    info();
    break;
  case 2:
    warning();
    break;
  case 3:
    error();
    break;
  default:
    std::cout << "[ Probably complaining about insignificant problems ]\n";
  }
}
