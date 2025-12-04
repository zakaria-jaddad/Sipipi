#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void f() {
  system("leaks main");
}

int main() {
  atexit(f);
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter *me = new Character("me");
  AMateria *tmp;
  tmp = src->createMateria("ice");
  if (tmp == NULL)
      std::cout << "Failed to create 'ice' materia" <<  std::endl;
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
  return 0;
}
