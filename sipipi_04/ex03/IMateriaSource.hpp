#ifndef __IMATERIASOURCE__HPP_
#define __IMATERIASOURCE__HPP_
#include "AMateria.hpp"

class IMateriaSource {
public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria *) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif // !__IMATERIASOURCE__HPP_
