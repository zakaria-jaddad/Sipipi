#include "Point.hpp"
#include "bsp.hpp"

int main(void) {

  Point a(0, 0);
  Point b(10, 0);
  Point c(5, 10);

  std::cout << "Triangle: A(0,0) B(10,0) C(5,10)" << std::endl;

  Point inside(5, 5);
  std::cout << "Test 1 Inside point (5,5): ";
  if (bsp(a, b, c, inside))
    std::cout << "INSIDE" << std::endl;
  else
    std::cout << "OUTSIDE" << std::endl;

  Point outside(15, 5);
  std::cout << "Test 2 Outside point (15,5): ";
  if (bsp(a, b, c, outside))
    std::cout << "INSIDE" << std::endl;
  else
    std::cout << "OUTSIDE" << std::endl;

  Point vertex(0, 0);
  std::cout << "Test 3 Vertex point (0,0): ";
  if (bsp(a, b, c, vertex))
    std::cout << "INSIDE" << std::endl;
  else
    std::cout << "OUTSIDE" << std::endl;

  return 0;
}
