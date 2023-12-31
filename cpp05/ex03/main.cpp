#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main ( void )
{
	{
		std::cout << "-----------Basic functionality: ShrubberyCreationForm-----------" << std::endl;

		Intern  someRandomIntern;
		AForm*   rrf;
		rrf = someRandomIntern.makeForm("Shrubbery Creation Form", "home");

		Bureaucrat officer("officer", 144);
		officer.signForm(*rrf);
		Bureaucrat officer1("officer1", 20);
		officer1.executeForm(*rrf);

		delete rrf;
	}

	{
		std::cout << std::endl << "-----------Basic functionality: RobotomyRequestForm-----------" << std::endl;

		Intern  someRandomIntern;
		AForm*   rrf;
		rrf = someRandomIntern.makeForm("Robotomy Request Form", "Bender");

		Bureaucrat officer("officer", 70);
		officer.signForm(*rrf);
		Bureaucrat officer1("officer1", 40);
		officer1.executeForm(*rrf);

		delete rrf;
	}

	{
		std::cout << std::endl << "-----------Basic functionality: PresidentialPardonForm-----------" << std::endl;

		Intern  someRandomIntern;
		AForm*   rrf;
		rrf = someRandomIntern.makeForm("Presidential Pardon Form", "General Director");

		Bureaucrat officer("officer", 10);
		officer.signForm(*rrf);
		Bureaucrat officer1("officer1", 4);
		officer1.executeForm(*rrf);

		delete rrf;
	}

	{
		std::cout << std::endl << "-----------Form name doesn't exist-----------" << std::endl;

		Intern  someRandomIntern;
		AForm*   rrf;
		rrf = someRandomIntern.makeForm("Invalid Form", "General Director");

		delete rrf;
	}

	return 0;
}