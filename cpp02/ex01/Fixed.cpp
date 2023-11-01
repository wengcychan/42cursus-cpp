#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed ( void ) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const value ) : _rawBits(value << _bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const value ) : _rawBits(std::roundf(value * (1 << _bits))) {
	std::cout << "Float constructor called" << std::endl;
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

float	Fixed::toFloat( void ) const {
	return static_cast<float>(_rawBits) / (1 << _bits);
}

int	Fixed::toInt( void ) const {
	return _rawBits >> _bits;
}

std::ostream &	operator<<( std::ostream & o, Fixed const & src ) {
	o << src.toFloat();
	return o;
}

int const	Fixed::_bits = 8;
