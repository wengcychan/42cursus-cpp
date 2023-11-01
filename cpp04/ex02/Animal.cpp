#include <iostream>
#include "Animal.hpp"

AAnimal::AAnimal( void ) : _type("AAnimal") {
	std::cout << "Default constructor of AAnimal is called" << std::endl;
}

AAnimal::AAnimal( AAnimal const & src ) {
	std::cout << "Copy constructor of AAnimal is called" << std::endl;
	*this = src;
}

AAnimal & AAnimal::operator=( AAnimal const & rhs ) {
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

AAnimal::~AAnimal( void ) {
	std::cout << "Destructor of AAnimal is called" << std::endl;
}

std::string	AAnimal::getType( void ) const {
	return _type;
}
