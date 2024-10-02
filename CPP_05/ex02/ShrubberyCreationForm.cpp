#include "AForm.hpp"

AForm::AForm(): _name("*NoName*"), _gradeSign(20), _gradeExecute(10), _signed(false) {}

AForm::AForm(std::string name, int gradeSign, int gradeExecute): _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	if (_gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHigh();
	if (_gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLow();
}

AForm::AForm(const AForm& other): _name(other._name), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
, _signed(other._signed){
	*this = other;
}

AForm::~AForm() {}

AForm&	AForm::operator=(const AForm& other)
{
	_signed = other._signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const AForm& other)
{
	os << "AForm Name: " << other.getName()
	<<", Grade to Sign: " << other.getGradeSign()
	<<", Grade to Execute: " << other.getGradeExecute()
	<<", is Signed: " << other.getSigned();
	return (os);
}


void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw Bureaucrat::GradeTooLow();
}

std::string	AForm::getName() const
{
	return (_name);
}

int	AForm::getGradeSign() const
{
	return (_gradeSign);
}

int	AForm::getGradeExecute() const
{
	return (_gradeExecute);
}


bool	AForm::getSigned() const
{
	return (_signed);
}

const char*	AForm::GradeTooLow::what() const throw()
{
	return ("AForm::GradeTooLow");
}

const char*	AForm::GradeTooHigh::what() const throw()
{
	return ("AForm::GradeTooHigh");
}
