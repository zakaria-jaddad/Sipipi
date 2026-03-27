#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5) {
  this->_target = "Default PresidentialPardonForm Target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5) {
  this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other) {
  this->_target = other._target;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this == &other) {
    return *this;
  }
  AForm::operator=(other);
  this->_target = other._target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::formAction() const {
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
