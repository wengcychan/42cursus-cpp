#include <iostream>
#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of argument" << std::endl;
		return 1;
	}

	try 
	{
		RPN rpn(argv[1]);
		std::cout << rpn.calculate() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}