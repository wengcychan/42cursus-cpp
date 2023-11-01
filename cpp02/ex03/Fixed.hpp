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

		bool	operator>(Fixed const & rhs) const; 
		bool	operator<(Fixed const & rhs) const; 
		bool	operator>=(Fixed const & rhs) const; 
		bool	operator<=(Fixed const & rhs) const; 
		bool	operator==(Fixed const & rhs) const; 
		bool	operator!=(Fixed const & rhs) const;

		Fixed	operator+(Fixed const & rhs) const;
		Fixed	operator-(Fixed const & rhs) const;
		Fixed	operator*(Fixed const & rhs) const;
		Fixed	operator/(Fixed const & rhs) const;

		Fixed	operator++( void );
		Fixed	operator++( int );
		Fixed	operator--( void );
		Fixed	operator--( int );

		static Fixed &			min(Fixed &nb1, Fixed &nb2);
		static Fixed const &	min(Fixed const &nb1, Fixed const &nb2);
		static Fixed &			max(Fixed &nb1, Fixed &nb2);
		static Fixed const &	max(Fixed const &nb1, Fixed const &nb2);

};

std::ostream &	operator<<( std::ostream & o, Fixed const & src );

#endif
