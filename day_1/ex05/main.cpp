#include "Harl.hpp"

int main(void) {
  Harl harl;

  harl.complain("NOTHING");
  harl.complain("DEBUG");
  harl.complain("INFO");
  harl.complain("WARNING");
  harl.complain("ERROR");

  return 0;
}
