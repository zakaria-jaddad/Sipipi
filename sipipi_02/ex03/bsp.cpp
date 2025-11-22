
#include "Fixed.hpp"
#include "Point.hpp"
#include <cstdio>
#include <iostream>
#include <ostream>

static float area(Point const a, Point const b, Point const c) {
  float x1 = a.get_x().toFloat() * (b.get_y().toFloat() - c.get_y().toFloat());
  float x2 = b.get_x().toFloat() * (c.get_y().toFloat() - a.get_y().toFloat());
  float x3 = c.get_x().toFloat() * (a.get_y().toFloat() - b.get_y().toFloat());

  float res = x1 + x2 + x3;
  if (res < 0)
    res *= -1;
  return (res / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {

  float abc_area = area(a, b, c);
  float pab_area = area(point, a, b);
  float pbc_area = area(point, b, c);
  float pac_area = area(point, a, c);

  if (pab_area == 0 || pbc_area == 0 || pac_area == 0) {

    // std::cout << pab_area << std::endl;
    // std::cout << pbc_area << std::endl;
    // std::cout << pac_area << std::endl;
    // std::cout << "hello world" << std::endl;
    //
    return (false);
  }
  return ((pab_area + pbc_area + pac_area) == abc_area);
}
