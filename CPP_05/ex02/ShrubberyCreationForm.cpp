#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("target", 145, 137), _target("target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other)
{
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
	<< ", Grade to Sign: " << other.getGradeSign()
	<< ", Grade to Execute: " << other.getGradeExecute()
	<< ", is Signed: " << other.getSigned()
	<< ", Target: " << other.getTarget();
	return (os);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat)
{
	if (!this->getSigned()) 
	{
		throw ShrubberyCreationForm::NotSigned();
	}
	if (bureaucrat.getGrade() > this->getGradeExecute()) 
	{
		throw ShrubberyCreationForm::GradeTooLow();
	}
	std::string fileName = this->getTarget() + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (!file.is_open()) 
	{
		std::cout << "Error : can't open the file " << fileName << std::endl;
		return;
	}

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
	file.close();
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}
