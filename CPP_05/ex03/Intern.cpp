#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern::~Intern() {}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	std::string	forms[NB_FORMS] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm*	(Intern::*ptrs[NB_FORMS])(std::string target) = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};

	int	i = 0;

	while (i < NB_FORMS && forms[i].compare(form) != 0)
		i++;
	if (i > NB_FORMS - 1)
	{
		std::cout << "Form \"" << form << "\" doesn't exist" << std::endl;
		throw Intern::BadFormName();
	}
	if (i < NB_FORMS)
		return (this->*ptrs[i])(target);
	return NULL;
}

AForm	*Intern::createPresidentialPardonForm(std::string target)
{
	PresidentialPardonForm* form = new PresidentialPardonForm(target);
	return form;
}
AForm	*Intern::createRobotomyRequestForm(std::string target)
{
	RobotomyRequestForm* form = new RobotomyRequestForm(target);
	return form;
}
AForm	*Intern::createShrubberyCreationForm(std::string target)
{
	ShrubberyCreationForm* form = new ShrubberyCreationForm(target);
	return form;
}

const char*	Intern::BadFormName::what() const throw()
{
	return ("Intern::BadFormName");
}

