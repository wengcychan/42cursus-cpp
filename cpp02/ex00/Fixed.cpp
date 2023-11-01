#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed ( void ) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( Fixed const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs)
		setRawBits(rhs.getRawBits());

	return *this;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void	Fixed::setRawBits( int const raw ) {
	_rawBits = raw;
}

int const	Fixed::_bits = 8;
