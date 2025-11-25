#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point {

private:
  Fixed const x;
  Fixed const y;
  // more

public:
  Point();
  Point(const float x, const float y);
  Point(const Point &other);
  Point &operator=(const Point &other);
  ~Point();
  Fixed const getX(void) const;
  Fixed const getY(void) const;
};

#endif // !__POINT_HPP__
