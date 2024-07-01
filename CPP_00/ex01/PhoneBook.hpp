#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "header.hpp"

class PhoneBook{
	private:
		Contact	_contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(void);
		void	displayPhoneBook(void) const;
		void	searchContact(void) const;
};

#endif