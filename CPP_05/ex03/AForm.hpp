#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <exception>
#include <cstdio>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	const int			_gradeSign;
	const int			_gradeExecute;
	bool				_signed;
public:
	AForm();
	AForm(std::string name, int gradeSign, int gradeExecute);
	AForm(const AForm& other);
	virtual ~AForm();

	AForm&	operator=(const AForm& other);

	std::string		getName() const;
	int				getGradeSign() const;
	int				getGradeExecute() const;
	bool			getSigned() const;

	void				beSigned(const Bureaucrat& bureaucrat);
	virtual void		execute(const Bureaucrat& bureaucrat) = 0;
	virtual std::string	getTarget() const = 0;

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
	class NotSigned : public std::exception
	{
	public:
		const char	*what() const throw();
	};

};

std::ostream&	operator<<(std::ostream& os, const AForm& other);

#endif