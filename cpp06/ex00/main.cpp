#include <iostream>
#include "ScalarCoverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of argument" << std::endl;
		return 1;
	}

	return ScalarConverter::convert(argv[1]);
}