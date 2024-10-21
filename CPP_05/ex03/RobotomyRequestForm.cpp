#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("target", 72, 45), _target("target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other)
{
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
	<< ", Grade to Sign: " << other.getGradeSign()
	<< ", Grade to Execute: " << other.getGradeExecute()
	<< ", is Signed: " << other.getSigned()
	<< ", Target: " << other.getTarget();
	return (os);
}

void	RobotomyRequestForm::execute(const Bureaucrat& bureaucrat)
{
	if ((*this).getSigned() == false)
	{
		std::cout << "The robotomy on " << (*this).getTarget() << " failed" << std::endl;
		throw	RobotomyRequestForm::NotSigned();
	}
	if (bureaucrat.getGrade() > (*this).getGradeExecute())
	{
		std::cout << "The robotomy on " << (*this).getTarget() << " failed" << std::endl;
		throw	RobotomyRequestForm::GradeTooLow();
	}
	std::cout << (*this).getTarget() << " has been robotomized successfully 50\% of the time " << std::endl;

}

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}
