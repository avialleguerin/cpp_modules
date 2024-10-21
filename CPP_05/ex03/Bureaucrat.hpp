#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& other);

	void			incrementGrade();
	void			decrementGrade();

	void			signForm(AForm& other) const;
	void			executeForm(AForm& form) const;
	void			setGrade(int grade);
	std::string		getName() const;
	int				getGrade() const;

	class GradeTooLow : public std::exception
	{
	public:
		const char	*what() const throw();
	};
	class GradeTooHigh : public std::exception
	{
	public:
		const char	*what() const throw();
	};

};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& other);

#endif