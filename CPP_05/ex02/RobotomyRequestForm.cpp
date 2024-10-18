#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("*NoName", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string name): AForm(name, 72, 45)
{
	if (_gradeSign < 1 || _gradeExecute < 1)
		throw GradeTooHigh();
	if (_gradeSign > 150 || _gradeExecute > 150)
		throw GradeTooLow();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other) {
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	_target = other._target;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& other)
{
	os << "RobotomyRequestForm Name: " << other.getName()
	<<", Grade to Sign: " << other.getGradeSign()
	<<", Grade to Execute: " << other.getGradeExecute()
	<<", Signed: " << other.getSigned()
	<<", Target: " << other.getSigned();
	return (os);
}


void	RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw Bureaucrat::GradeTooLow();
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if ((*this).getSigned() == true && executor.getGrade() <= (*this).getGradeExecute())
	{
		std::cout << "Some driling noises" << std::endl;
		std::cout << _target << " has been robotomized successfully 50 of the time" << std::endl;
	}
	else
		std::cout << "The robotomy failed" << std::endl;
}

std::string*	RobotomyRequestForm::getTarget() const
{
	return (_target);
}
