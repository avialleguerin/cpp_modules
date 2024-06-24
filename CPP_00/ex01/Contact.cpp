#include "header.hpp"

Contact::Contact() : _firstname(""), _lastname(""), _nickname(""), _phone(""), _secret("")
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

	while (!validInput)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			validInput = true;
		else 
		{
			if (!std::cin)
				std::freopen("/dev/tty", "r", stdin);
			std::cin.clear();
			std::cout << "\nInvalid input. Try again" << std::endl;
		}
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
	_firstname = _getUserInput("Enter First Name: ");
	_lastname = _getUserInput("Enter Last Name: ");
	_nickname = _getUserInput("Enter Nickname: ");
	_phone = _getUserInput("Enter Phone Number: ");
	_secret = _getUserInput("Enter Darkest Secret: ");
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
	std::cout << "Index\t\t" << index << std::endl;
	std::cout << "Firstname\t" << _firstname << std::endl;
	std::cout << "Lastname\t" << _lastname << std::endl;
	std::cout << "Nickname\t" << _nickname << std::endl;
	std::cout << "Phone Number\t" << _phone << std::endl;
	std::cout << "Darkest Secret\t" << _secret << std::endl;
	std::cout << std::endl;
}
