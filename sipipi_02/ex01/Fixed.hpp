#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <ostream>

class Fixed {
private:
  int _rawValue;
  static const int _fractionalBits;

public:
  Fixed();
  Fixed(const int number);
  Fixed(const float number);
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  int getRawBits(void) const;
  void setRawBits(int const rawValue);
  int toInt(void) const;
  float toFloat(void) const;
  ~Fixed();
};

std::ostream &operator<<(std::ostream &os, const Fixed &n);

#endif // !__FIXED_HPP__
