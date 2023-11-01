#include <iostream>
#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal") {
	std::cout << "Default constructor of Animal is called" << std::endl;
}

Animal::Animal( Animal const & src ) {
	std::cout << "Copy constructor of Animal is called" << std::endl;
	*this = src;
}

Animal & Animal::operator=( Animal const & rhs ) {
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

Animal::~Animal( void ) {
	std::cout << "Destructor of Animal is called" << std::endl;
}

void	Animal::makeSound( void ) const {
	std::cout << "Ah Ah Ah" << std::endl;
}

std::string	Animal::getType( void ) const {
	return _type;
}

