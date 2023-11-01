#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

	private:

		Fixed const	_x;
		Fixed const	_y;

	
	public:

		Point( void );
		Point( float const nb1, float const nb2 );
		Point( Point const & src );
		Point & operator=( Point const & );
		~Point( void );
		Fixed const &	getX( void ) const;
		Fixed const &	getY( void ) const;

};

#endif
