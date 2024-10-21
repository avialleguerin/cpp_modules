#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	std::cout << "\n* ----- WORKING TESTS ----- *" << std::endl;
	{
		Bureaucrat				John("John", 1);

		PresidentialPardonForm	pardonForm("criminal");
		RobotomyRequestForm		robotForm("robot_target");
		ShrubberyCreationForm	shrubberyForm("backyard");

		std::cout << "\n" << std::endl;
		std::cout << std::endl;
		John.signForm(robotForm);
		John.executeForm(robotForm);

		std::cout << "\n" << std::endl;
		John.signForm(shrubberyForm);
		John.executeForm(shrubberyForm);

		std::cout << "\n" << std::endl;
		John.signForm(pardonForm);
		John.executeForm(pardonForm);
	}

	std::cout << "\n* ----- FAILING TESTS : Signature ----- *" << std::endl;
	{
		Bureaucrat				Mike("Mike", 1);

		PresidentialPardonForm	pardonForm("criminal");
		RobotomyRequestForm		robotForm("robot_target");
		ShrubberyCreationForm	shrubberyForm("backyard");

		std::cout << "\n" << std::endl;
		std::cout << std::endl;
		Mike.executeForm(robotForm);

		std::cout << "\n" << std::endl;
		Mike.executeForm(shrubberyForm);

		std::cout << "\n" << std::endl;
		Mike.executeForm(pardonForm);
	}

	std::cout << "\n* ----- FAILING TESTS : Grade ----- *" << std::endl;
	{
		Bureaucrat				Jack("Jack", 150);
		Bureaucrat				Max("Max", 1);

		PresidentialPardonForm	pardonForm("criminal");
		RobotomyRequestForm		robotForm("robot_target");
		ShrubberyCreationForm	shrubberyForm("backyard");

		std::cout << "\n" << std::endl;
		std::cout << std::endl;
		Max.signForm(robotForm);
		Jack.executeForm(robotForm);

		std::cout << "\n" << std::endl;
		Max.signForm(shrubberyForm);
		Jack.executeForm(shrubberyForm);

		std::cout << "\n" << std::endl;
		Max.signForm(pardonForm);
		Jack.executeForm(pardonForm);
	}
	return 0;
}
