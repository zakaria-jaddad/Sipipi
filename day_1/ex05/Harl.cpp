#include "Harl.hpp"

//  private function
void Harl::debug(void) { std::cout << "DEBUG\n"; }

void Harl::info(void) { std::cout << "INFO\n"; }

void Harl::warning(void) { std::cout << "WARNING\n"; }

void Harl::error(void) { std::cout << "ERROR\n"; }

// public function
void Harl::complain(std::string level) {

  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  void (Harl::*funcs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                  &Harl::error};

  for (int i = 0; i < 4; i++) {
    if (levels[i] == level) {
      (this->*funcs[i])();
      return;
    }
  }
}
