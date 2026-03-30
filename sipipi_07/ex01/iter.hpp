#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T> void printElement(const T &var) {
  std::cout << var << " ";
}

template <typename T> void incrementElement(T &var) { var++; }

template <typename T> void iter(T *array, size_t length, void (*func)(T &)) {
  for (size_t i = 0; i < length; i++) {
    func(array[i]);
  }
}

template <typename T>
void iter(const T *array, size_t length, void (*func)(const T &)) {
  for (size_t i = 0; i < length; i++) {
    func(array[i]);
  }
}

#endif // !ITER_HPP
