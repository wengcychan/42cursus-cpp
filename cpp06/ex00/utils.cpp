#include "utils.hpp"

bool isChar(std::string str)
{
	return str.length() == 1 && std::isprint(str[0]);
}

bool isPseudoFloat(std::string str)
{
	return str == "-inff" || str == "+inff" || str == "nanf";
}

bool isPseudoDouble(std::string str)
{
	return str == "-inf" || str == "+inf" || str == "nan";
}

t_nbrType checkNumberType(std::string str)
{
	if (isPseudoFloat(str))
		return FLOAT;
	else if (isPseudoDouble(str))
		return DOUBLE;

	t_nbrType nbrType = INT;

	if (!std::isdigit(str[0]) && str[0] != '-' && str[0] != '+')
		return NONE;
		
	for (std::string::iterator it = str.begin() + 1; it != str.end(); ++it)
	{
		if (*it == '.')
		{
			if (nbrType == DOUBLE)
				return NONE;
			else
				nbrType = DOUBLE;
		}
		else if (*it == 'f')
		{
			if (it + 1 == str.end())
				return FLOAT;
			else
				return NONE;
		}
		else if (!std::isdigit(*it))
			return NONE;
	}
	return nbrType;
}

void convertChar(std::string str)
{
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::setprecision (1) << std::fixed  << f << "f" << std::endl;
	std::cout << "double: " << std::setprecision (1) << std::fixed  << d << std::endl;
}

void convertInt(std::string str)
{
	int i = std::atoi(str.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	if (c < 0)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::setprecision (1) << std::fixed  << f << "f" << std::endl;
	std::cout << "double: " << std::setprecision (1) << std::fixed  << d << std::endl;
}

void convertFloat(std::string str)
{
	float f = std::atof(str.c_str());
	double d = static_cast<double>(f);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);

	if (isPseudoFloat(str) || c < 0)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (isPseudoFloat(str))
		std::cout << "int: impossible" << std::endl;
	else if (f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min())
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: overflow" << std::endl;

	std::cout << "float: " << std::setprecision (1) << std::fixed  << f << "f" << std::endl;
	std::cout << "double: " << std::setprecision (1) << std::fixed  << d << std::endl;
}

int convertDouble(std::string str)
{
	char *endptr;
	double d = std::strtod(str.c_str(), &endptr);

	if (*endptr != '\0')
	{
		std::cout << "Invalid input" << std::endl;
		return 1;
	}

	float f = static_cast<float>(d);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);

	if (isPseudoDouble(str) || c < 0)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (isPseudoDouble(str))
		std::cout << "int: impossible" << std::endl;
	else if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min())
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: overflow" << std::endl;
	
	if ((d <= std::numeric_limits<float>::max() && d >= std::numeric_limits<float>::lowest()) 
		|| isPseudoDouble(str))
		std::cout << "float: " << std::setprecision (1) << std::fixed  << f << "f" << std::endl;
	else
		std::cout << "float: overflow" << std::endl;

	std::cout << "double: " << std::setprecision (1) << std::fixed  << d << std::endl;

	return 0;
}
