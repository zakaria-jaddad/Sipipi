
#include "Fixed.hpp"
#include "Point.hpp"

static float area(Point const a, Point const b, Point const c) {
  float x1 = a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat());
  float x2 = b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat());
  float x3 = c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat());

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
    return (false);
  }
  return ((pab_area + pbc_area + pac_area) == abc_area);
}
