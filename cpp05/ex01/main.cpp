#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ( void )
{
	{
		std::cout << "-----------Basic functionality-----------" << std::endl;

		Bureaucrat officer("officer", 2);
		std::cout << officer;
		Form form("a very long form", 50, 20);
		std::cout << form;
		officer.signForm(form);
		std::cout << form;
		Bureaucrat officer1("officer1", 5);
		officer1.signForm(form);
		std::cout << form;
	}

	{
		std::cout << std::endl << "-----------Create grade too high Form-----------" << std::endl;
		try
		{
			Form form("a very long form", 0, 50);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "-----------Create grade too low Form-----------" << std::endl;
		try
		{
			Form form("a very long form", 151, 50);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "-----------Sign grade too low-----------" << std::endl;

		Bureaucrat officer("officer", 51);
		std::cout << officer;
		Form form("a very long form", 50, 20);
		std::cout << form;
		officer.signForm(form);
		std::cout << form;
	}

	return 0;
}