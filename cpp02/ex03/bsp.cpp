#include "Point.hpp"

static Fixed	triangleArea( Point const pt1, Point const pt2, Point const pt3 ) {
	
	Fixed area = pt1.getX() * (pt2.getY() - pt3.getY()) + pt2.getX() * 
				(pt3.getY() - pt1.getY()) + pt3.getX() * (pt1.getY() - pt2.getY());
	if (area < 0)
		area.setRawBits(std::abs(area.getRawBits()));
	return area;

}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	
	Fixed totalArea = triangleArea(a , b , c);
	if (totalArea == 0)
		return false;

	Fixed Area1 = triangleArea(a , b , point);
	Fixed Area2 = triangleArea(a , c , point);
	Fixed Area3 = triangleArea(b , c , point);

	if (Area1 == 0 || Area2 == 0 || Area3 == 0) 
		return false;
	if (Area1 + Area2 + Area3 != totalArea)
		return false;
	return true;

}
