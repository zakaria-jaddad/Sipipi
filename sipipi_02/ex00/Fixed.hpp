#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {
private:
  int _rawValue;
  static const int _fractionalBits;

public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  int getRawBits(void) const;
  void setRawBits(int const rawValue);
  ~Fixed();
};

#endif // !__FIXED_HPP__
