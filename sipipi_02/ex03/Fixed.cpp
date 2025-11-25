#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawValue(0) {}

Fixed::Fixed(const int val) : _rawValue(val << _fractionalBits) {}

Fixed::Fixed(const float val)
    : _rawValue(roundf(val * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed::~Fixed() {}

float Fixed::toFloat(void) const {
  return float(_rawValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const { return _rawValue >> _fractionalBits; }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}

int Fixed::getRawBits(void) const { return this->_rawValue; }

void Fixed::setRawBits(int const rawValue) { _rawValue = rawValue; }

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other)
    this->_rawValue = other.getRawBits();
  return *this;
}

bool Fixed::operator>(const Fixed &other) const {
  return (this->_rawValue > other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const {
  return (this->_rawValue >= other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const {
  return this->_rawValue < other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
  return this->_rawValue <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
  return this->_rawValue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
  return this->_rawValue != other.getRawBits();
}

Fixed Fixed::operator*(const Fixed &other) const {

  Fixed result;

  result._rawValue = (this->_rawValue * other.getRawBits()) >> _fractionalBits;
  return result;
}

Fixed Fixed::operator+(const Fixed &other) const {

  Fixed result;
  result._rawValue = this->_rawValue + other.getRawBits();
  return (result);
}

Fixed Fixed::operator-(const Fixed &other) const {

  Fixed result;
  result._rawValue = this->_rawValue - other.getRawBits();
  return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {

  Fixed result;
  result._rawValue = (this->_rawValue >> _fractionalBits) / other.getRawBits();
  return (result);
}

Fixed &Fixed::operator++() {
  this->_rawValue++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed copy = *this;
  this->_rawValue++;
  return (copy);
}

Fixed Fixed::operator--(int) {
  Fixed copy = *this;
  this->_rawValue--;
  return (copy);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) { return (f1 <= f2 ? f1 : f2); }

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
  return (f1 <= f2 ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) { return (f1 > f2 ? f1 : f2); }

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
  return (f1 > f2 ? f1 : f2);
}
