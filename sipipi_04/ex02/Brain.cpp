#include "Brain.hpp"
#include <iostream>

Brain::Brain() { std::cout << "Brain Default Constructor Called" << std::endl; }

Brain::~Brain() {
    std::cout << "Brain Destructor Called" << std::endl;
}

Brain::Brain(const Brain &other) { 
  *this = other;
}

Brain &Brain::operator=(const Brain &other) {
  if (this != &other) {
    for (int i = 0; i < 100; i++) {
      this->ideas[i] = other.ideas[i];
    }
  }
  return *this;
}
