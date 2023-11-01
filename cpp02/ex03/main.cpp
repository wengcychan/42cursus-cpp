#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int	main( void ) {

	{
		//the point is inside the triangle
		Point const a(0, 0);
		Point const b(10, 30);
		Point const c(20, 0);
		Point const point(10, 15);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	{
		//the point is outside the triangle
		Point const a(0, 0);
		Point const b(10, 30);
		Point const c(20, 0);
		Point const point(30, 15);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	{
		//the point is on the triangle
		Point const a(0, 0);
		Point const b(10, 30);
		Point const c(20, 0);
		Point const point(5, 15);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	{
		//the triangle is a point
		Point const a(0, 0);
		Point const b(0, 0);
		Point const c(0, 0);
		Point const point(0, 0);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	{
		//the point is on the vertice
		Point const a(-2, 3);
		Point const b(-4, -2);
		Point const c(2, 1);
		Point const point(2, 1);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	{
		//the point is outside the triangle
		Point const a(-2, 3);
		Point const b(-4, -2);
		Point const c(2, 1);
		Point const point(3, 3);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	{
		//the point is inside the triangle
		Point const a(-2, 3);
		Point const b(-4, -2);
		Point const c(2, 1);
		Point const point(0, 1);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}

	return 0;
}
