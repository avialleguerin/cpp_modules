#include "header.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string input = "";
	book.welcome();

	while (true)
	{
		std::cout << "> " << std::flush;
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