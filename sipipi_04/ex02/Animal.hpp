#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal {
protected:
  std::string type;

public:
  Animal();
  virtual ~Animal();
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  virtual void makeSound() const = 0;
  std::string getType() const;
};

#endif // !__ANIMAL_HPP__
