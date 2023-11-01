#include <iostream>
#include "Cat.hpp"

Cat::Cat( void ) {
	_type = "Cat";
	std::cout << "Default constructor of Cat is called" << std::endl;
	_brain = new Brain();
}

Cat::Cat( Cat const & src ) {
	std::cout << "Copy constructor of Cat is called" << std::endl;
	_brain = new Brain();
	*this = src;
}

Cat & Cat::operator=( Cat const & rhs ) {
	if (this != &rhs) {
		_type = rhs._type;
		*_brain = *(rhs._brain);
	}
	return *this;
}

Cat::~Cat( void ) {
	delete _brain;
	std::cout << "Destructor of Cat is called" << std::endl;
}
	
void	Cat::makeSound( void ) const {
	std::cout << "Meow Meow Meow" << std::endl;
}

void	Cat::setBrain( std::string idea ) {
	_brain->setIdea(idea);
}

void	Cat::printBrain( void ) {
	_brain->printIdea();
}
