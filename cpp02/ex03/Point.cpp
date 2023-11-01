#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::Point( float const nb1, float const nb2 ) : _x(nb1), _y(nb2) {
}

Point::Point( Point const & src ) : _x(src.getX()), _y(src.getY()) {
}

Point &	Point::operator=( Point const & ) {
	return *this;
}

Point::~Point( void ) {
}

Fixed const &	Point::getX( void ) const {
	return _x;
}

Fixed const &	Point::getY( void ) const {
	return _y;
}
