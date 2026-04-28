
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

template <typename T> bool easyfind(T &container, int number) {
  typename T::iterator it =
      std::find(container.begin(), container.end(), number);
  if (it == container.end()) {
    // not found
    return false;
  }
  // found
  return true;
}
#endif // EASYFIND_HPP
