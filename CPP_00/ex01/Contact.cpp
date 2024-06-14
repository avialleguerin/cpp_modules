#include "header.hpp"

Contact::Contact()
{
	_isInit = false;
}

Contact::~Contact()
{
}

std::string	Contact::_getUserInput(std::string str) const
{
	std::string	input = "";
	bool		validInput = false;

	std::cout << str << std::flush;
	std::getline(std::cin, input);
	if (std::cin.good() && !input.empty())
		validInput = true;
	else 
	{
		if (!std::cin)
		{
			std::cout << "X" << std::endl;
			return ("empty");
		}
		std::cin.clear();
		std::cout << "Entree invalide. Veuillez reessayer" << std::endl;
		_getUserInput(str);
	}
	return (input);
	
}

std::string	Contact::_trimeContact(std::string content) const
{
	if (content.length() > 10)
		return (content.substr(0, 9) + ".");
	return (content);
}


bool	Contact::isInitContact(void) const
{
	return (_isInit);
}

void	Contact::initContact(void)
{
	_firstname = _getUserInput("Entrez le prenom: ");
	_lastname = _getUserInput("Entrez le nom de famille: ");
	_nickname = _getUserInput("Entrez le surnom: ");
	_phone = _getUserInput("Entrez le numero de telephone: ");
	_secret = _getUserInput("Entrez le sombre secret: ");
	std::cout << std::endl;
	_isInit = true;
}

void	Contact::viewContact(int index) const
{
	if (_firstname.empty() || _lastname.empty() || _nickname.empty())
		return ;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << _trimeContact(_firstname) << std::flush;
	std::cout << "|" << std::setw(10) << _trimeContact(_lastname) << std::flush;
	std::cout << "|" << std::setw(10) << _trimeContact(_nickname) << std::flush;
	std::cout << "|" << std::endl;
}
void	Contact::printContact(int index) const
{
	if (_firstname.empty() || _lastname.empty() || _nickname.empty())
		return ;
	std::cout << std::endl;
	std::cout << "Contact: " << index << std::endl;
	std::cout << "Firstname\t" << _firstname << std::endl;
	std::cout << "Lastname\t" << _lastname << std::endl;
	std::cout << "Nickname\t" << _nickname << std::endl;
	std::cout << std::endl;
}
