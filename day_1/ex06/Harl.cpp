#include "Harl.hpp"

void Harl::debug(void) {
  std::cout << "[ DEBUG ]\n";
  std::cout << "I love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-specialketchup burger. I "
               "really do!\n";
}

void Harl::info(void) {
  std::cout << "[ INFO ]\n";
  std::cout << "I cannot believe adding extra bacon costs more money. You "
               "didn't put enough bacon in my burger! If you did, I wouldn't "
               "be asking for more!\n";
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]\n";
  std::cout << "I think I deserve to have some extra bacon for free. I've been "
               "coming for years whereas you started working here since last "
               "month.\n";
}

void Harl::error(void) {
  std::cout << "[ ERROR ]\n";
  std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

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
    std::cout << "\n";
    /* fall through */
  case 1:
    info();
    std::cout << "\n";
    /* fall through */
  case 2:
    warning();
    std::cout << "\n";
    /* fall through */
  case 3:
    error();
    break;
  default:
    std::cout << "[ Probably complaining about insignificant problems ]\n";
  }
}
