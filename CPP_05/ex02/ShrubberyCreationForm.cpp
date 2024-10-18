#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("*NoName", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name): AForm(name, 145, 137)
{
	if (_gradeSign < 1 || _gradeExecute < 1)
		throw GradeTooHigh();
	if (_gradeSign > 150 || _gradeExecute > 150)
		throw GradeTooLow();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other) {
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	_target = other._target;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& other)
{
	os << "ShrubberyCreationForm Name: " << other.getName()
	<<", Grade to Sign: " << other.getGradeSign()
	<<", Grade to Execute: " << other.getGradeExecute()
	<<", Signed: " << other.getSigned()
	<<", Target: " << other.getSigned();
	return (os);
}


void	ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw Bureaucrat::GradeTooLow();
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string	file_name = executor.getName() + "_shrubbery";
	std::ofstream file(file_name);
	if ((*this).getSigned() == true && executor.getGrade() <= (*this).getGradeExecute())
	{
		if (file.is_open())
		{
			file << "          &&& &&  & &&\n";
			file << "      && &\\/&\\|& ()|/ @, &&\n";
			file << "      &\\/(/&/&||/& /_/)_&/_&\n";
			file << "   &() &\\/&|()|/&\\/ '%\" & ()\n";
			file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
			file << "&&   && & &| &| /& & % ()& /&&\n";
			file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
			file << "     &&     \\|||\n";
			file << "             |||\n";
			file << "             |||\n";
			file << "       , -=-~  .-^- _\n" << std::endl;
		}
	}
}

std::string*	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}
