#include "header.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string input;
	std::cout << "Welcome in PhoneBook App !\n" << std::endl;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT) : " << std::flush;
		std::getline(std::cin, input);
		if (!std::cin)
			break;
		else if (input.compare("EXIT") == 0)
			break;
		else if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH") == 0)
		{
			book.displayPhoneBook();
			book.searchContact();
		}
	}
	return 0;
}