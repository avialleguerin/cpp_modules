#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	std::string	*_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

	void			beSigned(const Bureaucrat& bureaucrat);
	void			execute(Bureaucrat const & executor) const;
	std::string		*getTarget() const;

};

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& other);

#endif