#include "Bureaucrat.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int	main()
{
	try {
		Bureaucrat bureaucrat("bureau", 148);
		std::cout << "\n-------CONSTRUCT FORM WITH GRADE TOO LOW----------\n" << std::endl;
		ShrubberyCreationForm form1("Contract");
		form1.beSigned(bureaucrat);
		form1.execute(bureaucrat);
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
