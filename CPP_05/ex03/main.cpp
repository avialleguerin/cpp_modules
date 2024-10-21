#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat Jon("Jon", 1);
	std::cout << "\n----- OK TESTS -----!\n" << std::endl;
	{
		Intern intern;
		AForm* presidential;
		try 
		{
			presidential = intern.makeForm("presidential pardon", "prisoner");
			Jon.signForm(*presidential);
			Jon.executeForm(*presidential);
			delete presidential;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception catched : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Intern intern;
		AForm* robotomy;
		try 
		{
			robotomy = intern.makeForm("robotomy request", "Transformer");
			Jon.signForm(*robotomy);
			Jon.executeForm(*robotomy);
			delete robotomy;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception catched : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Intern intern;
		AForm* shrubbery;
		try 
		{
			shrubbery = intern.makeForm("shrubbery creation", "backyard");
			Jon.signForm(*shrubbery);
			Jon.executeForm(*shrubbery);
			delete shrubbery;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception catched : " << e.what() << std::endl;
		}
	}
	std::cout << "\n\n----- KO TEST -----\n" << std::endl;
	{
		Intern intern;
		AForm* bad;
		try 
		{
			bad = intern.makeForm("bad form name", "Bender");
			Jon.signForm(*bad);
			Jon.executeForm(*bad);
			delete bad;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception catched : " << e.what() << std::endl;
		}
	}
	return 0;
}
