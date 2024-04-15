#include <iostream>
#include <stdlib.h>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nbContact(0) {
}

PhoneBook::~PhoneBook(void){
}

void PhoneBook::run(void)
{

	std::string	cmd;

	while (!std::cin.eof()) {	
		std::cout << "Please enter command (ADD / SEARCH / EXIT) : ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return;
		if (cmd == "ADD")
			_addContact();
		else if (cmd == "SEARCH")
			_searchContact();
		else if (cmd == "EXIT")
			return;
		else if (cmd.empty() || cmd.find_first_not_of(" \t") == cmd.npos)
			std::cout << "Empty Input" << std::endl;
		else
			std::cout << "Invalid Input" << std::endl;
	}

}

void	PhoneBook::_addContact(void) {

	_contact[_nbContact % MAX_NBR_CONTACT].setContact();
	_nbContact++;

}

void	PhoneBook::_searchContact(void) {
	
	if (!_nbContact)
	{
		std::cout << "No Record" << std::endl;
		return ;
	}

	_displayContactList();
	_displaySelectedContact();

}

void PhoneBook::_displayContactList(void) {
	
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < std::min(_nbContact, MAX_NBR_CONTACT); ++i) {
		_contact[i].displayContactListItem(i);
	}

}

void PhoneBook::_displaySelectedContact(void) {
	
	std::string	str;

	do {
		std::cout << "Please enter index : ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			break;
	} while (!_checkIndex(str));

}

bool PhoneBook::_checkIndex(std::string const &str) {

	int index = std::atoi(str.c_str());
	if (str.empty() || str.find_first_not_of(" \t") == str.npos) {
		std::cout << "Empty Input" << std:: endl;
		return false;
	}
	if ((index < 1 || index > std::min(_nbContact, MAX_NBR_CONTACT)) ||
	std::to_string(index) != str) {
		std::cout << "Invalid Input" << std::endl;
		return false;
	}
	_contact[index - 1].displayContactInfo();
	return true;

}
