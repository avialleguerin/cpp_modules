#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): _name("*NoName*"), _gradeSign(20), _gradeExecute(10), _signed(false) {}

RobotomyRequestForm::RobotomyRequestForm(std::string name, int gradeSign, int gradeExecute): _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (_gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHigh();
	if (_gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLow();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): _name(other._name), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
, _signed(other._signed){
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	_signed = other._signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& other)
{
	os << "RobotomyRequestForm Name: " << other.getName()
	<<", Grade to Sign: " << other.getGradeSign()
	<<", Grade to Execute: " << other.getGradeExecute()
	<<", is Signed: " << other.getSigned();
	return (os);
}


void	RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw Bureaucrat::GradeTooLow();
}

std::string	RobotomyRequestForm::getName() const
{
	return (_name);
}

int	RobotomyRequestForm::getGradeSign() const
{
	return (_gradeSign);
}

int	RobotomyRequestForm::getGradeExecute() const
{
	return (_gradeExecute);
}


bool	RobotomyRequestForm::getSigned() const
{
	return (_signed);
}
