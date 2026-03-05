#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name,
                                             const int gradeToSign,
                                             const int gradeToExecute)
    : AForm(name, gradeToSign, gradeToExecute) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {};

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &exec) const {
  if (this->getIsSigned() == true) {
    if (this->getGradeToSign() == 145 && this->getGradeToExecute() == 137) {
      std::ofstream targetFile(this->getName() + "_shrubbery");
      if (targetFile.is_open() == false) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
      }
        targetFile << "       _-_" << std::endl;
        targetFile << "    /~~   ~~\\" << std::endl;
        targetFile << " /~~         ~~\\" << std::endl;
        targetFile << "{               }" << std::endl;
        targetFile << " \\  _-     -_  /" << std::endl;
        targetFile << "   ~  \\\\ //  ~" << std::endl;
        targetFile << "_- -   | | _- _" << std::endl;
        targetFile << "  _ -  | |   -_" << std::endl;
        targetFile << "      // \\\\" << std::endl;
        targetFile.close();
        return ;
    }
    throw AForm::GradeTooLowException();
  }
}
