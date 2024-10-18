#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	const std::string	_name;
	const int			_gradeSign;
	const int			_gradeExecute;
	bool				_signed;
public:
	AForm();
	AForm(std::string name, int gradeSign, int gradeExecute);
	AForm(const AForm& other);
	~AForm();

	AForm&	operator=(const AForm& other);

	std::string		getName() const;
	int				getGradeSign() const;
	int				getGradeExecute() const;
	bool			getSigned() const;

	virtual void			beSigned(const Bureaucrat& bureaucrat) = 0;

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

std::ostream&	operator<<(std::ostream& os, const AForm& other);

#endif