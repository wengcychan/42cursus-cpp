#include <iostream>
#include "Brain.hpp"

Brain::Brain( void ) : _countIdea(0) {
	std::cout << "Default constructor of Brain is called" << std::endl;
}

Brain::Brain( Brain const & src ) : _countIdea(0) {
	std::cout << "Copy constructor of Brain is called" << std::endl;
	*this = src;
}

Brain & Brain::operator=( Brain const & rhs ) {
	if (this != &rhs) {
		for (int i = 0; i < NB_IDEA; ++i)
			_ideas[i] = rhs._ideas[i];
		_countIdea = rhs._countIdea;
	}
	return *this;
}

Brain::~Brain ( void ) {
	std::cout << "Destructor of Brain is called" << std::endl;
}

void	Brain::setIdea( std::string idea ) {
	if (_countIdea == NB_IDEA) {
		std::cout << "the idea array is full, cannot add " << idea << std::endl;
		return;
	}
	_ideas[_countIdea] = idea;
	_countIdea++;
}

void	Brain::printIdea( void ) {
	for (int i = 0; i < std::min(_countIdea, NB_IDEA); ++i)
		std::cout << _ideas[i] << std::endl;
}
