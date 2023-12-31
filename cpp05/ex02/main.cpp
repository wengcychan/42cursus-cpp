#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main ( void )
{
	{
		std::cout << "-----------Basic functionality: ShrubberyCreationForm-----------" << std::endl;

		Bureaucrat officer("officer", 144);
		AForm *shrubbery = new ShrubberyCreationForm("home");
		std::cout << *shrubbery;
		officer.signForm(*shrubbery);
		Bureaucrat officer1("officer1", 20);
		officer1.executeForm(*shrubbery);

		delete shrubbery;
	}

	{
		std::cout << std::endl << "-----------Basic functionality : RobotomyRequestForm-----------" << std::endl;

		Bureaucrat officer("officer", 70);
		AForm *robotomy = new RobotomyRequestForm("Bender");
		std::cout << *robotomy;
		officer.signForm(*robotomy);
		Bureaucrat officer1("officer1", 40);
		officer1.executeForm(*robotomy);

		delete robotomy;
	}

	{
		std::cout << std::endl << "-----------Basic functionality : PresidentialPardonForm-----------" << std::endl;

		Bureaucrat officer("officer", 10);
		AForm *president = new PresidentialPardonForm("General Director");
		std::cout << *president;
		officer.signForm(*president);
		Bureaucrat officer1("officer1", 4);
		officer1.executeForm(*president);

		delete president;
	}

	{
		std::cout << std::endl << "-----------Form not signed-----------" << std::endl;

		Bureaucrat officer("officer", 144);
		AForm *shrubbery = new ShrubberyCreationForm("home");
		std::cout << *shrubbery;
		Bureaucrat officer1("officer1", 20);
		officer1.executeForm(*shrubbery);

		delete shrubbery;
	}

	{
		std::cout << std::endl << "-----------Sign grade too low-----------" << std::endl;

		Bureaucrat officer("officer", 150);
		AForm *shrubbery = new ShrubberyCreationForm("home");
		std::cout << *shrubbery;
		officer.signForm(*shrubbery);
		Bureaucrat officer1("officer1", 20);
		officer1.executeForm(*shrubbery);

		delete shrubbery;
	}

	{
		std::cout << std::endl << "-----------Execute grade too low-----------" << std::endl;

		Bureaucrat officer("officer", 144);
		AForm *shrubbery = new ShrubberyCreationForm("home");
		std::cout << *shrubbery;
		officer.signForm(*shrubbery);
		Bureaucrat officer1("officer1", 140);
		officer1.executeForm(*shrubbery);

		delete shrubbery;
	}

	std::cout << std::endl;

	return 0;
}