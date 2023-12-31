#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>

typedef enum nbrType
{
	INT,
	FLOAT,
	DOUBLE,
	NONE
}			t_nbrType;

bool		isChar(std::string str);
bool		isPseudoFloat(std::string str);
bool		isPseudoDouble(std::string str);
t_nbrType	numberType(std::string str);

void	convertInt(std::string str);
void	convertFloat(std::string str);
int		convertDouble(std::string str);
void	convertChar(std::string str);

#endif