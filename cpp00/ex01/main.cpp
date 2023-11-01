#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(void) {

	PhoneBook	phonebook;
	std::string	cmd;

	while (1) {	
		if (std::cin.eof())
			return 0;
		std::cout << "Please enter command (ADD / SEARCH / EXIT) : ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return 0;
		if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
			phonebook.searchContact();
		else if (cmd == "EXIT")
			return 0;
		else if (cmd.empty() || cmd.find_first_not_of(" ") == cmd.npos)
			std::cout << "Empty Input" << std::endl;
		else
			std::cout << "Invalid Input" << std::endl;
	}

	return 0;

}
