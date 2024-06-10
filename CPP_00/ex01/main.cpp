#include "header.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string input;
	std::cout << "Welcome in PhoneBook App !\n" << std::endl;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT) : " << std::flush;
		if (!(std::cin >> input))
			break;
		if (input.compare("EXIT") == 0)
			break;
		if (input.compare("ADD") == 0)
			book.addContact();
		if (input.compare("SEARCH") == 0)
		{
			book.displayPhoneBook();
			book.searchContact();
		}
	}
	return 0;
}