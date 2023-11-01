#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal"){
	std::cout << "Default constructor of WrongAnimal is called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src ) {
	std::cout << "Copy constructor of WrongAnimal is called" << std::endl;
	*this = src;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & rhs ) {
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "Destructor of WrongAnimal is called" << std::endl;
}
	
void	WrongAnimal::makeSound( void ) const {
	std::cout << "Ah Ah Ah" << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return _type;
}

