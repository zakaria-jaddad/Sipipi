#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point &copy) : x(copy.getX()), y(copy.getY()) {}

Point &Point::operator=(const Point &other) {
  (void)other;
  return *this;
}

Fixed const Point::getX(void) const { return this->x; }

Fixed const Point::getY(void) const { return this->y; }

Point::~Point() {}
