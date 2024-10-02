#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	std::string	_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

	void		beSigned(const Bureaucrat& bureaucrat);

};

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& other);

#endif