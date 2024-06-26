#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

# define COLUMN_WIDTH 10

class Contact
{

    private:

		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

		void		_setContactField(std::string const &prompt, std::string &field);
		bool		_isEmptyField(std::string const &field);
		std::string	_truncContactListItem(std::string item);

	
    public:

		Contact(void);
		~Contact(void);
		void	setContact(void);
		void	displayContactListItem(int const &i);
		void	displayContactInfo(void) const;

};

#endif
