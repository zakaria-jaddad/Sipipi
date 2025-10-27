#include "Zombie.hpp"

int main() {
  int N = 5;
  std::string hordeName = "TestHorde";
  Zombie *horde = zombieHorde(N, hordeName);

  if (horde == NULL) {
    std::cerr << "Failed to create horde." << std::endl;
    return 1;
  }

  for (int i = 0; i < N; ++i) {
    horde[i].announce();
  }

  delete[] horde;

  Zombie *emptyHorde = zombieHorde(0, "Nobody");
  if (emptyHorde == NULL) {
    std::cout << "Empty horde handled correctly." << std::endl;
  }

  Zombie *singleZombie = zombieHorde(1, "SingleZombie");
  if (singleZombie) {
    singleZombie[0].announce();
    delete[] singleZombie;
  }

  return 0;
}
