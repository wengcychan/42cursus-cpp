#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:

		int					_rawBits;
		static int const	_bits;


	public:

		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );
		Fixed( Fixed const & src );
		Fixed &	operator=( Fixed const & rhs );
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt ( void ) const;

};

std::ostream &	operator<<( std::ostream & o, Fixed const & src );

#endif
