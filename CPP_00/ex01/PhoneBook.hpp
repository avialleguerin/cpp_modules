#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "header.hpp"

class PhoneBook{
	private:
		Contact	_contacts[8];
		int		_nbContacts;
		int		_searchInput(void) const;
	public:
		PhoneBook();;
		~PhoneBook();
		void	welcome(void) const;
		void	addContact(void);
		void	displayPhoneBook(void) const;
		void	searchContact(void) const;
};

#endif