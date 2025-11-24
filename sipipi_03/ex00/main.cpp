#include "ClapTrap.hpp"

int main(void) {

  ClapTrap mbarek("Mbarek");
  ClapTrap lmaati("Lmaati");

  mbarek.attack("Lmaati");
  lmaati.takeDamage(2);

  lmaati.attack("Mbarek");
  mbarek.takeDamage(3);

  lmaati.attack("Mbarek");
  mbarek.takeDamage(5);

  for (int i = 0; i < 10; i++) {
    mbarek.attack("Lmaati");
  }
  mbarek.beRepaired(5);
  mbarek.attack("Lmaati");

  return 0;
}
