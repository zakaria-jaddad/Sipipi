#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawValue(0) { std::cout << "Default constructor called\n"; }

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other) {
    this->_rawValue = other.getRawBits();
  }
  return *this;
}

Fixed::Fixed(const Fixed &other) {
  // this->_rawValue = other.getRawBits();
  *this = other;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called\n";
  return this->_rawValue;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called\n";
  _rawValue = raw;
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; }
