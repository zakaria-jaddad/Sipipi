#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45) {
  this->_target = "Default RobotomyRequestForm name";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 72, 45) {
  this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {
  this->_target = other._target;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this == &other) {
    return *this;
  }
  AForm::operator=(other);
  this->_target = other._target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::formAction() const {
  std::cout << "* Drilling noises *" << std::endl;
  if (std::rand() % 2 == 0) {
    std::cout << this->_target << " has been robotomized successfully."
              << std::endl;
  } else {
    std::cout << "Failed to robotomize " << this->_target << "." << std::endl;
  }
}
