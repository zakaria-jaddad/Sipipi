


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat Name") {
  this->_grade = 1;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
  if (grade < 1)
    throw GradeTooHighException("Grade Too High");
  else if (grade > 150)
    throw GradeTooLowException("Grade Too Low");
  else
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name) {
  this->_grade = other.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->_grade = other.getGrade();
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::incrementGrade() {
  if (this->_grade == 1)
    throw GradeTooHighException("Grade Out Of Range");
  this->_grade = this->_grade - 1;
}

void Bureaucrat::decrementGrade() {
  if (this->_grade == 150)
    throw GradeTooLowException("Grade Out Of Range");
  this->_grade = this->_grade + 1;
}
