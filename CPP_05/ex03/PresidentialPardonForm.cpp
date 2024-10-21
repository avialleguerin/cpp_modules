#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("target", 25, 5), _target("target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other)
{
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
	<< ", Grade to Sign: " << other.getGradeSign()
	<< ", Grade to Execute: " << other.getGradeExecute()
	<< ", is Signed: " << other.getSigned()
	<< ", Target: " << other.getTarget();
	return (os);
}

void	PresidentialPardonForm::execute(const Bureaucrat& bureaucrat)
{
	if ((*this).getSigned() == false)
	{
		std::cout << "Zaphod Beeblebrox didn't pardoned " << (*this).getTarget() << std::endl;
		throw	PresidentialPardonForm::NotSigned();
	}
	if (bureaucrat.getGrade() > (*this).getGradeExecute())
	{
		std::cout << "Zaphod Beeblebrox didn't pardoned " << (*this).getTarget() << std::endl;
		throw	PresidentialPardonForm::GradeTooLow();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}
