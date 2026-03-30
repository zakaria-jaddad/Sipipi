#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <class T> class Array {
public:
  Array() {
    this->_size = 0;
    this->_array = new T[0];
  }
  Array(unsigned int n) {
    this->_array = new T[n]();
    this->_size = n;
  }
  Array(const Array &other) {
    this->_array = new T[other._size]();
    for (unsigned int i = 0; i < other._size; i++) {
      this->_array[i] = other._array[i];
    }
    this->_size = other._size;
  }
  Array &operator=(const Array &other) {
    if (this == &other)
      return *this;
    delete[] this->_array;
    this->_array = NULL;
    this->_array = new T[other._size]();
    for (unsigned int i = 0; i < other._size; i++) {
      this->_array[i] = other._array[i];
    }
    this->_size = other._size;
    return *this;
  }
  ~Array() { delete[] this->_array; }

  class InvalidIndexException : public std::exception {
  public:
    // InvalidIndexException() {};
    // virtual ~InvalidIndexException() {};
    const char *what() const throw() { return "Invalid Array Index"; }
  };

  const T &operator[](unsigned int index) const {
    if (index >= this->_size) {
      throw Array<T>::InvalidIndexException();
    }
    return (this->_array[index]);
  }

  T &operator[](unsigned int index) {
    if (index >= this->_size || this->_array == NULL) {
      throw Array<T>::InvalidIndexException();
    }
    return (this->_array[index]);
  }
  unsigned int size() const { return this->_size; }

private:
  T *_array;
  unsigned int _size;
};

#endif // !ARRAY_HPP
