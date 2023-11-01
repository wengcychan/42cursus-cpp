#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {
	_type = "WrongCat";
	std::cout << "Default constructor of WrongCat is called" << std::endl;
}

WrongCat::WrongCat( WrongCat const & src ) {
	std::cout << "Copy constructor of WrongCat is called" << std::endl;
	*this = src;
}

WrongCat & WrongCat::operator=( WrongCat const & rhs ) {
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

WrongCat::~WrongCat( void ) {
	std::cout << "Destructor of WrongCat is called" << std::endl;
}
	
void	WrongCat::makeSound( void ) const {
	std::cout << "Meow Meow Meow" << std::endl;
}
