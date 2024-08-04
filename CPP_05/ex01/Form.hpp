#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int			_gradeSign;
	const int			_gradeExecute;
	bool				_signed;
public:
	Form();
	Form(std::string name, int gradeSign, int gradeExecute);
	Form(const Form& other);
	~Form();

	Form&	operator=(const Form& other);

	std::string		getName() const;
	int				getGradeSign() const;
	int				getGradeExecute() const;
	bool			getSigned() const;

	void			beSigned(const Bureaucrat& bureaucrat);

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

std::ostream&	operator<<(std::ostream& os, const Form& other);

#endif