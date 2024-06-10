#include "header.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

void	PhoneBook::welcome(void) const
{
	std::cout << "Welcome in PhoneBook App !" << std::endl;
	std::cout << std::endl;
	std::cout << "------ HOW TO USE ------" << std::endl;
	std::cout << "ADD : To add a contact" << std::endl;
	std::cout << "SEARCH : To search a contact" << std::endl;
	std::cout << "EXIT : To exit PhoneBook" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::displayPhoneBook(void) const
{
	std::cout << "---- PHONEBOOK CONTACTS ----" << std::endl;
	for (int i = 0; i < 8; i++)
		if (this->_contacts[i].isInitContact())
			this->_contacts[i].viewContact(i);
	std::cout << std::endl;
}

int	PhoneBook::_searchInput(void) const
{
	bool	valid = false;
	int		index = -1;

	do
	{
		std::cout << "Please enter the contact index : " << std::flush;
		std::cin >> index;
		if (index >= 0 && index < 8)
			valid = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Invalid index. Please try again." << std::endl;
		}
	} while (!valid);
	return (index);
}

void	PhoneBook::searchContact(void) const
{
	int	i;
	
	i = this->_searchInput();
	this->_contacts[i].printContact(i);
}

void	PhoneBook::addContact(void)
{
	static int	indexContact = 0;

	if (indexContact == 8)
		indexContact = 0;
	this->_contacts[indexContact].initContact();
	indexContact++;
}