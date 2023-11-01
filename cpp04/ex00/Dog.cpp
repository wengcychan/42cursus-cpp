#include <iostream>
#include "Dog.hpp"

Dog::Dog( void ) {
	_type = "Dog";
	std::cout << "Default constructor of Dog is called" << std::endl;
}

Dog::Dog( Dog const & src ) {
	std::cout << "Copy constructor of Dog is called" << std::endl;
	*this = src;
}

Dog & Dog::operator=( Dog const & rhs ) {
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

Dog::~Dog( void ) {
	std::cout << "Destructor of Dog is called" << std::endl;
}
		
void	Dog::makeSound( void ) const {
	std::cout << "Woo Woo Woo" << std::endl;
}
