#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
  Dog();
  ~Dog();
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  void makeSound() const;

  private:
    Brain* brain;
};

#endif // !__DOG_HPP__
