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
	this->_firstname = this->_getUserInput("Please enter your firstname: ");
	this->_lastname = this->_getUserInput("Please enter your lastname: ");
	this->_nickname = this->_getUserInput("Please enter your nickname: ");
	this->_phone = this->_getUserInput("Please enter your phone number: ");
	this->_secret = this->_getUserInput("Please enter your darkest secret: ");
	std::cout << std::endl;
	this->_isInit = true;
}

void	Contact::viewContact(int index) const
{
	if (this->_firstname.empty() || this->_lastname.empty() || this->_nickname.empty())
		return ;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << this->_trimeContact(this->_firstname) << std::flush;
	std::cout << "|" << std::setw(10) << this->_trimeContact(this->_lastname) << std::flush;
	std::cout << "|" << std::setw(10) << this->_trimeContact(this->_nickname) << std::flush;
	std::cout << "|" << std::endl;
}
void	Contact::printContact(int index) const
{
	if (this->_firstname.empty() || this->_lastname.empty() || this->_nickname.empty())
		return ;
	std::cout << std::endl;
	std::cout << "Contact: " << index << std::endl;
	std::cout << "Firstname\t" << this->_firstname << std::endl;
	std::cout << "Lastname\t" << this->_lastname << std::endl;
	std::cout << "Nickname\t" << this->_nickname << std::endl;
	std::cout << std::endl;
}
