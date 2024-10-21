#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <exception>
#include <cstdio>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

# define NB_FORMS 3

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	~Intern();

	Intern&	operator=(const Intern& other);

	AForm	*makeForm(std::string formName, std::string target);
	AForm	*createPresidentialPardonForm(std::string target);
	AForm	*createRobotomyRequestForm(std::string target);
	AForm	*createShrubberyCreationForm(std::string target);

	class BadFormName : public std::exception
	{
	public:
		const char	*what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Intern& other);

#endif