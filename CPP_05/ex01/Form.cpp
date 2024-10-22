#include "Form.hpp"

Form::Form(): _name("*NoName*"), _gradeSign(20), _gradeExecute(10), _signed(false) {}

Form::Form(std::string name, int gradeSign, int gradeExecute): _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute), _signed(false)
{
	if (_gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHigh();
	if (_gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLow();
	std::cout << "Form " << name << " has been created" << std::endl;
}

Form::Form(const Form& other): _name(other._name), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
, _signed(other._signed){
	*this = other;
}

Form::~Form() {}

Form&	Form::operator=(const Form& other)
{
	_signed = other._signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Form& other)
{
	os << "Form Name: " << other.getName()
	<<", Grade to Sign: " << other.getGradeSign()
	<<", Grade to Execute: " << other.getGradeExecute()
	<<", is Signed: " << other.getSigned();
	return (os);
}


void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw Bureaucrat::GradeTooLow();
}

std::string	Form::getName() const
{
	return (_name);
}

int	Form::getGradeSign() const
{
	return (_gradeSign);
}

int	Form::getGradeExecute() const
{
	return (_gradeExecute);
}


bool	Form::getSigned() const
{
	return (_signed);
}

const char*	Form::GradeTooLow::what() const throw()
{
	return ("Form::GradeTooLow");
}

const char*	Form::GradeTooHigh::what() const throw()
{
	return ("Form::GradeTooHigh");
}
