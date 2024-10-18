#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("*NoName", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string name): AForm(name, 25, 5)
{
	if (_gradeSign < 1 || _gradeExecute < 1)
		throw GradeTooHigh();
	if (_gradeSign > 150 || _gradeExecute > 150)
		throw GradeTooLow();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other) {
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	_target = other._target;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& other)
{
	os << "PresidentialPardonForm Name: " << other.getName()
	<<", Grade to Sign: " << other.getGradeSign()
	<<", Grade to Execute: " << other.getGradeExecute()
	<<", Signed: " << other.getSigned()
	<<", Target: " << other.getSigned();
	return (os);
}


void	PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw Bureaucrat::GradeTooLow();
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if ((*this).getSigned() == true && executor.getGrade() <= (*this).getGradeExecute())
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		std::cout << "Zaphod Beeblebrox didn't pardoned " << _target << std::endl;
}

std::string*	PresidentialPardonForm::getTarget() const
{
	return (_target);
}
