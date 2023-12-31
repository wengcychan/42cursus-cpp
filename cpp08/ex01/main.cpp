#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Span.hpp"

int main (void)
{

	srand(time(NULL));

	{
		std::cout << "--------- 5 numbers ---------" << std::endl;

		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::vector<int> v = sp.getSpan();
		std::cout << "vector: ";
		for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << "--------- 10 numbers ---------" << std::endl;

		Span span(10);

		span.addNumber(1);
		span.addNumber(2);
		span.addNumber(5);
		span.addNumber(14);
		span.addNumber(19);
		span.addNumber(4);
		span.addNumber(10);
		span.addNumber(89);
		span.addNumber(78);
		span.addNumber(65);

		std::vector<int> v = span.getSpan();
		std::cout << "vector: ";
		for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "longest span: " << span.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << "--------- 10000 numbers ---------" << std::endl;

		Span span(10000);

		int number;

		for (int i = 0; i < 10000; i++)
		{
			number = rand() % 1000000000;
			span.addNumber(number);
		}

		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "longest span: " << span.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << "--------- Exception for maximum number of intergers ---------" << std::endl;

		Span span(2);

		try
		{
			span.addNumber(1);
			span.addNumber(2);
			span.addNumber(5);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "--------- Exception for no span ---------" << std::endl;

		Span span(1);

		span.addNumber(1);

		try
		{
			span.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "--------- Add Many Numbers ---------" << std::endl;

		Span span(9);

		int size = 4;
		int array[] = {1, 3, 9, 11};
		span.addManyNumbers(array, size);

		std::vector<int> v = span.getSpan();
		std::cout << "vector: ";
		for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		size = 5;
		int array1[] = {15, 20, 30, 41, 50};
		span.addManyNumbers(array1, size);


		v = span.getSpan();
		std::cout << "vector: ";
		for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "longest span: " << span.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << "--------- Exception for maximum number of intergers ---------" << std::endl;


		try
		{
			Span span(8);

			int size = 4;
			int array[] = {1, 2, 3, 4};
			span.addManyNumbers(array, size);

			std::vector<int> v = span.getSpan();
			std::cout << "vector: ";
			for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;

			size = 5;
			int array1[] = {5, 6, 7, 8, 9};
			
			span.addManyNumbers(array1, size);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}