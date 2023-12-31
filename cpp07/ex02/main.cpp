#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Array.hpp"

int main(int, char**)
{
	{
		int size = 3;

		std::cout << "--------- array int ---------" << std::endl;
		Array<int> numbers(size);
		Array<int> tmp = numbers;
		Array<int> test(tmp);

		for (int i = 0; i < size; ++i)
			numbers[i] = i;

		for (int i = 0; i < size; ++i)
			std::cout << numbers[i] << std::endl;

		try
		{
			numbers[-1];
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			numbers[size];
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		int size = 3;

		std::cout << "--------- array float ---------" << std::endl;
		Array<float> numbers(size);
		Array<float> tmp = numbers;
		Array<float> test(tmp);

		for (int i = 0; i < size; ++i)
			numbers[i] = static_cast<float>(i);

		for (int i = 0; i < size; ++i)
			std::cout << std::setprecision(1) << std::fixed << numbers[i] << std::endl;

		try
		{
			numbers[-1];
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			numbers[size];
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		int size = 3;

		std::cout << "--------- array string ---------" << std::endl;
		Array<std::string> str(size);
		Array<std::string> tmp = str;
		Array<std::string> test(tmp);

		for (int i = 0; i < size; ++i)
		{
			std::stringstream number;
			number << i;
			str[i] = "str" + number.str();


		}
		for (int i = 0; i < size; ++i)
			std::cout << str[i] << std::endl;

		try
		{
			str[-1];
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			str[size];
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

    return 0;
}