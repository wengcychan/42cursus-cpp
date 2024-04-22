#include <iostream>
#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	try {
		PmergeMe pmergeme(argc, argv);
		pmergeme.sort();
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}