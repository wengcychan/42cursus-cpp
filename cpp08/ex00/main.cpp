#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int main (void)
{
	{
		std::cout << "---------- vector ----------" << std::endl;

		int target;
		int array[] = {2, 4, 4, 8, 9};
		std::vector<int> v(array, array + sizeof(array) / sizeof(int));


		std::cout << "***** case found *****" << std::endl;
		target = 4;
	
		std::cout << "container: ";
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl << "target: " << target << std::endl;
	
		if (easyfind(v, target))
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Found" << std::endl;


		std::cout << "***** case not found *****" << std::endl;
		target = 11;

		std::cout << "container: ";
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl << "target: " << target << std::endl;

		if (easyfind(v, target))
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Found" << std::endl;
	}

	{
		std::cout << std::endl << "---------- list ----------" << std::endl;

		int target;
		int array[] = {10, 6, 3, 8, 11, 13};
		std::list<int> li(array, array + sizeof(array) / sizeof(int));


		std::cout << "***** case found *****" << std::endl;
		target = 13;

		std::cout << "container: ";
		for (std::list<int>::iterator it = li.begin(); it != li.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl << "target: " << target << std::endl;

		if (easyfind(li, target))
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Found" << std::endl;


		std::cout << "***** case not found *****" << std::endl;
		target = -1;

		std::cout << "container: ";
		for (std::list<int>::iterator it = li.begin(); it != li.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl << "target: " << target << std::endl;
		if (easyfind(li, target))
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Found" << std::endl;
	}

	return 0;
}