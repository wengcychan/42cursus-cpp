#include "ScalarCoverter.hpp"
#include <iomanip>
#include <limits.h>

int ScalarConverter::convert(std::string str)
{
	if (isChar(str))
		convertChar(str);
	else
	{
		switch (checkNumberType(str)) 
		{
			case INT:
				convertInt(str);
				break;
			case FLOAT:
				convertFloat(str);
				break;
			case DOUBLE:
				if (convertDouble(str))
					return 1;
				break;
			default:
				std::cout << "Invalid input" << std::endl;
				return 1;
		}
	}

	return 0;
}