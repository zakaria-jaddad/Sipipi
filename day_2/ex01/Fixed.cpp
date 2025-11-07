#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawValue(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : _rawValue(val << _fractionalBits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
    : _rawValue(roundf(val * (1 << _fractionalBits))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    this->_rawValue = other._rawValue;
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

float Fixed::toFloat(void) const {
  return static_cast<float>(_rawValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const { return _rawValue >> _fractionalBits; }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}
