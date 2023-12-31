#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

#include "utils.hpp"

class ScalarConverter {

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator=(ScalarConverter const &rhs);
		~ScalarConverter();

	public:
		static int convert(std::string str);

};

#endif