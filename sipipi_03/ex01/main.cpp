#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

  ClapTrap mbarek("Mbarek");
  ScavTrap lmaati("Lmaati");

  lmaati.attack("Mbarek");
  mbarek.takeDamage(lmaati.getDamage());

  ScavTrap billal("Billal");

  for (int i = 0; i < 4; i++) {
    billal.attack("Mbarek");
    lmaati.takeDamage(billal.getDamage());
  }

  lmaati.beRepaired(80);

  return 0;
}
