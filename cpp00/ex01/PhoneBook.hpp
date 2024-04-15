#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_NBR_CONTACT 8

class PhoneBook
{

    private:

		int		_nbContact;
		Contact	_contact[MAX_NBR_CONTACT];

		void	_addContact(void);
		void	_searchContact(void);
		void	_displayContactList(void);
		void 	_displaySelectedContact(void);
		bool _checkIndex(std::string const &str);


	public:

    PhoneBook(void);
		~PhoneBook(void);
		void	run(void);
};

#endif
