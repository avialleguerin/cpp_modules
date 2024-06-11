#include "header.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

void	PhoneBook::displayPhoneBook(void) const
{
	std::cout << "---- PHONEBOOK CONTACTS ----" << std::endl;
	for (int i = 0; i < 8; i++)
		if (_contacts[i].isInitContact())
			_contacts[i].viewContact(i);
	std::cout << std::endl;
}


void	PhoneBook::searchContact(void) const
{
	int	nb;
	std::cout << "Veuillez entrer l'index d'un contact : ";
	if (std::cin >> nb && nb < 8)
		_contacts[nb].printContact(nb);
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Erreur : Entree invalide." << std::endl;
	}
}

void	PhoneBook::addContact(void)
{
	static int	indexContact = 0;

	if (indexContact == 8)
		indexContact = 0;
	_contacts[indexContact].initContact();
	indexContact++;
}
