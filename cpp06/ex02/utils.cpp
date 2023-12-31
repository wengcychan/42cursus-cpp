#include "utils.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <exception>

Base *generate(void)
{
	srand(time(NULL));
	int randomNbr = rand() % 3;

	if (randomNbr == 0)
		return new A();
	else if (randomNbr == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer::The real type is A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointer::The real type is B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointer::The real type is C" << std::endl;
}

void identify(Base& p)
{	
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Ref::The real type is A" << std::endl;
	}
	catch (const std::exception& e)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Ref::The real type is B" << std::endl;
	}
	catch (const std::exception& e)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Ref::The real type is C" << std::endl;
	}
	catch (const std::exception& e)
	{
	}
}