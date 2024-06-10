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

	do
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			validInput = true;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input; please try again." << std::endl;
		}
	} while (!validInput);
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
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	_firstname = _getUserInput("Please enter your firstname: ");
	_lastname = _getUserInput("Please enter your lastname: ");
	_nickname = _getUserInput("Please enter your nickname: ");
	_phone = _getUserInput("Please enter your phone number: ");
	_secret = _getUserInput("Please enter your darkest secret: ");
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
