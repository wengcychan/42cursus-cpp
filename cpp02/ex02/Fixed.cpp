#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed ( void ) : _rawBits(0) {
}

Fixed::Fixed( int const value ) : _rawBits(value << _bits) {
}

Fixed::Fixed( float const value ) : _rawBits(std::roundf(value * (1 << _bits))) {
}

Fixed::Fixed ( Fixed const & src ) {
	*this = src;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	if (this != &rhs)
		setRawBits(rhs.getRawBits());

	return *this;
}

Fixed::~Fixed( void ) {
}

int	Fixed::getRawBits( void ) const {
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

bool	Fixed::operator>(Fixed const & rhs) const {
	return (_rawBits > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const & rhs) const {
	return (_rawBits < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhs) const {
	return (_rawBits >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhs) const {
	return (_rawBits <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const & rhs) const {
	return (_rawBits == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhs) const {
	return (_rawBits != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const & rhs) const {
	Fixed	res;
	res.setRawBits(_rawBits + rhs.getRawBits());
	return res;
}

Fixed	Fixed::operator-(Fixed const & rhs) const {
	Fixed	res;
	res.setRawBits(_rawBits - rhs.getRawBits());
	return res;
}

Fixed	Fixed::operator*(Fixed const & rhs) const {
	Fixed	res;
	res.setRawBits((_rawBits * rhs.getRawBits()) >> _bits);
	return res;
}

Fixed	Fixed::operator/(Fixed const & rhs) const {
	Fixed	res;
	res.setRawBits((_rawBits << _bits) / rhs.getRawBits());
	return res;
}

Fixed	Fixed::operator++( void ) {
	_rawBits++;
	return *this;
}

Fixed	Fixed::operator++( int ) {
	Fixed tmp = *this;
	_rawBits++;
	return tmp;
}

Fixed	Fixed::operator--( void ) {
	_rawBits--;
	return *this;
}

Fixed	Fixed::operator--( int ) {
	Fixed tmp = *this;
	_rawBits--;
	return tmp;
}

Fixed &	Fixed::min(Fixed &nb1, Fixed &nb2) {
	return (nb1 < nb2) ? nb1 : nb2 ;
}

Fixed const &	Fixed::min(Fixed const &nb1, Fixed const &nb2) {
	return (nb1 < nb2) ? nb1 : nb2 ;
}

Fixed &	Fixed::max(Fixed &nb1, Fixed &nb2) {
	return (nb1 > nb2) ? nb1 : nb2 ;
}

Fixed const &	Fixed::max(Fixed const &nb1, Fixed const &nb2) {
	return (nb1 > nb2) ? nb1 : nb2 ;
}

std::ostream &	operator<<( std::ostream & o, Fixed const & src ) {
	o << src.toFloat();
	return o;
}

int const	Fixed::_bits = 8;
