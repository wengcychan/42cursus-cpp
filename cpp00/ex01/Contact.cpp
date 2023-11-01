#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(void) {
}

Contact::~Contact(void){
}

void	Contact::setContact(void) {

	_setContactField("first name : ", _firstName);
	_setContactField("last name : ", _lastName);
	_setContactField("nick name : ", _nickname);
	_setContactField("phone number : ", _phoneNumber);
	_setContactField("darkest secret : ", _darkestSecret);

}

void Contact::_setContactField (std::string prompt, std::string &field) {

	do {
		if (std::cin.eof())
			break;
		std::cout << prompt;
		std::getline(std::cin, field);
		if (std::cin.eof())
			break;
	} while (!_checkContactField(field));

}

bool Contact::_checkContactField (std::string field) {

	if (field.empty() || field.find_first_not_of(" ") == field.npos) {
		std::cout << "Empty Input" << std:: endl;
		return false;
	}
	return true;

}

void	Contact::displayContactListItem(int i) {

	std::cout << std::right << std::setw(COLUMN_WIDTH) << i + 1 << "|";
	std::cout << std::right << std::setw(COLUMN_WIDTH) << _truncContactListItem(_firstName) << "|";
	std::cout << std::right << std::setw(COLUMN_WIDTH) << _truncContactListItem(_lastName) << "|";
	std::cout << std::right << std::setw(COLUMN_WIDTH) << _truncContactListItem(_nickname) << std::endl;

}

std::string	Contact::_truncContactListItem(std::string item) {

	if (item.length() > COLUMN_WIDTH) {
		item = item.substr(0, 9);
		item.push_back('.');
	}
	return item;

}

void	Contact::displayContactInfo(void) const {

	std::cout << "first name : " << _firstName << std::endl;
	std::cout << "last name : " << _lastName << std::endl;
	std::cout << "nick name : " << _nickname << std::endl;
	std::cout << "phone number : " << _phoneNumber << std::endl;
	std::cout << "darkest secret : " << _darkestSecret << std::endl;

}
