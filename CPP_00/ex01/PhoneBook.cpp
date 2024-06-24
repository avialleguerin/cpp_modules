#include "header.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

void	PhoneBook::displayPhoneBook(void) const
{
	if (!_contacts[0].isInitContact())
	{
		std::cout << "\nPhoneBook is empty...\n" << std::endl;
		return ;
	}
	std::cout << "\n------------- PHONEBOOK CONTACTS -------------\n" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << std::flush;
	std::cout << "|" << std::setw(10) << "Firstname" << std::flush;
	std::cout << "|" << std::setw(10) << "Lastname" << std::flush;
	std::cout << "|" << std::setw(10) << "Nickname" << std::flush;
	std::cout << "|" << std::endl;
	for (int i = 0; i < 8; i++)
		if (_contacts[i].isInitContact())
			_contacts[i].viewContact(i);
	std::cout << std::endl;
	searchContact();
}


void	PhoneBook::searchContact(void) const
{
	int		nb;
	bool	validInput = false;
	while (!validInput)
	{
		std::cout << "Enter a contact index: " << std::flush;
		if (!(std::cin >> nb))
		{
			if (!std::cin)
				std::freopen("/dev/tty", "r", stdin);
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nInvalid input. Try again" << std::endl;
		}
		else if ((nb >= 0 && nb < 8) && _contacts[nb].isInitContact())
			validInput = true;
		else
			std::cout << "\nInvalid index. Try again" << std::endl;
	}
	_contacts[nb].printContact(nb);
}

void	PhoneBook::addContact(void)
{
	static int	indexContact = 0;

	if (indexContact == 8)
		indexContact = 0;
	_contacts[indexContact].initContact();
	indexContact++;
}
