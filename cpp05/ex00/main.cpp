#include "Bureaucrat.hpp"

int main ( void )
{
	{
		std::cout << "-----------Basic functionality-----------" << std::endl;

		Bureaucrat officer("officer", 50);
		std::cout << officer;
		officer.increaseGrade();
		officer.increaseGrade();
		std::cout << officer;
		officer.decreaseGrade();
		std::cout << officer;
	}

	{
		std::cout << std::endl << "-----------Create grade too high object-----------" << std::endl;
		try
		{
			Bureaucrat officer("officer", 0);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "-----------Create grade too low object-----------" << std::endl;
		try
		{
			Bureaucrat officer("officer", 151);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "-----------Increase grade out of range-----------" << std::endl;
		Bureaucrat officer( "officer", 1);
		std::cout << officer;
		try
		{
			officer.increaseGrade();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << officer;
	}

	{
		std::cout << std::endl << "-----------Decrease grade out of range-----------" << std::endl;
		Bureaucrat officer("officer", 150);
		std::cout << officer;
		try
		{
			officer.decreaseGrade();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << officer;
	}

	return 0;
}