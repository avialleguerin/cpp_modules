#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

	void			execute(const Bureaucrat& bureaucrat);
	std::string		getTarget() const;

};

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& other);

#endif