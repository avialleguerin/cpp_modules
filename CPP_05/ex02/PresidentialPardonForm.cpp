#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("target", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	_signed = other._signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& other)
{
	os << "PresidentialPardonForm Name: " << other.getName()
	<<", Grade to Sign: " << other.getGradeSign()
	<<", Grade to Execute: " << other.getGradeExecute()
	<<", is Signed: " << other.getSigned();
	return (os);
}


void	PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw Bureaucrat::GradeTooLow();
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}
