#include <iostream>
#include "Dog.hpp"

Dog::Dog( void ) {
	_type = "Dog";
	std::cout << "Default constructor of Dog is called" << std::endl;
	_brain = new Brain();
}

Dog::Dog( Dog const & src ) {
	std::cout << "Copy constructor of Dog is called" << std::endl;
	_brain = new Brain();
	*this = src;
}

Dog & Dog::operator=( Dog const & rhs ) {
	if (this != &rhs) {
		_type = rhs._type;
		*_brain = *(rhs._brain);
	}
	return *this;
}

Dog::~Dog( void ) {
	delete _brain;
	std::cout << "Destructor of Dog is called" << std::endl;
}
		
void	Dog::makeSound( void ) const {
	std::cout << "Woo Woo Woo" << std::endl;
}

void	Dog::setBrain( std::string idea ) {
	_brain->setIdea(idea);
}

void	Dog::printBrain( void ) {
	_brain->printIdea();
}
