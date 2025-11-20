#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <ostream>

class Fixed {
private:
  int _rawValue;
  static const int _fractionalBits = 8;

public:
  Fixed();
  Fixed(const int number);
  Fixed(const float number);
  Fixed(const Fixed &other);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  int toInt(void) const;
  float toFloat(void) const;
  ~Fixed();
  Fixed &operator=(const Fixed &other);
  //
  bool operator>(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  //
  Fixed operator*(const Fixed &other) const;
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  //
  Fixed &operator++(void);
  Fixed operator++(int); // adding int parameter meanning post increment
  Fixed &operator--(void);
  Fixed operator--(int);

  //

  static const Fixed &min(const Fixed &f1, const Fixed &f2);
  static Fixed &min(Fixed &f1, Fixed &f2);
  static const Fixed &max(const Fixed &f1, const Fixed &f2);
  static Fixed &max(Fixed &f1, Fixed &f2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &n);

#endif //  __FIXED_HPP__
