#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawValue(0) { std::cout << "Default constructor called\n"; }

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called\n";
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other) {
    this->_rawValue = other.getRawBits();
  }
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called\n";
  return this->_rawValue;
}

void Fixed::setRawBits(int const rawValue) {
  std::cout << "setRawBits member function called\n";
  _rawValue = rawValue;
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; }
