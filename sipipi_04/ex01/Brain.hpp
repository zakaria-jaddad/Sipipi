#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <string>

class Brain {
public:
  std::string ideas[100];
  Brain();
  ~Brain();
  Brain(const Brain &other);
  Brain &operator=(const Brain &other);
};

#endif // !__BRAIN_HPP__
