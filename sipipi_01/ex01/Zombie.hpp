#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
public:
  void announce(void);
  Zombie(void);
  Zombie(std::string name);
  ~Zombie(void);

private:
  std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif
