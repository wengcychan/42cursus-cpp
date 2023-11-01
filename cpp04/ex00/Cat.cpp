#include <iostream>
#include "Cat.hpp"

Cat::Cat( void ) {
	_type = "Cat";
	std::cout << "Default constructor of Cat is called" << std::endl;
}

Cat::Cat( Cat const & src ) {
	std::cout << "Copy constructor of Cat is called" << std::endl;
	*this = src;
}

Cat & Cat::operator=( Cat const & rhs ) {
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

Cat::~Cat( void ) {
	std::cout << "Destructor of Cat is called" << std::endl;
}
	
void	Cat::makeSound( void ) const {
	std::cout << "Meow Meow Meow" << std::endl;
}
