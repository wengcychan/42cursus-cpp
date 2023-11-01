#include <iostream>
#include "Fixed.hpp"

int	main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;


	// Fixed a(3);
	// Fixed b(2);

	// std::cout << std::endl;
	// std::cout << "a : " << a << std::endl;
	// std::cout << "b : " << b << std::endl;
	// std::cout << std::endl;

	// std::cout << "a > b : " << (a > b) << std::endl;
	// std::cout << "a < b : " << (a < b) << std::endl;
	// std::cout << "a >= b : " << (a >= b) << std::endl;
	// std::cout << "a <= b : " << (a <= b) << std::endl;
	// std::cout << "a == b : " << (a == b) << std::endl;
	// std::cout << "a != b : " << (a != b) << std::endl;
	// std::cout << std::endl;

	// std::cout << "a + b : " << (a + b) << std::endl;
	// std::cout << "a - b : " << (a - b) << std::endl;
	// std::cout << "a * b : " << (a * b) << std::endl;
	// std::cout << "a / b : " << (a / b) << std::endl;
	// std::cout << std::endl;

	// std::cout << "a : " << a << std::endl;
	// std::cout << "++a : " << ++a << std::endl;
	// std::cout << "a : " << a << std::endl;
	// std::cout << "a++ : " << a++ << std::endl;
	// std::cout << "a : " << a << std::endl;
	// std::cout << std::endl;

	// std::cout << "a : " << a << std::endl;
	// std::cout << "--a : " << --a << std::endl;
	// std::cout << "a : " << a << std::endl;
	// std::cout << "a-- : " << a-- << std::endl;
	// std::cout << "a : " << a << std::endl;
	// std::cout << std::endl;

	// Fixed c(1);
	// Fixed d(2);
	// Fixed const e(3);
	// Fixed const f(4);

	// std::cout << std::endl;
	// std::cout << "c : " << c << std::endl;
	// std::cout << "d : " << d << std::endl;
	// std::cout << "e : " << e << std::endl;
	// std::cout << "f : " << f << std::endl;
	// std::cout << std::endl;

	// std::cout << "min( c , d ) : " << Fixed::min( c, d ) << std::endl;
	// std::cout << "max( c , d ) : " << Fixed::max( c, d ) << std::endl;
	// std::cout << "min( e , f ) : " << Fixed::min( e, f ) << std::endl;
	// std::cout << "max( e , f ) : " << Fixed::max( e, f ) << std::endl;
	// std::cout << std::endl;

	return 0;
}
