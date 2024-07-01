#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "header.hpp"

class Contact {
private:
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phone;
	std::string	_secret;
	bool		_isInit;
	std::string	_getUserInput(std::string str) const;
	std::string	_trimeContact(std::string content) const;
public:
	Contact();
	~Contact();
	void	initContact(void);
	bool	isInitContact(void) const;
	void	viewContact(int index) const;
	void	printContact(int index) const;
};

#endif