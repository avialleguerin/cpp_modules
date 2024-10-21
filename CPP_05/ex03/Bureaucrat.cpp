#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("*NoName*"), _grade(50)
{
	std::cout << "A Bureaucrat with the grade " << _grade << " has been created." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	(*this).setGrade(grade);
	std::cout << "A Bureaucrat named " << _name << " with the grade " << _grade << " has been created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "A Copy Bureaucrat named " << _name << " with the grade " << _grade << " has been created." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A Copy Bureaucrat named " << _name << " with the grade " << _grade << " has been destroyed." << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	_grade = other._grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() <<", bureaucrat grade " << other.getGrade() << "." << std::endl;
	return (os);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		std::cout << "Bureaucrat " << _name << "has already the highest grade." << std::endl;
	else
	{
		_grade--;
		std::cout << "Bureaucrat " << _name << " has now the grade " << _grade << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		std::cout << "Bureaucrat " << _name << "has already the lowest grade." << std::endl;
	else
	{
		_grade++;
		std::cout << "Bureaucrat " << _name << " has now the grade " << _grade << std::endl;
	}
}

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "." << std::endl;
	} catch(std::exception& e)
	{
		std::cerr << "couldn't sign " << form.getSigned() << " beacause " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch(std::exception& e)
	{
		std::cerr << _name << " couldn't execute " << form.getTarget() << " because " << e.what() << std::endl;
	}
}


void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLow();
	if (grade < 1)
		throw Bureaucrat::GradeTooHigh();
	_grade = grade;
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

const char*	Bureaucrat::GradeTooLow::what() const throw()
{
	return ("Bureaucrat::GradeTooLow");
}

const char*	Bureaucrat::GradeTooHigh::what() const throw()
{
	return ("Bureaucrat::GradeTooHigh");
}
