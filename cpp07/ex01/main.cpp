#include <iostream>
#include "iter.hpp"

int main( void ) {

	int length;

	{
		std::cout << "--------- print int ---------" << std::endl;
		length = 4;
		int i[] = {1, 2, 3, 4};
		iter<int>(i, length, &print);
	}

	{
		std::cout << std::endl << "--------- print float ---------" << std::endl;
		length = 5;
		float f[] = {1.2, 2.5, 3.1, 4.6, 5.7};
		iter<float>(f, length, &print);
	}

	{
		std::cout << std::endl << "--------- print string ---------" << std::endl;
		length = 4;
		std::string str[] = {"str1", "str2", "str3", "str4"};
		iter<std::string>(str, length, &print);
	}

	return 0;
}


