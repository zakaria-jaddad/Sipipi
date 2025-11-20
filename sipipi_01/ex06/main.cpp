#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {

  if (argc != 2)
    return 1;

  Harl h;
  h.filter(argv[1]);
  return 0;
}
