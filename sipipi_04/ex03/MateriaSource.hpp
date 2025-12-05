#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private:
  AMateria *_inventory[4];

public:
  MateriaSource();
  MateriaSource(const MateriaSource &other);
  MateriaSource &operator=(const MateriaSource &other);
  ~MateriaSource();

  virtual void learnMateria(AMateria *m);
  virtual AMateria *createMateria(std::string const &type);
};

#endif // !__MATERIASOURCE_HPP__
