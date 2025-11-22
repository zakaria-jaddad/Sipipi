#include "Point.hpp"

Point::Point() : x(Fixed(0.0f)), y(Fixed(0.0f)) {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point &copy) : x(copy.get_x()), y(copy.get_y()) {}

Point &Point::operator=(const Point &other) {
  (void)other;
  return *this;
}

Fixed const Point::get_x(void) const { return this->x; }

Fixed const Point::get_y(void) const { return this->y; }

Point::~Point() {}
