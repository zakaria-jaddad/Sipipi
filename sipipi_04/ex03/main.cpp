#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
  std::cout << "=== Basic Test ===" << std::endl;
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter *me = new Character("me");
  AMateria *tmp;
  tmp = src->createMateria("ice");
  if (tmp == NULL)
    std::cout << "Failed to create 'ice' materia" << std::endl;
  else
    me->equip(tmp);
  tmp = src->createMateria("cure");
  if (tmp == NULL)
    std::cout << "Failed to create 'cure' materia" << std::endl;
  else
    me->equip(tmp);
  ICharacter *bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;

  ICharacter *original = new Character("original");
  AMateria *ice = new Ice();
  original->equip(ice);

  ICharacter *copy = new Character(*(Character *)original);

  std::cout << "================================" << std::endl;
  original->use(0, *original);

  copy->use(0, *copy);

  delete original;

  copy->use(0, *copy);
  delete copy;

  return 0;
}
