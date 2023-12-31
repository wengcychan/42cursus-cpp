#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_NBR_CONTACT 8

class PhoneBook
{

    private:

		int		_nbContact;
		Contact	_contact[MAX_NBR_CONTACT];

		void	_displayContactList(void);
		void 	_displaySelectedContact(void);
		bool _checkIndex(std::string str);


	public:

        PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	searchContact(void);

};

#endif
